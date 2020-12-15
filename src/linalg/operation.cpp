#include <linalg/matrix.hpp>
#include <linalg/reduce.hpp>
#include <linalg/operation.hpp>

/** Tranpose */

Matrix transpose(const Matrix &mat) {
    int n = mat.getNumRows();
    int m = mat.getNumCols();
    Matrix resMat(m, n);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            resMat(j, i) = mat(i, j);
    }

    return resMat;
}

/** Matrix Multiplication */

Matrix matmul(const Matrix &a, const Matrix &b) {

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

/** Elementwise Multiplication */

Matrix mul(const Matrix &a, const Matrix &b) {

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

/** Elementwise Division */

Matrix div(const Matrix &a, const Matrix &b) {

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

/** Inverse */

/**
 * Computes Augmented Matrix consisting of the input
 * matrix and the identity matrix. The input matrix
 * is assumed to be a square matrix
 * 
 * @param mat The input matrix
 * @return matrix [mat Identity]
 */
Matrix getAugmentedMatrix(const Matrix &mat) {
    int n = mat.getNumRows();
    Matrix augMat(n, 2 * n);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++)
            augMat(i, j) = mat(i, j);

        for(int j = n;j < 2 * n;j++)
            augMat(i, j) = (i == j - n ? 1 : 0);
    }

    return augMat;
}

Matrix inverse(const Matrix &mat) {
    if(mat.getNumRows() != mat.getNumCols())
        throw MatError(
            "Cannot Compute Inverse - "
            "Number of Rows and Number of Cols do not match"
        );

    int n = mat.getNumRows();

    // Get Augmented Matrix: [mat Identity]
    Matrix augMat = getAugmentedMatrix(mat);

    // Get RREF using Gauss-Jordan method
    // rref = [R E]
    Matrix rref = getRREF(augMat);

    // If R in rref = [R E] is not identity, then
    // inverse does not exist
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if(rref(i, j) != (i == j ? 1 : 0))
                throw MatError("Input Matrix is not invertible");
        }
    }

    // Inverse exists and is E in rref = [R E]
    // build the inverse and return it
    Matrix matInv(n, n);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++)
            matInv(i, j) = rref(i, j + n);
    }

    return matInv;
}
