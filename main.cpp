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

//    bts::ai::NeuralNetwork nn(4, 4, 2, 4);
//    for (auto w: nn.hiddenLayers) {
//        std::cout << w << std::endl << std::endl;
//    }
//
//    Eigen::MatrixXd m(1, 2);
//    Eigen::MatrixXd m2(2, 1);
//    Eigen::VectorXd v1(2);
//    v1 << 1, 2;
//
//    Eigen::VectorXd v2(2);
//    v2 << 3, 4;
//
//    m.row(0) = v1;
//    m2.col(0) = v2;
    //m2 << v2; //[3,4]
    /* m = m.unaryExpr(&bts::ai::NeuralNetwork::sigmoid);
     std::cout << m<< std::endl << std::endl;*/

//    Eigen::VectorXd v1(2);
//    v1 << 1, 2;
//    Eigen::VectorXd v2(2);
//    v1 << 2, 3;
//    std::cout << m << std::endl << std::endl;
//    std::cout << m2 << std::endl << std::endl;
//    std::cout << m2 * m;
//
//    std::vector<Eigen::MatrixXd> v;
//    Eigen::MatrixXd m(2, 2);
//    m << 1, 2, 3, 4;
//    Eigen::MatrixXd m2(2, 2);
//    m << 1, 2, 3, 4;
//    v.push_back(m);
//    *std::begin(v) += m2;
//    std::cout << v[0] << std::endl;


//    Eigen::VectorXd v(4);
//    std::cout << v<< std::endl;
//    nn.expect(v);
////
////    std::cout << Eigen::VectorXd::Zero(8) << std::endl << std::endl;
////
////    std::cout << nn.expect(Eigen::VectorXd(8)) << std::endl << std::endl;
    return 0;
}