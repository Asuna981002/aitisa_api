#ifndef IMAGE_GRADIENTS_H
#define IMAGE_GRADIENTS_H

#include "src/core/tensor.h"

/**
 * @brief
 * @details
 *
 * @param tensor1 Input image.
 * @param output The output image pointer.
 * @return Status The Status enum indicates whether the routine is OK.
 */

AITISA_API_PUBLIC Status aitisa_image_gradients(const Tensor input,
                                                Tensor *grad_x,
                                                Tensor *grad_y);

#endif