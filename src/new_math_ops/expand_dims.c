#include "src/basic/expand_dims.h"
#include "src/core/utils.h"

#define expand_dims_kernel(typename)                      \
    {                                                     \
        typename *in_data = aitisa_tensor_data(input);    \
        typename *out_data = aitisa_tensor_data(*output); \
        for (int64_t i = 0; i < size; i++)                \
        {                                                 \
            out_data[i] = (typename)(in_data[i]);         \
        }                                                 \
    }

Status aitisa_expand_dims(const Tensor input, const int axis, Tensor *output)
{
    int64_t *dims = aitisa_tensor_dims(input);
    int64_t ndim = aitisa_tensor_ndim(input);
    int64_t out_ndim = ndim + 1;
    int64_t *out_dims;
    if (axis < 0 || axis > ndim)
    {
        return STATUS_DIMENSIONS_MISMATCH;
    }

    // calculate dim infos
    out_dims = (int64_t)malloc(out_ndim);
    for (int i = 0; i < axis; i++)
    {
        out_dims[i] = dims[i];
    }
    out_dims[axis] = 1;
    for (int i = axis + 1; i < out_ndim; i++)
    {
        out_dims[i] = dims[i - 1];
    }
    Device device = aitisa_tensor_device(input);
    // LayoutType layout_type = aitisa_tensor_layout_type(input);
    DataType dtype = aitisa_tensor_data_type(input);
    Tensor new_tensor;
    CHECK_STATUS(
        aitisa_create(dtype, device, out_dims, out_ndim, NULL, 0, &new_tensor));
    *output = new_tensor;
    int64_t size = aitisa_tensor_size(input);
    AITISA_DISPATCH_ALL_TYPES_RETURN(dtype, expand_dims_kernel);

    return STATUS_SUCCESS;
}
