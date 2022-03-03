#include <iostream>
#include "mat.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

namespace ariel {

    string mat(int columns, int rows, char symb1, char symb2) {
        char **matrix = new char *[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new char[columns];
        }
        bool flag= true;
        string to_print = HelperMat(columns, rows, symb1, symb2, columns, matrix,true);
    }

    string HelperMat(int c, int r, char symb1, char symb2, int size, char ** matrix, bool flag) {
        if(c==1||r==1){//base case
            if(c==1){
                for(int i=0 ; i<r ; i++){

                }
            }
            else{
                for(int i=0 ; i<c ; i++){

                }
            }
        }
        else
    }
}
