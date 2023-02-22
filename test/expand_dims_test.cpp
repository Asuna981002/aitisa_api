#include "gtest/gtest.h"
extern "C"
{
#include "src/new_math_ops/expand_dims.h"
    // #include "src/tool/tool.h"
}

void expand_dims_assign_float(Tensor t)
{
    int64_t size = aitisa_tensor_size(t);
    float *data = (float *)aitisa_tensor_data(t);
    float value = 0;
    for (int i = 0; i < size; ++i)
    {
        value = i * 0.1 - 0.3;
        data[i] = value;
    }
}

namespace aitisa_api
{
    namespace
    {
        TEST(ExpandDims, Case1)
        {
            Tensor input;
            DataType dtype = kFloat;
            Device device = {DEVICE_CPU, 0};
            int64_t dims[2] = {2, 3};
            aitisa_create(dtype, device, dims, 2, NULL, 0, &input);
            expand_dims_assign_float(input);

            Tensor output;
            aitisa_expand_dims(input, 0, &output);

            float *out_data = (float *)aitisa_tensor_data(output);
            float test_data[] = {-0.3, -0.2, -0.1, 0., 0.1, 0.2};
            int64_t size = aitisa_tensor_size(input);
            for (int64_t i = 0; i < size; i++)
            {
                /* Due to the problem of precision, consider the two numbers
                   are equal when their difference is less than 0.000001*/
                EXPECT_TRUE(abs(out_data[i] - test_data[i]) < 0.000001);
            }

            aitisa_destroy(&input);
            aitisa_destroy(&output);
        }

        TEST(ExpandDims, Case2)
        {
            Tensor input;
            DataType dtype = kFloat;
            Device device = {DEVICE_CPU, 0};
            int64_t dims[2] = {2, 3};
            aitisa_create(dtype, device, dims, 2, NULL, 0, &input);
            expand_dims_assign_float(input);

            Tensor output;
            aitisa_expand_dims(input, 1, &output);

            float *out_data = (float *)aitisa_tensor_data(output);
            float test_data[] = {-0.3, -0.2, -0.1, 0., 0.1, 0.2};
            int64_t size = aitisa_tensor_size(input);
            for (int64_t i = 0; i < size; i++)
            {
                /* Due to the problem of precision, consider the two numbers
                   are equal when their difference is less than 0.000001*/
                EXPECT_TRUE(abs(out_data[i] - test_data[i]) < 0.000001);
            }

            aitisa_destroy(&input);
            aitisa_destroy(&output);
        }
    } // namespace
} // namespace aitisa_api