#include "gtest/gtest.h"
extern "C"
{
#include "src/new_math_ops/mul_add.h"
    // #include "src/tool/tool.h"
}

void mul_add_assign_float(Tensor t)
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
        TEST(mul_add, Float2d)
        {
            Tensor input1;
            Tensor input2;
            Tensor input3;
            DataType dtype = kFloat;
            Device device = {DEVICE_CPU, 0};
            int64_t dims[2] = {2, 3};
            aitisa_create(dtype, device, dims, 2, NULL, 0, &input1);
            aitisa_create(dtype, device, dims, 2, NULL, 0, &input2);
            aitisa_create(dtype, device, dims, 2, NULL, 0, &input3);
            mul_add_assign_float(input1);
            mul_add_assign_float(input2);
            mul_add_assign_float(input3);

            Tensor output;
            aitisa_mul_add(input1, input2, input3, &output);

            float *out_data = (float *)aitisa_tensor_data(output);
            float test_data[] = {-0.21, -0.16, -0.09, 0., 0.11, 0.24};
            int64_t size = aitisa_tensor_size(input1);
            for (int64_t i = 0; i < size; i++)
            {
                /* Due to the problem of precision, consider the two numbers
                   are equal when their difference is less than 0.000001*/
                EXPECT_TRUE(abs(out_data[i] - test_data[i]) < 0.000001);
            }

            aitisa_destroy(&input1);
            aitisa_destroy(&input2);
            aitisa_destroy(&input3);
            aitisa_destroy(&output);
        }

        TEST(mul_add, Float3d)
        {
            Tensor input1;
            Tensor input2;
            Tensor input3;
            DataType dtype = kFloat;
            Device device = {DEVICE_CPU, 0};
            int64_t dims[2] = {2, 2, 3};
            aitisa_create(dtype, device, dims, 3, NULL, 0, &input1);
            aitisa_create(dtype, device, dims, 3, NULL, 0, &input2);
            aitisa_create(dtype, device, dims, 3, NULL, 0, &input3);
            mul_add_assign_float(input1);
            mul_add_assign_float(input2);
            mul_add_assign_float(input3);

            Tensor output;
            aitisa_mul_add(input1, input2, input3, &output);

            float *out_data = (float *)aitisa_tensor_data(output);
            float test_data[] = {-0.21, -0.16, -0.09, 0., 0.11, 0.24,
                                 0.39, 0.56, 0.75, 0.96, 1.19, 1.44};
            int64_t size = aitisa_tensor_size(input1);
            for (int64_t i = 0; i < size; i++)
            {
                /* Due to the problem of precision, consider the two numbers
                   are equal when their difference is less than 0.000001*/
                EXPECT_TRUE(abs(out_data[i] - test_data[i]) < 0.000001);
            }

            aitisa_destroy(&input1);
            aitisa_destroy(&input2);
            aitisa_destroy(&input3);
            aitisa_destroy(&output);
        }

    } // namespace
} // namespace aitisa_api