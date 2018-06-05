#include <iostream>
#include "Board.h"
#include "Eigen/Dense"
#include "NeuralNetwork.h"
#include "Writefile.h"
#include <unistd.h>

using namespace std;


int main() {

    Board board[100];

//    bts::ai::NeuralNetwork neuralNetwork(8,50,5,8);
//    neuralNetwork.learn(board[0].change_Vector(),board[0].calc_Maxtirx());
//


    for (int i = 0; i <100 ; ++i) {
        Write(board[i].getMatirx("origin"));
    }


//    board[0].display_origin();
//    Write(board[0].getMatirx("origin"));
//
//    Eigen::MatrixXd a = Read();
//    cout << endl;
//    cout << a << endl;
//







//    Eigen::VectorXd v(4);
//    std::cout << v<< std::endl;
//    nn.expect(v);
////
////    std::cout << Eigen::VectorXd::Zero(8) << std::endl << std::endl;
////
////    std::cout << nn.expect(Eigen::VectorXd(8)) << std::endl << std::endl;
    return 0;
}