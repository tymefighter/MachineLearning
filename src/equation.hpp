#ifndef EQUATION_HPP
#define EQUATION_HPP

enum Solution {NO_SOLUTION, ONE_SOLUTION, INFINITE_SOLUTIONS};

Solution solveEquations(
    Matrix &A,
    Matrix &b,
    Matrix &X
);

#endif
