//
// Created by user on 18. 6. 5.
//
#include <iostream>
#include "NeuralNetwork.h"
#include "Eigen/Dense"

bts::ai::NeuralNetwork::NeuralNetwork(int inputLayerSize, int hiddenLayersSize, int howManyHiddenLayers,
                                      int outputLayerSize) {

    Eigen::MatrixXd w = Eigen::MatrixXd::Random(hiddenLayersSize, inputLayerSize);
    hiddenLayers.push_back(w);
    for (int i = 0; i < howManyHiddenLayers - 1; ++i) {
        w = Eigen::MatrixXd::Random(hiddenLayersSize, hiddenLayersSize);
        hiddenLayers.push_back(w);
    }
    w = Eigen::MatrixXd::Random(outputLayerSize, hiddenLayersSize);
    hiddenLayers.push_back(w);
}

Eigen::VectorXd bts::ai::NeuralNetwork::expect(const Eigen::VectorXd &input) {
    Eigen::VectorXd result = input; //복자 연산자
    outputsOnLayers.push_back(input);
    for (const auto &w : this->hiddenLayers) {
        std::cout << result << std::endl;
        result = w * result;
        result = result.unaryExpr(&bts::ai::NeuralNetwork::sigmoid);
        outputsOnLayers.push_back(result);
    }
    return result;
}

double bts::ai::NeuralNetwork::adjust(double x) {
    return sigmoid(x);
}

void bts::ai::NeuralNetwork::backPropagate(const Eigen::VectorXd guessed, const Eigen::VectorXd supervising,
                                           double learning_rate) {
    Eigen::VectorXd error;
    Eigen::VectorXd deep_error;
    bool flag = true;
    int i = 1;

    int rwsize = this->outputsOnLayers.size();
    int hwsize = this->hiddenLayers.size();
    for (auto it = std::rbegin(this->hiddenLayers), end = std::rend(this->hiddenLayers); it != end; ++it) {
        if (flag) {
            error = supervising - this->outputsOnLayers[rwsize - i]; //오차는 실제값 - 계산값
            flag = false;
        } else {
            //error =

        }

        deep_error = (*it).transpose() * error;


        Eigen::VectorXd n;
        for (int i = 0; i < error.size(); ++i) {
            n(i) = error(i) * guessed(i) * (1 - guessed(i));
        }
        Eigen::MatrixXd m1;
        Eigen::MatrixXd m2;
        m1.col(0) = n;
        m2.row(0) = this->outputsOnLayers[rwsize - i];
        this->hiddenLayers[hwsize - i] = *it + learning_rate * m1 * m2;
        error = deep_error;
        ++i;
    }
}

void bts::ai::NeuralNetwork::learn(const Eigen::VectorXd &input, const Eigen::VectorXd &supervising,
                                   double learning_rate) {
    Eigen::VectorXd guessed = this->expect(input);
    this->backPropagate(guessed, supervising);
}