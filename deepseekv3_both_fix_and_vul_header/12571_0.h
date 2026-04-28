#include <stdint.h>
#include <stdlib.h>
#include <math.h>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1,
  kTfLiteDelegateError = 2,
  kTfLiteApplicationError = 3,
  kTfLiteDelegateDataNotFound = 4,
  kTfLiteDelegateDataWriteError = 5,
  kTfLiteUnresolvedOps = 6,
  kTfLiteCancelled = 7,
} TfLiteStatus;

typedef enum {
  kTfLiteNoPadding = 0,
  kTfLiteSamePadding = 1,
  kTfLiteValidPadding = 2,
} TfLitePadding;

typedef enum {
  kTfLiteFloat32 = 0,
  kTfLiteInt32 = 1,
  kTfLiteUInt8 = 2,
  kTfLiteInt64 = 3,
  kTfLiteString = 4,
  kTfLiteBool = 5,
  kTfLiteInt16 = 6,
  kTfLiteComplex64 = 7,
  kTfLiteInt8 = 8,
  kTfLiteFloat16 = 9,
  kTfLiteFloat64 = 10,
  kTfLiteComplex128 = 11,
  kTfLiteUInt64 = 12,
} TfLiteType;

typedef struct TfLiteIntArray {
  int size;
  int data[1];
} TfLiteIntArray;

typedef struct TfLiteTensor {
  TfLiteType type;
  TfLiteIntArray* dims;
  struct {
    float scale;
    int32_t zero_point;
  } params;
} TfLiteTensor;

typedef struct TfLiteContext {
  TfLiteStatus (*ResizeTensor)(struct TfLiteContext*, TfLiteTensor*, TfLiteIntArray*);
} TfLiteContext;

typedef struct TfLiteNode {
  void* builtin_data;
  void* user_data;
} TfLiteNode;

typedef struct TfLitePoolParams {
  TfLitePadding padding;
  int stride_width;
  int stride_height;
  int filter_width;
  int filter_height;
} TfLitePoolParams;

typedef struct OpData {
  int padding;
} OpData;

typedef enum {
  kAverage,
  kMax,
  kL2
} PoolType;

PoolType pool_type;

#define TF_LITE_ENSURE_EQ(context, a, b) ((a == b) ? kTfLiteOk : kTfLiteError)
#define TF_LITE_ENSURE(context, cond) ((cond) ? kTfLiteOk : kTfLiteError)
#define TF_LITE_ENSURE_TYPES_EQ(context, a, b) ((a == b) ? kTfLiteOk : kTfLiteError)
#define TF_LITE_ENSURE_OK(context, status) (status)
#define TFLITE_DCHECK_LE(a, b)
#define TFLITE_DCHECK_EQ(a, b)

int NumInputs(TfLiteNode* node);
int NumOutputs(TfLiteNode* node);
int NumDimensions(const TfLiteTensor* tensor);
TfLiteStatus GetOutputSafe(TfLiteContext* context, TfLiteNode* node, int index, TfLiteTensor** tensor);
TfLiteStatus GetInputSafe(TfLiteContext* context, TfLiteNode* node, int index, const TfLiteTensor** tensor);
TfLiteIntArray* TfLiteIntArrayCreate(int size);
int ComputePaddingHeightWidth(int stride_height, int stride_width, int dilation_rate_height, int dilation_rate_width, int in_height, int in_width, int filter_height, int filter_width, TfLitePadding padding, int* out_height, int* out_width);