//
// Created by user on 18. 6. 5.
//

#pragma once

#include <cmath>
#include <vector>
#include "Eigen/Dense"
#include "Writefile.h"
#include <list>

namespace bts {
    namespace ai {
        class NeuralNetwork;
    }
}

class bts::ai::NeuralNetwork {
public:
    /**
     * @param howManyHiddenLayers : hidden layer 갯수
     */
    NeuralNetwork(int inputLayerSize, int hiddenLayersSize, int howManyHiddenLayers, int outputLayerSize);

    virtual Eigen::VectorXd expect(const Eigen::VectorXd &input);

    virtual void backPropagate(const Eigen::VectorXd guessed, const Eigen::VectorXd supervising, double learning_rate =0.5);

    virtual Eigen::VectorXd learn(const Eigen::VectorXd &input, const Eigen::VectorXd &supervising, double learning_rate = 0.5);

    virtual double adjust(double x);

    inline static double sigmoid(double x) {
        return 1.0 / (1.0 + std::exp(x));
    }

    inline static double sigmoidDerivative(double x) {
        return NeuralNetwork::sigmoid(x) * (1 - NeuralNetwork::sigmoid(x));
    }
    virtual void saveModel();

    virtual void stepClear();

public:
    const int inputLayerSize;
    const int hiddenLayersSize;
    const int howManyHiddenLayers;
    const int outputLayerSize;
public:
// protected: //향후 protected 로 한다.
    std::vector<Eigen::MatrixXd> hiddenLayers;
    std::vector<Eigen::VectorXd> outputsOnLayers;

};
