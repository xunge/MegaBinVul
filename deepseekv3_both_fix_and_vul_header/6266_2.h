#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef enum {
  kTfLiteNoType = 0,
  kTfLiteFloat32,
  kTfLiteUInt8,
  kTfLiteInt8,
  kTfLiteInt16,
  kTfLiteInt32,
  kTfLiteInt64,
  kTfLiteString,
} TfLiteType;

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef struct TfLiteContext {
  void (*ReportError)(struct TfLiteContext*, const char*, ...);
} TfLiteContext;

typedef struct TfLiteTensor {
  TfLiteType type;
  size_t bytes;
  void* data;
} TfLiteTensor;

template <typename T>
const T* GetTensorData(const TfLiteTensor* tensor) {
  return static_cast<const T*>(tensor->data);
}

template <typename DataT, typename IndicesT>
TfLiteStatus GatherNd(const TfLiteTensor* params, const TfLiteTensor* indices, TfLiteTensor* output);

template <typename IndicesT>
TfLiteStatus GatherNdString(const TfLiteTensor* params, const TfLiteTensor* indices, TfLiteTensor* output);

const char* TfLiteTypeGetName(TfLiteType type);

#define TF_LITE_ENSURE(ctx, condition) \
  do { \
    if (!(condition)) return kTfLiteError; \
  } while (0)

typedef int32_t IndicesT;