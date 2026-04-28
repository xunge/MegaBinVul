#include <stdint.h>
#include <algorithm>
#include <stdlib.h>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef enum {
  kTfLiteCombinerTypeSum = 0,
  kTfLiteCombinerTypeMean = 1,
  kTfLiteCombinerTypeSqrtn = 2
} TfLiteCombinerType;

typedef struct {
  TfLiteCombinerType combiner;
} TfLiteEmbeddingLookupSparseParams;

typedef struct TfLiteIntArray {
  int size;
  int data[];
} TfLiteIntArray;

typedef struct TfLiteTensor {
  TfLiteIntArray* dims;
  union {
    int32_t* i32;
    float* f;
  } data;
} TfLiteTensor;

typedef struct TfLiteContext {
  TfLiteStatus (*ResizeTensor)(struct TfLiteContext*, struct TfLiteTensor*, struct TfLiteIntArray*);
  void (*ReportError)(struct TfLiteContext*, const char*, ...);
} TfLiteContext;

typedef struct TfLiteNode {
  void* builtin_data;
} TfLiteNode;

#define TF_LITE_ENSURE_OK(context, status) (status)
#define TF_LITE_ENSURE_EQ(context, a, b) (kTfLiteOk)
#define TF_LITE_ENSURE_STATUS(status) (status)
#define TF_LITE_ENSURE(context, condition) (kTfLiteOk)

static inline TfLiteStatus GetOutputSafe(TfLiteContext* context, TfLiteNode* node, int index, TfLiteTensor** tensor) {
  return kTfLiteOk;
}

static inline TfLiteStatus GetInputSafe(TfLiteContext* context, TfLiteNode* node, int index, const TfLiteTensor** tensor) {
  return kTfLiteOk;
}

static inline int SizeOfDimension(const TfLiteTensor* tensor, int dimension) {
  return tensor->dims->data[dimension];
}

static inline int NumDimensions(const TfLiteTensor* tensor) {
  return tensor->dims->size;
}

static inline TfLiteIntArray* TfLiteIntArrayCreate(int size) {
  TfLiteIntArray* ret = (TfLiteIntArray*)malloc(sizeof(TfLiteIntArray) + sizeof(int) * size);
  ret->size = size;
  return ret;
}

static inline TfLiteStatus TfLiteTensorRealloc(size_t num_bytes, TfLiteTensor* tensor) {
  return kTfLiteOk;
}

template <typename T>
static inline T* GetTensorData(TfLiteTensor* tensor) {
  return reinterpret_cast<T*>(tensor->data.f);
}

template <typename T>
static inline const T* GetTensorData(const TfLiteTensor* tensor) {
  return reinterpret_cast<const T*>(tensor->data.f);
}

static inline void FinalizeAggregation(TfLiteCombinerType combiner, int num_elements, float total_weight, float squares_weight, int embedding_size, float* output) {
}