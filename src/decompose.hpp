#ifndef DECOMPOSE_HPP
#define DECOMPOSE_HPP

#include <matrix.hpp>

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
