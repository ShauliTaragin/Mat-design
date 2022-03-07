#include <iostream>
#include "mat.hpp"
#include <string>
#include <stdexcept>

using namespace std;

const int maximum_digit = 1000;

namespace ariel {
    string mat(int columns, int rows, char symb1, char symb2) {
        if (columns % 2 == 0 || rows % 2 == 0 || rows < 1 || columns < 1) {
            throw invalid_argument("Mat size is always odd ");
        }
        else {
            char **matrix = new char *[rows];
            for (int i = 0; i < rows; ++i) {
                matrix[i] = new char[columns];
            }
            bool flag = true;
            //I will implement this function by working like an onion i.e. I will create each frame separately
            //starting from external frame until the final center frame.
            int start_rows = 0;
            int start_columns = 0;
            int end_rows = rows;
            int end_columns = columns;
            int row_counter = rows;
            int col_counter = columns;
            while (col_counter > 0 && row_counter > 0) {
                for (int i = start_rows; i < end_rows; ++i) {
                    for (int j = start_columns; j < end_columns; ++j) {
                        if (i == start_rows || i == end_rows - 1 || j == start_columns || j == end_columns - 1) {
                            if (flag) {
                                matrix[i][j] = symb1;
                            }
                            else {
                                matrix[i][j] = symb2;
                            }
                        }
                    }
                }
                if (flag) {//want to make sure to switch between symbols
                    flag = false;
                }
                else {
                    flag = true;
                }
                start_columns++;
                start_rows++;
                end_columns--;
                end_rows--;
                row_counter -= 2;
                col_counter -= 2;
            }
            string result = "";
            //now all thats left is to make the matrix into a string which is printable easily
            for (int i = 0; i < rows; ++i) {
                if (i != 0)
                    result += '\n';
                for (int j = 0; j < columns; ++j) {
                    result += matrix[i][j];
                }
            }
            //delete arrays to make sure no memory leaks
            for (int i = 0; i < rows; ++i){
                delete [] matrix[i];
            }
            delete [] matrix;
            return result;
        }
    }
}
