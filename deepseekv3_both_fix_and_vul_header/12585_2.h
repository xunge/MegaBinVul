#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1,
} TfLiteStatus;

typedef enum {
  kTfLiteFloat32 = 1,
  kTfLiteUInt8 = 3,
  kTfLiteInt8 = 9,
  kTfLiteInt32 = 2,
  kTfLiteInt64 = 4,
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
  TfLiteStatus (*ResizeTensor)(TfLiteContext*, TfLiteTensor*, TfLiteIntArray*);
} TfLiteContext;

typedef struct TfLiteDepthToSpaceParams {
  int block_size;
} TfLiteDepthToSpaceParams;

#define TF_LITE_ENSURE_EQ(context, a, b) ((a) == (b) ? kTfLiteOk : kTfLiteError)
#define TF_LITE_ENSURE(context, condition) ((condition) ? kTfLiteOk : kTfLiteError)
#define TF_LITE_ENSURE_TYPES_EQ(context, a, b) ((a) == (b) ? kTfLiteOk : kTfLiteError)
#define TF_LITE_ENSURE_OK(context, status) (status)

#define kInputTensor 0
#define kOutputTensor 0

static inline int NumInputs(const TfLiteNode* node) { return 1; }
static inline int NumOutputs(const TfLiteNode* node) { return 1; }
static inline int NumDimensions(const TfLiteTensor* tensor) { return 4; }
static inline TfLiteStatus GetInputSafe(TfLiteContext* context, TfLiteNode* node, int index, const TfLiteTensor** tensor) { return kTfLiteOk; }
static inline TfLiteStatus GetOutputSafe(TfLiteContext* context, TfLiteNode* node, int index, TfLiteTensor** tensor) { return kTfLiteOk; }
static inline TfLiteIntArray* TfLiteIntArrayCreate(int size) { 
  TfLiteIntArray* arr = (TfLiteIntArray*)malloc(sizeof(TfLiteIntArray) + size * sizeof(int));
  arr->size = size;
  return arr;
}