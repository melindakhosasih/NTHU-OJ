#include <iostream>
#include "function.h"
using namespace std;

Matrix::Matrix(int s):size(s) {
    matrix = new int*[s];
    buf = new int[s*s];

    for(int i = 0; i < size; i++)
        matrix[i] = &buf[i*size];

    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            matrix[i][j] = 0;
}

Matrix::Matrix(const Matrix &a) {
    *this = a;
}

Matrix &Matrix::clockwise90() {
    Matrix a;
    a = *this;
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            matrix[i][j] = a.matrix[size-j-1][i];
    return *this;
}

Matrix::~Matrix() {
    delete [] buf;
    delete [] matrix;
}

Matrix &Matrix::operator=(const Matrix &a) {
    if (a.size != size) {
        delete [] buf;
        delete [] matrix;

        size = a.size;
        buf = new int [size*size];
        matrix = new int* [size];

        for(int i = 0; i < size; i++)
            matrix[i] = &buf[i*size];
    }
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            matrix[i][j] = a.matrix[i][j];
    return *this;
}

std::istream &operator>>(std::istream &in, Matrix &a) {
    for(int i = 0; i < a.size; i++)
        for(int j = 0; j < a.size; j++)
            cin >> a.matrix[i][j];
    return in;
}

std::ostream &operator<<(std::ostream &out, const Matrix &a) {
    int i, j;
    for(i = 0; i < a.size; i++) {
        for(j = 0; j < a.size-1; j++){
            cout << a.matrix[i][j] << ' ';
        }
        cout << a.matrix[i][j] << endl;
    }
    return out;
}
