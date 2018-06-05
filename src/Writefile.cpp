//
// Created by sonhyeongi on 6/5/18.
//

#include <iostream>
#include <fstream>
#include "Writefile.h"
using namespace std;

void Write(Eigen::MatrixXd data){
    fstream Instream;
    Instream.open("/home/sonhyeongi/cpp-battleship-ai-training/output.txt",ios::app);
    if (Instream.fail()){
        cout << "NO File" << endl;
    }
    else{
        int output;
        for (int i = 0; i <8 ; ++i) {
            for (int j = 0; j <8 ; ++j) {
                output = data(i,j);
                if (i==7 && j==7){
                Instream << output ;
                }
                else{
                    Instream << output << " ";
                }
            }
        }
        Instream << endl;
    }
}

Eigen::MatrixXd Read(){
    fstream Instream;
    Eigen::MatrixXd result(8,8);
    Instream.open("/home/sonhyeongi/cpp-battleship-ai-training/output.txt");
    if (Instream.fail()){
        cout << "NO File" << endl;
    }
    else{
        int input;
        for (int i = 0; i <8 ; ++i) {
            for (int j = 0; j < 8; ++j) {
                Instream >> input;
                result(i, j) = input;
            }
        }
    }
    return result;
}