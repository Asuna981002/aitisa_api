#ifndef EXPAND_DIMS_H
#define EXPAND_DIMS_H

#include "src/core/tensor.h"
#include "stdlib.h"

/**
 * @brief Applies a reshape over an input tensor within a specified dimension.
 *
 * @param input The input tensor.
 * @param dims The new dimension to reshape to.
 * @param ndim The length of array dims.
 * @param output The output tensor pointer.
 * @return Status The Status enum indicates whether the routine is OK.
 */
AITISA_API_PUBLIC Status aitisa_reshape(const Tensor input,
                                        const int axis,
                                        Tensor *output);

#endif // EXPAND_DIMS_H
