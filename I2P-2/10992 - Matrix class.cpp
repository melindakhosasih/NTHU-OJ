#include <iostream>
#include "function.h"
using namespace std;
Matrix::Matrix() : matrix{}{};
Matrix::Matrix (const int n, const int mat[50][50]) {
    matrix_size = n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            matrix[i][j] = mat[i][j];
}
Matrix Matrix::add(const Matrix b) const {
    Matrix ans;
    ans.matrix_size = matrix_size;
    for(int i = 0; i < matrix_size; i++)
        for(int j = 0; j < matrix_size; j++)
            ans.matrix[i][j] = matrix[i][j] + b.matrix[i][j];
    return ans;
}
Matrix Matrix::subtract(const Matrix b) const {
    Matrix ans;
    ans.matrix_size = matrix_size;
    for(int i = 0; i < matrix_size; i++)
        for(int j = 0; j < matrix_size; j++)
            ans.matrix[i][j] = matrix[i][j] - b.matrix[i][j];
    return ans;
}
Matrix Matrix::multiplication(const Matrix b) const {
    Matrix ans;
    int i, j, k;
    ans.matrix_size = matrix_size;
    for(i = 0; i < matrix_size; i++) {
        for(j = 0; j < matrix_size; j++)
            for(k = 0; k < matrix_size; k++)
                ans.matrix[i][j] += matrix[i][k] * b.matrix[k][j];
    }
    return ans;
}
Matrix Matrix::inc(void) const {
    Matrix ans;
    ans.matrix_size = matrix_size;
    for(int i = 0; i < matrix_size; i++)
        for(int j = 0; j < matrix_size; j++)
            ans.matrix[i][j] = (matrix[i][j] + 1) % 10;
    return ans;
}
void Matrix::Transpose(void) const {
    int i, j;
    for(i = 0; i < matrix_size; i++) {
        for(j = 0; j < matrix_size-1; j++) {
            cout << matrix[j][i] << ' ';
        }
        cout << matrix[j][i] << endl;
    }
}
void Matrix::output(void) const {
    int i, j;
    for(i = 0; i < matrix_size; i++) {
        for(j = 0; j < matrix_size-1; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << matrix[i][j] << endl;
    }

}
