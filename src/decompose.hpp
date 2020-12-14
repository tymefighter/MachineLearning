#ifndef DECOMPOSE_HPP
#define DECOMPOSE_HPP

#include <matrix.hpp>

void decomposeLU(Matrix &mat, Matrix &L, Matrix &U);

void decomposeLUP(
    Matrix &mat, 
    Matrix &L, 
    Matrix &U,
    Matrix &P
);

#endif
