#include <iostream>
#include "Eigen/Dense"
#include "NeuralNetwork.h"

int main() {
//    Eigen::MatrixXd m(8, 8);
//    m(1, 2) = 3.44444444444555599;
//
    std::cout << "Hello, World!" << std::endl;
//    std::cout << m << std::endl;
//    std::cout << m(1, 2) << std::endl;

    bts::ai::NeuralNetwork nn(8, 8, 2, 8);
    for (auto w: nn.hiddenLayers) {
        std::cout << w << std::endl << std::endl;
    }

    std::cout << nn.inputLayer << std::endl<< std::endl;
    std::cout << nn.outputLayer << std::endl<< std::endl;

    auto a = nn.hiddenLayers[0] * nn.outputLayer;
    std::cout << a;

    return 0;
}