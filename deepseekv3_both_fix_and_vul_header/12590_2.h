#include <stdint.h>
#include <stddef.h>
#include <cstdlib>
#include <cstring>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef struct TfLiteContext {
  TfLiteStatus (*ResizeTensor)(struct TfLiteContext*, struct TfLiteTensor*, struct TfLiteIntArray*);
} TfLiteContext;

typedef struct TfLiteNode {
  int outputs;
} TfLiteNode;

typedef struct TfLiteIntArray {
  int size;
  int data[];
} TfLiteIntArray;

typedef struct TfLiteTensor {
  TfLiteIntArray* dims;
} TfLiteTensor;

#define TF_LITE_ENSURE(context, condition) ((condition) ? kTfLiteOk : kTfLiteError)
#define TF_LITE_ENSURE_MSG(context, condition, msg) ((condition) ? kTfLiteOk : kTfLiteError)
#define TF_LITE_ENSURE_OK(context, status) (status)
#define TF_LITE_ENSURE_STATUS(status) (status)

static inline int NumDimensions(const TfLiteTensor* tensor) { return tensor->dims->size; }
static inline int SizeOfDimension(const TfLiteTensor* tensor, int dim) { return tensor->dims->data[dim]; }
static inline int NumOutputs(const TfLiteNode* node) { return node->outputs; }
static inline TfLiteIntArray* TfLiteIntArrayCopy(const TfLiteIntArray* src) { 
  TfLiteIntArray* copy = (TfLiteIntArray*)malloc(sizeof(TfLiteIntArray) + src->size * sizeof(int));
  copy->size = src->size;
  memcpy(copy->data, src->data, src->size * sizeof(int));
  return copy;
}
static inline TfLiteStatus GetOutputSafe(TfLiteContext* context, TfLiteNode* node, int index, TfLiteTensor** tensor) { return kTfLiteOk; }
template<typename T> static inline const T* GetTensorData(const TfLiteTensor* tensor) { return NULL; }