#ifndef VERTICAL_FLIP_H
#define VERTICAL_FLIP_H

#include "src/core/tensor.h"

/**
 * @brief
 * @details
 *
 * @param tensor1 Input image.
 * @param output The output image pointer.
 * @return Status The Status enum indicates whether the routine is OK.
 */

AITISA_API_PUBLIC Status aitisa_vertical_flip(const Tensor input,
                                              Tensor *output);

#endif