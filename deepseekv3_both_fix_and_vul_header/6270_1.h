#include <stdint.h>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1,
  kTfLiteDelegateError = 2,
  kTfLiteApplicationError = 3,
  kTfLiteDelegateDataNotFound = 4,
  kTfLiteDelegateDataWriteError = 5,
  kTfLiteDelegateDataReadError = 6,
  kTfLiteUnresolvedOps = 7,
  kTfLiteCancelled = 8,
} TfLiteStatus;

typedef enum {
  kTfLiteLshProjectionUnknown = 0,
  kTfLiteLshProjectionSparse = 1,
  kTfLiteLshProjectionDense = 2,
} TfLiteLSHProjectionType;

typedef struct {
  TfLiteLSHProjectionType type;
} TfLiteLSHProjectionParams;

typedef struct TfLiteTensor {
  int32_t* dims;
} TfLiteTensor;

typedef struct TfLiteIntArray {
  int32_t size;
  int32_t data[1];
} TfLiteIntArray;

typedef struct TfLiteNode {
  void* builtin_data;
} TfLiteNode;

typedef struct TfLiteContext {
  TfLiteStatus (*ResizeTensor)(struct TfLiteContext*, TfLiteTensor*, TfLiteIntArray*);
} TfLiteContext;

#define TF_LITE_ENSURE(context, condition) ((condition) ? kTfLiteOk : kTfLiteError)
#define TF_LITE_ENSURE_EQ(context, x, y) ((x) == (y) ? kTfLiteOk : kTfLiteError)
#define TF_LITE_ENSURE_OK(context, status) (status)

TfLiteIntArray* TfLiteIntArrayCreate(int size);
int NumInputs(TfLiteNode* node);
int NumOutputs(TfLiteNode* node);
int NumDimensions(const TfLiteTensor* tensor);
int SizeOfDimension(const TfLiteTensor* tensor, int dim);
TfLiteStatus GetInputSafe(TfLiteContext* context, TfLiteNode* node, int index, const TfLiteTensor** tensor);
TfLiteStatus GetOutputSafe(TfLiteContext* context, TfLiteNode* node, int index, TfLiteTensor** tensor);