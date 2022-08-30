#ifndef CROP_TO_BOUNDING_BOX_H
#define CROP_TO_BOUNDING_BOX_H

#include "src/core/tensor.h"

/**
 * @brief 
 *
 * @param input The input tensor.
 * @param output The output tensor pointer.
 * @return Status The Status enum indicates whether the routine is OK.
 */
AITISA_API_PUBLIC Status aitisa_crop_to_bounding_box(const Tensor input, int offset_h, int offset_w, int target_h, int target_w, Tensor *output);

#endif // CROP_TO_BOUNDING_BOX_H
