#ifndef ADJUST_GAMMA_H
#define ADJUST_GAMMA_H

#include "src/core/tensor.h"

/**
 * @brief 
 *
 * @param input The input tensor.
 * @param output The output tensor pointer.
 * @return Status The Status enum indicates whether the routine is OK.
 */
AITISA_API_PUBLIC Status aitisa_adjust_gamma(const Tensor input, double gain, double gamma, Tensor *output);

#endif // ADJUST_GAMMA_H
