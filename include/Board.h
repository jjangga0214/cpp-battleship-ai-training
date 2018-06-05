//
// Created by sonhyeongi on 6/5/18.
//
#include <iostream>
#include "Eigen/Dense"
#include "NeuralNetwork.h"
#include "../Random.h"
using namespace std;
#ifndef BATTLESHIP_AI_TRAINING_BOARD_H
#define BATTLESHIP_AI_TRAINING_BOARD_H



class Board{
private:
    Eigen::MatrixXd origin_data_Matrix;
    Eigen::MatrixXd state_data_Matrix;
    int origin_data[8][8]={{0,}};
public:
    Board()
            :origin_data_Matrix(8,8), state_data_Matrix(8,8)
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
                if (mg.Random_select_position(left, right, direction, size1[size_count], origin_data) == 0) {
                    size_count++;
                }
            }
        }


        for(int i=0; i<8; ++i) {
            for(int j=0; j<8; ++j) {
                origin_data_Matrix(i,j) = origin_data[i][j];
            }
        };
    }

    void display_origin(){
        cout << origin_data_Matrix <<endl;
    }
    void display_state(){
        cout << state_data_Matrix << endl;
    }

    Eigen::VectorXd change_Vector(){
        Eigen::VectorXd result(64);
        int count=0;
        for(int i=0; i<8; ++i) {
            for(int j=0; j<8; ++j) {
                result(count++) = state_data_Matrix(i,j);
            }
        }
        return result;
    }

    Eigen::VectorXd calc_Maxtirx(){
        Eigen::VectorXd result(64);
        int count=0;
        for (int i = 0; i <8 ; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (origin_data_Matrix(i,j)==1){
                    if(state_data_Matrix(i,j)==0){
                        result(count) = 1;
                    }
                }
                ++count;
            }

        }
        return result;
    }


};





#endif //BATTLESHIP_AI_TRAINING_BOARD_H
