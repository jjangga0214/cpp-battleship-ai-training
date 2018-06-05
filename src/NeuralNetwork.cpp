//
// Created by user on 18. 6. 5.
//

#include "NeuralNetwork.h"

bts::ai::NeuralNetwork::NeuralNetwork(int inputLayerSize, int hiddenLayersSize, int howManyHiddenLayers, int outputLayerSize)
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