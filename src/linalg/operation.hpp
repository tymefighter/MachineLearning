#ifndef OPERATION_HPP
#define OPERATION_HPP

#include <linalg/matrix.hpp>

Matrix transpose(const Matrix &mat);

Matrix matmul(const Matrix &a, const Matrix &b);

Matrix mul(const Matrix &a, const Matrix &b);

Matrix div(const Matrix &a, const Matrix &b);

Matrix inverse(const Matrix &mat);

#endif
