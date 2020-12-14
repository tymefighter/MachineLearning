#ifndef REDUCE_HPP
#define REDUCE_HPP

#include <matrix.hpp>

/**
 * Construct a Row Echelon Form matrix from the provided argument.
 * It uses the Gaussian Elimination Method.
 * Complexity - O(n * m * min(n, m))
 * 
 * @param mat Input Matrix
 * @return Row Echelon Form Matrix
 */
Matrix getREF(const Matrix &mat);

/**
 * Construct THE Reduced Row Echelon Form matrix from the provided argument.
 * It uses the Gauss-Jordan Method.
 * Complexity - O(n * m * min(n, m))
 * 
 * @param mat Input Matrix
 * @return Row Reduced Echelon Form Matrix
 */
Matrix getRREF(const Matrix &mat);

#endif;
