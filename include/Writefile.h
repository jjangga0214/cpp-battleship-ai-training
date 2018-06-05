//
// Created by sonhyeongi on 6/5/18.
//
#include <iostream>
#include "Eigen/Dense"
#include "NeuralNetwork.h"
#include <fstream>
using namespace std;
#ifndef BATTLESHIP_AI_TRAINING_WRITEFILE_H
#define BATTLESHIP_AI_TRAINING_WRITEFILE_H

void Write(Eigen::MatrixXd data);
Eigen::MatrixXd Read();

#endif //BATTLESHIP_AI_TRAINING_WRITEFILE_H
