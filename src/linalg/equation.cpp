#include <linalg/matrix.hpp>
#include <linalg/equation.hpp>

Solution solveEquations(
    const Matrix &A,
    const Matrix &b,
    Matrix &x
) {
    if(A.getNumRows() != b.getNumRows() || b.getNumCols() != 1)
        throw MatError("Input shapes do not agree");

    int n = A.getNumRows(), m = A.getNumCols();
    x = Matrix(m, 1);


}
