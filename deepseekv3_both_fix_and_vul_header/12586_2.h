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
  kTfLiteCancelled = 7,
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
} TfLiteType;

typedef struct TfLiteIntArray {
  int size;
  int data[];
} TfLiteIntArray;

typedef struct TfLiteTensor {
  TfLiteType type;
  TfLiteIntArray* dims;
} TfLiteTensor;

typedef struct TfLiteNode {
  void* builtin_data;
} TfLiteNode;

typedef struct TfLiteContext {
  TfLiteStatus (*ResizeTensor)(struct TfLiteContext*, TfLiteTensor*, TfLiteIntArray*);
} TfLiteContext;

typedef struct {
  int block_size;
} TfLiteDepthToSpaceParams;

#define TF_LITE_ENSURE_EQ(context, a, b) ((a) == (b) ? kTfLiteOk : kTfLiteError)
#define TF_LITE_ENSURE(context, condition) ((condition) ? kTfLiteOk : kTfLiteError)
#define TF_LITE_ENSURE_TYPES_EQ(context, a, b) ((a) == (b) ? kTfLiteOk : kTfLiteError)
#define TF_LITE_ENSURE_OK(context, status) (status)

#define kInputTensor 0
#define kOutputTensor 0

static inline int NumInputs(TfLiteNode* node) { return 0; }
static inline int NumOutputs(TfLiteNode* node) { return 0; }
static inline int NumDimensions(const TfLiteTensor* tensor) { return 0; }
static inline TfLiteStatus GetInputSafe(TfLiteContext* context, TfLiteNode* node, int index, const TfLiteTensor** tensor) { return kTfLiteOk; }
static inline TfLiteStatus GetOutputSafe(TfLiteContext* context, TfLiteNode* node, int index, TfLiteTensor** tensor) { return kTfLiteOk; }
static inline TfLiteIntArray* TfLiteIntArrayCreate(int size) { return NULL; }