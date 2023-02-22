#include "src/new_math_ops/mul_add.h"
#include "src/core/dispatch.h"

#define mul_add_kernel(typename)                                       \
    {                                                                  \
        typename *x_data = aitisa_tensor_data(x);                      \
        typename *y_data = aitisa_tensor_data(y);                      \
        typename *a_data = aitisa_tensor_data(a);                      \
        typename *z_data = aitisa_tensor_data(*z);                     \
        for (int64_t i = 0; i < size; i++)                             \
        {                                                              \
            z_data[i] = (typename)(x_data[i] * y_data[i] + a_data[i]); \
        }                                                              \
    }

// Definition of aitisa_matmul.
Status aitisa_mul_add(const Tensor x, const Tensor y,
                      const Tensor a, Tensor *z)
{
    if (aitisa_tensor_device(x).type != DEVICE_CPU ||
        aitisa_tensor_device(y).type != DEVICE_CPU)
    {
        return STATUS_NOT_SUPPORTED;
    }
    int64_t ndim1 = aitisa_tensor_ndim(x);
    int64_t *dims1 = aitisa_tensor_dims(x);

    int64_t ndim2 = aitisa_tensor_ndim(y);
    int64_t *dims2 = aitisa_tensor_dims(y);

    int64_t ndim3 = aitisa_tensor_ndim(a);
    int64_t *dims3 = aitisa_tensor_dims(a);
    Status status = STATUS_SUCCESS;

    if ((ndim1 != ndim2) || (ndim1 != ndim3))
    {
        return STATUS_DIMENSIONS_MISMATCH;
    }

    for (int64_t i = 0; i < ndim1; i++)
    {
        if ((dims1[i] != dims2[i]) || (dims1[i] != dims3[i]))
            return STATUS_DIMENSIONS_MISMATCH;
    }

    Device device = aitisa_tensor_device(x);
    DataType dtype = aitisa_tensor_data_type(x);
    Tensor new_tensor;
    CHECK_STATUS(
        aitisa_create(dtype, device, dims1, ndim1, NULL, 0, &new_tensor));
    *z = new_tensor;
    int64_t size = aitisa_tensor_size(x);
    AITISA_DISPATCH_ALL_TYPES_RETURN(dtype, mul_add_kernel);

    return STATUS_SUCCESS;
}