#include <stdint.h>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError
} TfLiteStatus;

namespace reference_ops {
template <typename IndicesT, typename UpdatesT>
TfLiteStatus ScatterNd(const int* indices_shape, const IndicesT* indices_data,
                       const int* updates_shape, const UpdatesT* updates_data,
                       const int* output_shape, UpdatesT* output_data);
}  // namespace reference_ops

struct TfLiteTensor {
  const int* dims;
  const void* data;
};

template <typename T>
const T* GetTensorData(const TfLiteTensor* tensor) {
  return static_cast<const T*>(tensor->data);
}

template <typename T>
T* GetTensorData(TfLiteTensor* tensor) {
  return static_cast<T*>(const_cast<void*>(tensor->data));
}

const int* GetTensorShape(const TfLiteTensor* tensor) {
  return tensor->dims;
}

typedef int32_t IndicesT;
typedef float UpdatesT;