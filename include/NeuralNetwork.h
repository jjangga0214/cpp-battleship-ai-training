//
// Created by user on 18. 6. 5.
//

#pragma once

#include <vector>
#include "Eigen/Dense"

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

public:
// protected: //향후 protected 로 한다.
    Eigen::VectorXd inputLayer;
    std::vector<Eigen::MatrixXd> hiddenLayers;
    Eigen::VectorXd outputLayer;

};
