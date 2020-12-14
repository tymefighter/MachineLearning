#include <matrix.hpp>
#include <reduce.hpp>

/** Multiplies ith row with constant c */
void mulRow(Matrix &mat, int i, double c) {
    for(int j = 0;j < mat.getNumCols();j++)
        mat(i, j) *= c;
}

/** Adds jth row multiplied with constant c to the ith row */
void addRow(Matrix &mat, int i, int j, double c) {
    for(int k = 0;k < mat.getNumCols();k++)
        mat(i, k) += mat(j, k) * c;
}

/** Swaps the ith and jth row */
void swapRows(Matrix &mat, int i, int j) {
    for(int k = 0;k < mat.getNumCols();k++)
        swap(mat(i, k), mat(j, k));
}

Matrix getREF(Matrix &mat) {
   
}
