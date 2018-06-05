//
// Created by sonhyeongi on 6/5/18.
//
#include <iostream>
#include "Eigen/Dense"
#include "NeuralNetwork.h"
#include "Random.h"
#include <string>
#include <unistd.h>
#include "Random.h"
using namespace std;
#ifndef BATTLESHIP_AI_TRAINING_BOARD_H
#define BATTLESHIP_AI_TRAINING_BOARD_H


class Board {
private:
    Eigen::MatrixXd origin_data_matrix;
    Eigen::MatrixXd state_data_matrix;
    int origin_data[8][8] = {{0,}};
public:
    Board() : origin_data_matrix(8, 8), state_data_matrix(8, 8) {
        Make mg;
        int size1[5] = {5, 4, 3, 2, 2};
        int size_count = 0;


        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        srand((time_t)ts.tv_nsec);

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


        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                origin_data_matrix(i, j) = origin_data[i][j];
            }
        };
    }

    void display_origin() {
        cout << origin_data_matrix << endl;
    }

    void display_state() {
        cout << state_data_matrix << endl;
    }

    Eigen::VectorXd change_vector() {
        Eigen::VectorXd result(64);
        int count = 0;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                result(count++) = state_data_matrix(i, j);
            }
        }
        return result;
    }

    Eigen::VectorXd calc_matrix() {
        Eigen::VectorXd result(64);
        int count = 0;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (origin_data_matrix(i, j) == 1) {
                    if (state_data_matrix(i, j) == 0) {
                        result(count) = 1;
                    }else{
                        result(count) = 0;
                    }
                }
                ++count;
            }

        }
        return result;
    }

    Eigen::MatrixXd getMatirx(string option){
        Eigen::MatrixXd result;
        if (option=="origin"){
            result = origin_data_matrix;
        }
        else if(option=="state"){
            result = state_data_matrix;
        }
        return result;
    }


};


#endif //BATTLESHIP_AI_TRAINING_BOARD_H
