#include <stdint.h>

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

struct TfLiteContext {
  void (*ReportError)(struct TfLiteContext*, const char*, ...);
};

struct TfLiteTensor {
  TfLiteType type;
};

struct TfLiteNode {};

#define TF_LITE_ENSURE_OK(context, status) (status)
#define TF_LITE_ENSURE(context, condition) (condition)

#define kParams 0
#define kIndices 1
#define kOutputTensor 0

const char* TfLiteTypeGetName(TfLiteType type);

TfLiteStatus GetInputSafe(TfLiteContext* context, TfLiteNode* node, int index, const TfLiteTensor** tensor);
TfLiteStatus GetOutputSafe(TfLiteContext* context, TfLiteNode* node, int index, TfLiteTensor** tensor);
int NumElements(const TfLiteTensor* tensor);

template <typename T>
TfLiteStatus EvalGatherNd(TfLiteContext* context, const TfLiteTensor* params, const TfLiteTensor* indices, TfLiteTensor* output);