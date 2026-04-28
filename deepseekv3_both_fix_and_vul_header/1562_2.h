#include <stdint.h>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef struct TfLiteContext TfLiteContext;
typedef struct TfLiteTensor TfLiteTensor;

struct RuntimeShape {
  int dimensions_count;
  int sizes[4];
};

template <typename T>
T* GetTensorData(const TfLiteTensor* tensor) {
  return nullptr;
}

RuntimeShape GetTensorShape(const TfLiteTensor* tensor) {
  return RuntimeShape();
}

void TF_LITE_KERNEL_LOG(TfLiteContext* context, const char* format, ...) {}

namespace reference_ops {
template <typename ParamsT, typename IndicesT>
TfLiteStatus GatherNd(const RuntimeShape& params_shape, const ParamsT* params_data,
                      const RuntimeShape& indices_shape, const IndicesT* indices_data,
                      const RuntimeShape& output_shape, ParamsT* output_data) {
  return kTfLiteOk;
}
}  // namespace reference_ops

typedef float ParamsT;
typedef int32_t IndicesT;