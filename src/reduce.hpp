#ifndef REDUCE_HPP
#define REDUCE_HPP

#include <matrix.hpp>

/**
 * Construct a Row Echelon Form matrix from the provided argument
 * 
 * @param mat Input Matrix
 * @return Row Echelon Form Matrix
 */
Matrix getREF(Matrix &mat);

/**
 * Construct THE Reduced Row Echelon Form matrix from
 * the provided argument
 * 
 * @param mat Input Matrix
 * @return Reduced Row Echelon Form Matrix
 */
Matrix getRREF(Matrix &mat);

#endif;
