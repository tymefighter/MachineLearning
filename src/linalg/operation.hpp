#ifndef OPERATION_HPP
#define OPERATION_HPP

#include <linalg/matrix.hpp>

/**
 * Computes the Transpose of the input matrix
 * 
 * @param mat Input Matrix
 * @return The tranpose of the input matrix
 */
Matrix transpose(const Matrix &mat);

/**
 * Multiplies the input matrices
 * 
 * @param a First input matrix
 * @param b Second input matrix
 * @return result of matrix multiplication ab
 */
Matrix matmul(const Matrix &a, const Matrix &b);

/**
 * Multiplies the input matrices elementwise
 * 
 * @param a First input matrix
 * @param b Second input matrix
 * @return result of elementwise multiplication a * b
 */
Matrix mul(const Matrix &a, const Matrix &b);

/**
 * Divides the input matrices elementwise
 * 
 * @param a First input matrix
 * @param b Second input matrix
 * @return result of elementwise division a / b
 */
Matrix div(const Matrix &a, const Matrix &b);

/**
 * Computes the inverse of the input matrix. The input
 * has to be a square matrix. If the matrix is not square
 * or not invertible then a MatError is thrown
 * 
 * @param mat The input square matrix
 * @return inverse of the input matrix if it exists, else
 * an error is thrown
 */
Matrix inverse(const Matrix &mat);

#endif
