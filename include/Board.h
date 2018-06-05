//
// Created by sonhyeongi on 6/5/18.
//
#pragma once

#include <iostream>
#include "Eigen/Dense"
#include "NeuralNetwork.h"
#include "Random.h"

using namespace std;

namespace bts {
    namespace ai {
        class Board;
    }
}

class bts::ai::Board {
private:
    Eigen::MatrixXd origin_data_matrix;
    Eigen::MatrixXd State_data_Matrix;
    int Origin_data[8][8] = {{0,}};
public:
    Board()
            : origin_data_matrix(8, 8), State_data_Matrix(8, 8) {
        Make mg;
        int size1[5] = {5, 4, 3, 2, 2};
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


        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                origin_data_matrix(i, j) = Origin_data[i][j];
            }
        };
    }

    void Display_origin() {
        cout << origin_data_matrix << endl;
    }

    void Display_state() {
        cout << State_data_Matrix << endl;
    }

    Eigen::VectorXd Change_Vector() {
        Eigen::VectorXd result(64);
        int count = 0;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                result(count++) = State_data_Matrix(i, j);
            }
        }
        return result;
    }

    Eigen::VectorXd Calc_Maxtirx() {
        Eigen::VectorXd result(64);
        int count = 0;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (origin_data_matrix(i, j) == 1) {
                    if (State_data_Matrix(i, j) == 0) {
                        result(count) = 1;
                    }
                }
                ++count;
            }

        }
        return result;
    }


};

