#ifndef IMAGE_NORMALIZE
#define IMAGE_NORMALIZE

#include "src/core/tensor.h"

/**
 * @brief 
 *
 * @param input The input tensor.
 * @param output The output tensor pointer.
 * @return Status The Status enum indicates whether the routine is OK.
 */
AITISA_API_PUBLIC Status aitisa_image_normalize(const Tensor input, double *mean, double *std, Tensor *output);

#endif // IMAGE_NORMALIZE
