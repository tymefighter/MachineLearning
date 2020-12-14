#ifndef OPERATION_HPP
#define OPERATION_HPP

#include <matrix.hpp>

Matrix transpose(Matrix &mat);

Matrix matmul(Matrix &a, Matrix &b);

Matrix mul(Matrix &a, Matrix &b);

Matrix div(Matrix &a, Matrix &b);

Matrix inverse(Matrix &mat);

#endif;
