//
// Created by user on 18. 6. 5.
//
#include <iostream>
#include "NeuralNetwork.h"
#include "Eigen/Dense"
#include <vector>
#include <cmath>

bts::ai::NeuralNetwork::NeuralNetwork(int inputLayerSize, int hiddenLayersSize, int howManyHiddenLayers,
                                      int outputLayerSize) : inputLayerSize(inputLayerSize),
                                                             hiddenLayersSize(hiddenLayersSize),
                                                             howManyHiddenLayers(howManyHiddenLayers),
                                                             outputLayerSize(outputLayerSize) {

    Eigen::MatrixXd w = Eigen::MatrixXd::Random(hiddenLayersSize, inputLayerSize);
    hiddenLayers.push_back(w);
    for (int i = 0; i < howManyHiddenLayers - 2; ++i) {
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
//        std::cout << result << std::endl;
//        std::cout << "==================================================================="<<'\n';
//        std::cout << "==================================================================="<<'\n';
        result = w * result;
        result = result.unaryExpr(&bts::ai::NeuralNetwork::sigmoid);
        outputsOnLayers.push_back(result);
    }
    return result;
}

double bts::ai::NeuralNetwork::adjust(double x) {
    return sigmoid(x);
}

void bts::ai::NeuralNetwork::backPropagate(const Eigen::VectorXd guessed, Eigen::VectorXd supervising,
                                           double learning_rate) {

    for (int m = 0; m < supervising.size(); ++m) {
        if (supervising(m) <= 0) {
            supervising(m) = 0.1;
        } else if (supervising(m) >= 1) {
            supervising(m) = 0.99;
        }
    }
//    std::cout << "==================================================================" << '\n';
//    for (int l = 0; l < guessed.size(); ++l) {
//        std::cout << supervising(l) - guessed(l) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << "==================================================================" << '\n';

    Eigen::VectorXd initialError(guessed.size());
    Eigen::VectorXd error(this->outputLayerSize);
    Eigen::VectorXd deeper_error(this->outputLayerSize);
    bool flag = true;
    int i = 1;
    int k = 0;
    int ooSize = this->outputsOnLayers.size();
    int hlSize = this->howManyHiddenLayers;
    initialError = supervising - guessed;
    double sum_ = 0;
    for (int l = 0; l < initialError.size(); ++l) {
        std::cout << initialError(l) << " ";
        sum_ += std::abs(initialError(l));
    }
    std::cout << '\n';
    std::cout << "sum of initialError: " << sum_ << '\n';
    //std::cout << "==================================================================" << '\n';

    error = this->hiddenLayers[this->hiddenLayers.size() - 1].transpose() * initialError;

    Eigen::VectorXd n_(initialError.size());
    for (int j = 0; j < initialError.size(); ++j) {
        n_(j) = initialError(j) * guessed(j) * (1.0 - guessed(j));
    }
    //std::cout << "==================================================================" << '\n';
    Eigen::MatrixXd cm_(initialError.size(), 1);
    Eigen::MatrixXd rm_(1, error.size());

    cm_.col(0) = n_;
    rm_.row(0) = this->outputsOnLayers[ooSize - i - 1];
    this->hiddenLayers[hlSize - i] = this->hiddenLayers[hlSize - i] + learning_rate * (cm_ * rm_);

    for (int row = 0; row < hiddenLayers[hlSize - i].rows(); ++row) {
        for (int col = 0; col < hiddenLayers[hlSize - i].cols(); ++col) {
            if (hiddenLayers[hlSize - i](row, col) == 0) {
                hiddenLayers[hlSize - i](row, col) = 0.000001;
            }
        }
    }
    ++i;
    ///std::cout << "==================================================================" << '\n';
    for (auto it = std::rbegin(this->hiddenLayers) + 1, end = std::rend(this->hiddenLayers); it != end - 1; ++it, ++i) {

        deeper_error = (*it).transpose() * error;

        //std::cout << "================================================================== 4" << '\n';
        Eigen::VectorXd n(error.size());
        for (int j = 0; j < error.size(); ++j) {
            n(j) = error(j) * this->outputsOnLayers[ooSize - i](j) * (1 - this->outputsOnLayers[ooSize - i](j));
        }
        Eigen::MatrixXd cm(error.size(), 1);
        Eigen::MatrixXd rm(1, deeper_error.size());
        //std::cout << "================================================================== 5" << '\n';
        cm.col(0) = n;
        rm.row(0) = this->outputsOnLayers[ooSize - i - 1];

        this->hiddenLayers[hlSize - i] = *it + learning_rate * (cm * rm);

        for (int row = 0; row < hiddenLayers[hlSize - i].rows(); ++row) {
            for (int col = 0; col < hiddenLayers[hlSize - i].cols(); ++col) {
                if (hiddenLayers[hlSize - i](row, col) == 0) {
                    hiddenLayers[hlSize - i](row, col) = 0.00001;
                }
            }
        }

        error = deeper_error;
    }
}

Eigen::VectorXd
bts::ai::NeuralNetwork::learn(const Eigen::VectorXd &input, const Eigen::VectorXd &supervising, double learning_rate) {
//    std::cout << "============================================================" << '\n';
//    for (int i = 0; i < this->howManyHiddenLayers; ++i) {
//        for (int row = 0; row < this->hiddenLayers[i].rows(); ++row) {
//            for (int col = 0; col < this->hiddenLayers[i].cols(); ++col) {
//                std::cout << this->hiddenLayers[i](row, col) << " ";
//            }
//        }
//        std::cout << std::endl;
//    }
//    std::cout << "============================================================" << '\n';
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