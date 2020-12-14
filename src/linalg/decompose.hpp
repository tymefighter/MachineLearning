#ifndef DECOMPOSE_HPP
#define DECOMPOSE_HPP

#include <linalg/matrix.hpp>

void decomposeLU(
    const Matrix &mat, 
    Matrix &L, 
    Matrix &U
);

void decomposeLUP(
    const Matrix &mat, 
    Matrix &L, 
    Matrix &U,
    Matrix &P
);

#endif
