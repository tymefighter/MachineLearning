#include <mat.hpp>
#include <operation.hpp>

Matrix transpose(Matrix &mat) {
    int n = mat.getNumCols();
    int m = mat.getNumRows();
    Matrix resMat(m, n);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            resMat(j, i) = mat(i, j);
    }

    return resMat;
}


