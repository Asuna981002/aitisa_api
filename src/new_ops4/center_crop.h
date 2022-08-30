#ifndef CENTER_CROP_H
#define CENTER_CROP_H

#include "src/core/tensor.h"

/**
 * @brief 
 *
 * @param input The input tensor.
 * @param output The output tensor pointer.
 * @return Status The Status enum indicates whether the routine is OK.
 */
AITISA_API_PUBLIC Status aitisa_center_crop(const Tensor input, int target_h, int target_w, Tensor *output);

#endif // CENTER_CROP_H
