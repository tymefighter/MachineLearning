#include <matrix.hpp>
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

Matrix matmul(Matrix &a, Matrix &b) {

    if(a.getNumCols() != b.getNumRows())
        throw MatError(
            "Matrix Multiplication Cannot be performed - "
            "shapes do not agree"
        );

    int n = a.getNumRows();
    int p = a.getNumCols();
    int m = b.getNumCols();

    Matrix resMat(n, m);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            for(int k = 0;k < p;k++)
                resMat(i, j) += a(i, k) * b(k, j);
        }
    }

    return resMat;
}

Matrix mul(Matrix &a, Matrix &b) {

    if(a.getShape() != b.getShape())
        throw MatError(
            "Elementwise Multiplication Cannot be performed - "
            "shapes do not match"
        );

    int n = a.getNumRows(), m = a.getNumCols();
    Matrix resMat(n, m);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            resMat(i, j) = a(i, j) * b(i, j);
    }

    return resMat;
}

Matrix div(Matrix &a, Matrix &b) {

    if(a.getShape() != b.getShape())
        throw MatError(
            "Elementwise Division Cannot be performed - "
            "shapes do not match"
        );

    int n = a.getNumRows(), m = a.getNumCols();
    Matrix resMat(n, m);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            resMat(i, j) = a(i, j) / b(i, j);
    }

    return resMat;
}
