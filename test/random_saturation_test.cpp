#include "gtest/gtest.h"
extern "C" {
#include "src/new_ops3/random_saturation.h"
//#include "src/tool/tool.h"
}

void random_saturation_assign_float(Tensor t) {
  int64_t size = aitisa_tensor_size(t);
  float* data = (float*)aitisa_tensor_data(t);
  float value = 0;
  for (int i = 0; i < size; ++i) {
    value = (float)i;
    data[i] = value;
  }
}

namespace aitisa_api {
namespace {
TEST(RandomHue, Float3d) {
  Tensor input;
  DataType dtype = kFloat;
  Device device = {DEVICE_CPU, 0};
  int64_t dims[3] = {3, 2, 3};
  aitisa_create(dtype, device, dims, 3, NULL, 0, &input);
  random_saturation_assign_float(input);
  // tensor_printer2d(input);

  Tensor output;
  aitisa_random_saturation(input, 0.8, 1.2, &output);
  // tensor_printer2d(output);
  srand(0);
  double factor = (rand() / double(RAND_MAX)) * (1.2 - 0.8) + 0.8;

  float* out_data = (float*)aitisa_tensor_data(output);
  float test_data[] = {0., 0., 0.3671, 1.3671, 2.3671, 3.3671,
                       12., 13., 14., 15., 16., 17.,
                       12., 13., 14., 15., 16., 17.};
  int64_t size = aitisa_tensor_size(output);
  for (int64_t i = 0; i < size; i++) {
    /* Due to the problem of precision, consider the two numbers
       are equal when their difference is less than 0.0001*/
    EXPECT_TRUE(abs(out_data[i] - test_data[i]) < 0.0001);
  }

  aitisa_destroy(&input);
  aitisa_destroy(&output);
}
}  // namespace
}  // namespace aitisa_api