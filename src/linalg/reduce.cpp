#include <linalg/matrix.hpp>
#include <linalg/reduce.hpp>

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

Matrix getREF(const Matrix &mat) {
    int n = mat.getNumRows(), m = mat.getNumCols();
    Matrix res(mat);

    int i = 0, j = 0;
    while(i < n && j < m) {
        if(fabs(res(i, j)) < EPS) {
            int k = i + 1;

            while(k < n && res(k, j) == 0)
                k ++;

            if(k < n) swapRows(res, i, k);
            else {
                j ++;
                continue;
            }
        }

        for(int k = i + 1;k < n;k++)
            addRow(res, k, i, -res(k, j) / res(i, j));

        i ++, j ++;
    }

    return res;
}

Matrix getRREF(const Matrix &mat) {
    int n = mat.getNumRows(), m = mat.getNumCols();
    Matrix res(mat);

    int i = 0, j = 0;
    while(i < n && j < m) {
        if(res(i, j) == 0) {
            int k = i + 1;

            while(k < n && res(k, j) == 0)
                k ++;

            if(k < n) swapRows(res, i, k);
            else {
                j ++;
                continue;
            }
        }

        if(res(i, j) != 1)
            mulRow(res, i, 1.0 / res(i, j));

        for(int k = 0;k < n;k++) {
            if(k == i) continue;
            
            addRow(res, k, i, -res(k, j));
        }

        i ++, j ++;
    }

    return res;
}
