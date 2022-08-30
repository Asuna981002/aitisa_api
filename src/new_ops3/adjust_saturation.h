#ifndef ADJUST_SATURATION_H
#define ADJUST_SATURATION_H

#include "src/core/tensor.h"

/**
 * @brief 
 *
 * @param input The input tensor.
 * @param output The output tensor pointer.
 * @return Status The Status enum indicates whether the routine is OK.
 */
AITISA_API_PUBLIC Status aitisa_adjust_saturation(const Tensor input, double saturation_factor, Tensor *output);

#endif // ADJUST_SATURATION_H
