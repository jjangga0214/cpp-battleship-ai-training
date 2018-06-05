//
// Created by sonhyeongi on 6/5/18.
//
#include <iostream>
#include "Eigen/Dense"
#include "NeuralNetwork.h"
#include "Random.h"
using namespace std;
#ifndef BATTLESHIP_AI_TRAINING_BOARD_H
#define BATTLESHIP_AI_TRAINING_BOARD_H



class Board{
private:
    Eigen::MatrixXd Origin_data_Matrix;
    Eigen::MatrixXd State_data_Matrix;
    int Origin_data[8][8]={{0,}};
public:
    Board()
            :Origin_data_Matrix(8,8), State_data_Matrix(8,8)
    {
        Make mg;
        int size1[5] = {5,4,3,2,2};
        int size_count = 0;

        srand((unsigned int) time(NULL));
        int direction = -1;
        while (1) {
            int left, right;
            left = rand() % 8;
            right = rand() % 8;
            direction = rand() % 4;

            if (size_count > 4) {
                break;
            } else {
                if (mg.Random_select_position(left, right, direction, size1[size_count], Origin_data) == 0) {
                    size_count++;
                }
            }
        }


        for(int i=0; i<8; ++i) {
            for(int j=0; j<8; ++j) {
                Origin_data_Matrix(i,j) = Origin_data[i][j];
            }
        };
    }

    void Display_origin(){
        cout << Origin_data_Matrix <<endl;
    }
    void Display_state(){
        cout << State_data_Matrix << endl;
    }

    void 



};





#endif //BATTLESHIP_AI_TRAINING_BOARD_H
