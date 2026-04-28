#include <stdint.h>
#include <stddef.h>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1,
  kTfLiteDelegateError = 2,
  kTfLiteApplicationError = 3,
  kTfLiteDelegateDataNotFound = 4,
  kTfLiteDelegateDataWriteError = 5,
  kTfLiteUnresolvedOps = 6,
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
  kTfLiteInt8 = 8,
} TfLiteType;

struct TfLiteContext {
  void (*ReportError)(TfLiteContext*, const char*, ...);
};

struct TfLiteNode {
  void* builtin_data;
};

struct TfLiteTensor {
  TfLiteType type;
};

struct TfLiteGatherParams {
  int axis;
};

#define TF_LITE_ENSURE_OK(context, status) (status)

#define kInputTensor 0
#define kInputPositions 1
#define kOutputTensor 0

const char* TfLiteTypeGetName(TfLiteType type);

TfLiteStatus GetInputSafe(TfLiteContext* context, TfLiteNode* node, int index, const TfLiteTensor** tensor);
TfLiteStatus GetOutputSafe(TfLiteContext* context, TfLiteNode* node, int index, TfLiteTensor** tensor);

template <typename T, typename P>
TfLiteStatus Gather(TfLiteContext* context, const TfLiteGatherParams& params, const TfLiteTensor* input, const TfLiteTensor* positions, TfLiteTensor* output);

template <typename T, typename P>
TfLiteStatus Gather(const TfLiteGatherParams& params, const TfLiteTensor* input, const TfLiteTensor* positions, TfLiteTensor* output);

template <typename P>
TfLiteStatus GatherStrings(TfLiteContext* context, const TfLiteTensor* input, const TfLiteTensor* positions, TfLiteTensor* output);