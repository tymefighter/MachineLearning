#ifndef EQUATION_HPP
#define EQUATION_HPP

#include <matrix.hpp>

enum Solution {NO_SOLUTION, ONE_SOLUTION, INFINITE_SOLUTIONS};

Solution solveEquations(
    const Matrix &A,
    const Matrix &b,
    Matrix &X
);

#endif
