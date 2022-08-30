#ifndef ADJUST_CONTRAST_H
#define ADJUST_CONTRAST_H

#include "src/core/tensor.h"

/**
 * @brief 
 *
 * @param input The input tensor.
 * @param output The output tensor pointer.
 * @return Status The Status enum indicates whether the routine is OK.
 */
AITISA_API_PUBLIC Status aitisa_adjust_contrast(const Tensor input, double contrast_factor, Tensor *output);

#endif // ADJUST_CONTRAST_H
