#include <stdint.h>
#include <stdbool.h>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1,
  kTfLiteDelegateError = 2,
  kTfLiteApplicationError = 3,
  kTfLiteDelegateDataNotFound = 4,
  kTfLiteDelegateDataWriteError = 5,
  kTfLiteUnresolvedOps = 6,
  kTfLiteCancelled = 7
} TfLiteStatus;

typedef enum {
  kTfLiteNoType = 0,
  kTfLiteFloat32 = 1,
  kTfLiteInt32 = 2,
  kTfLiteUInt8 = 3,
  kTfLiteInt64 = 4,
  kTfLiteString = 5,
  kTfLiteBool = 6,
  kTfLiteInt16 = 7,
  kTfLiteComplex64 = 8,
  kTfLiteInt8 = 9,
  kTfLiteFloat16 = 10,
  kTfLiteFloat64 = 11,
  kTfLiteComplex128 = 12,
  kTfLiteUInt64 = 13,
  kTfLiteResource = 14,
  kTfLiteVariant = 15,
  kTfLiteUInt32 = 16,
  kTfLiteUInt16 = 17,
  kTfLiteInt4 = 18,
} TfLiteType;

typedef struct TfLiteContext TfLiteContext;
typedef struct TfLiteIntArray {
  int size;
  int data[];
} TfLiteIntArray;

typedef struct TfLiteTensor {
  TfLiteType type;
  TfLiteIntArray* dims;
  void* data;
} TfLiteTensor;

#define TF_LITE_ENSURE_OK(context, status) (status)
#define TF_LITE_KERNEL_LOG(context, ...)

typedef int32_t IndicesT;

template<typename T>
TfLiteStatus CheckShapes(TfLiteContext* context, const TfLiteIntArray* indices_shape,
                         const TfLiteIntArray* updates_shape,
                         const TfLiteIntArray* shape_shape,
                         const T* shape_data);

template<typename T>
TfLiteStatus ResizeOutputTensor(TfLiteContext* context, const TfLiteTensor* shape,
                               TfLiteTensor* output);

template<typename IndicesT, typename DataT>
TfLiteStatus ScatterNd(const TfLiteTensor* indices, const TfLiteTensor* updates,
                       TfLiteTensor* output);

bool IsDynamicTensor(const TfLiteTensor* tensor);
const TfLiteIntArray* GetTensorShape(const TfLiteTensor* tensor);
template<typename T>
const T* GetTensorData(const TfLiteTensor* tensor);
const char* TfLiteTypeGetName(TfLiteType type);