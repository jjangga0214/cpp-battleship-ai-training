//
// Created by sonhyeongi on 6/5/18.
//

#include <iostream>
#include <fstream>
#include "Writefile.h"

using namespace std;

std::string filepath = "../output.txt";

void Write(Eigen::MatrixXd data) {
    fstream inStream;
    inStream.open(filepath, ios::app);
    if (inStream.fail()) {
        cout << "NO File" << endl;
        return;
    }

    for (int i = 0; i < data.rows(); ++i) {
        for (int j = 0; j < data.cols(); ++j) {
            inStream << data(i, j)<<" ";
        }
    }
    inStream << endl;
}

Eigen::MatrixXd Read() {
    fstream Instream;
    Eigen::MatrixXd result(8, 8);
    Instream.open(filepath);
    if (Instream.fail()) {
        cout << "NO File" << endl;
    } else {
        int input;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                Instream >> input;
                result(i, j) = input;
            }
        }
    }
    return result;
}