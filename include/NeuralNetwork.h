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
    NeuralNetwork(int inputLayerSize, int hiddenLayersSize, int howManyHiddenLayers, int outputLayerSize)
    :inputLayer(inputLayerSize),outputLayer(outputLayerSize){

        Eigen::MatrixXd w(hiddenLayersSize, inputLayerSize);
        hiddenLayers.push_back(w);
        for (int i = 0; i < howManyHiddenLayers - 1; ++i) {
            w = Eigen::MatrixXd(hiddenLayersSize, hiddenLayersSize);
            hiddenLayers.push_back(w);
        }
        w = Eigen::MatrixXd(outputLayerSize, hiddenLayersSize);
        hiddenLayers.push_back(w);
    }

public:
// protected: //향후 protected 로 한다.
    Eigen::VectorXd inputLayer;
    std::vector<Eigen::MatrixXd> hiddenLayers;
    Eigen::VectorXd outputLayer;

};
