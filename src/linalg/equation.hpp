#ifndef EQUATION_HPP
#define EQUATION_HPP

#include <linalg/matrix.hpp>

enum Solution {NO_SOLUTION, ONE_SOLUTION, INFINITE_SOLUTIONS};

/**
 * Solves the equation Ax = b using Gaussian Elimination followed by 
 * Back Substitution. If the solution does not exist or there are
 * infinite solutions (the return value would would indicate the
 * case), then the solution x has no importance. If there is exactly
 * one solution, then x would be that solution
 * 
 * @param A The Coefficient Matrix
 * @param b The vector of outputs
 * @param x The vector of variables, in this matrix the output is
 * provided
 */
Solution solveEquations(
    const Matrix &A,
    const Matrix &b,
    Matrix &x
);

#endif
