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
    for (const auto &w : this->hiddenLayers) {
        std::cout << result << std::endl;
        result = w * result;
        result = result.unaryExpr(&bts::ai::NeuralNetwork::sigmoid);
    }
    return result;
}

double bts::ai::NeuralNetwork::adjust(double x) {
    return sigmoid(x);
}

void bts::ai::NeuralNetwork::backPropagate(const Eigen::VectorXd &guessed, const Eigen::VectorXd &supervising) {

}

void bts::ai::NeuralNetwork::learn(const Eigen::VectorXd &input, const Eigen::VectorXd &supervising) {
    Eigen::VectorXd guessed = this->expect(input);
    this->backPropagate(guessed, supervising);
}