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
  kTfLiteString
} TfLiteType;

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef struct TfLiteContext TfLiteContext;

typedef struct TfLiteTensor {
  TfLiteType type;
  size_t bytes;
} TfLiteTensor;

#define TF_LITE_ENSURE(ctx, condition) ((condition) ? kTfLiteOk : kTfLiteError)
#define TF_LITE_KERNEL_LOG(ctx, ...)

const char* TfLiteTypeGetName(TfLiteType type);

template <typename T>
const T* GetTensorData(const TfLiteTensor* tensor);

template <typename T, typename IndicesT>
TfLiteStatus GatherNd(TfLiteContext* context, const TfLiteTensor* params,
                      const TfLiteTensor* indices, TfLiteTensor* output);

template <typename T, typename IndicesT>
TfLiteStatus GatherNd(const TfLiteTensor* params,
                      const TfLiteTensor* indices, TfLiteTensor* output);

template <typename IndicesT>
TfLiteStatus GatherNdString(const TfLiteTensor* params,
                            const TfLiteTensor* indices, TfLiteTensor* output);

template <typename IndicesT>
TfLiteStatus EvalGatherNd(TfLiteContext* context, const TfLiteTensor* params,
                          const TfLiteTensor* indices, TfLiteTensor* output);

typedef int32_t IndicesT;