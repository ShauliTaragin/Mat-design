#include <iostream>
#include "mat.h"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
namespace ariel {
    string mat(int columns, int rows, char symb1, char symb2) {
         char matrix[rows][columns];
         string to_print = mat(columns, rows, symb1, symb2 ,columns, matrix);
    }
    string mat(int c, int r, char symb1, char symb2 ,int size, char matrix[][size]){

    }
}