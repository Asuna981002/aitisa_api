#ifndef RANDOM_CONTRAST_H
#define RANDOM_CONTRAST_H

#include "src/core/tensor.h"

/**
 * @brief 
 *
 * @param input The input tensor.
 * @param output The output tensor pointer.
 * @return Status The Status enum indicates whether the routine is OK.
 */
AITISA_API_PUBLIC Status aitisa_random_contrast(const Tensor input, double lower, double upper, Tensor *output);

#endif // RANDOM_CONTRAST_H
