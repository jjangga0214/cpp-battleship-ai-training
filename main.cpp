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

    bts::ai::NeuralNetwork nn(4, 4, 2, 4);
    for (auto w: nn.hiddenLayers) {
        std::cout << w << std::endl << std::endl;
    }

    Eigen::MatrixXd m(2, 2);
    m << 1, 2, 3, 4;
    m = m.unaryExpr(&bts::ai::NeuralNetwork::sigmoid);
    std::cout << m<< std::endl << std::endl;

//    Eigen::VectorXd v(4);
//    std::cout << v<< std::endl;
//    nn.expect(v);
////
////    std::cout << Eigen::VectorXd::Zero(8) << std::endl << std::endl;
////
////    std::cout << nn.expect(Eigen::VectorXd(8)) << std::endl << std::endl;
    return 0;
}