//
// Created by user on 18. 6. 5.
//
#include <iostream>
#include "NeuralNetwork.h"
#include "Eigen/Dense"
#include <vector>

bts::ai::NeuralNetwork::NeuralNetwork(int inputLayerSize, int hiddenLayersSize, int howManyHiddenLayers,
                                      int outputLayerSize) : inputLayerSize(inputLayerSize),
                                                             hiddenLayersSize(hiddenLayersSize),
                                                             howManyHiddenLayers(howManyHiddenLayers),
                                                             outputLayerSize(outputLayerSize) {

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
    Eigen::VectorXd deepper_error;
    bool flag = true;
    int i = 1;
    int k = 0;
    int ooSize = this->outputsOnLayers.size();
    int hlSize = this->hiddenLayers.size();
    error = supervising - guessed;
    for (auto it = std::rbegin(this->hiddenLayers), end = std::rend(this->hiddenLayers); it != end; ++it, ++i) {

        deepper_error = (*it).transpose() * error;

        Eigen::VectorXd n(error.size());
        for (int j = 0; j < error.size(); ++j) {
            n(j) = error(j) * guessed(j) * (1 - guessed(j));
        }
        Eigen::MatrixXd cm(error.size(), 1);
        Eigen::MatrixXd rm(1, deepper_error.size());

        cm.col(0) = n;
        rm.row(0) = this->outputsOnLayers[ooSize - i - 1];

        this->hiddenLayers[hlSize - i] = *it + learning_rate * (cm * rm);
        error = deepper_error;
    }
}

Eigen::VectorXd
bts::ai::NeuralNetwork::learn(const Eigen::VectorXd &input, const Eigen::VectorXd &supervising, double learning_rate) {
    Eigen::VectorXd guessed = this->expect(input);
    //std::cout<<guessed<<std::endl;
    //Eigen::VectorXd guessed(64);
    this->backPropagate(guessed, supervising);
    return guessed;
}

void bts::ai::NeuralNetwork::saveModel() {
    for (auto m: hiddenLayers) {
        Write(m);
    }
}

void bts::ai::NeuralNetwork::stepClear() {
    outputsOnLayers.clear();
    outputsOnLayers.resize(0);
}