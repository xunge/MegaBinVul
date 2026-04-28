#include <stddef.h>
#include <algorithm>
#include <stdint.h>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef struct TfLiteIntArray TfLiteIntArray;
typedef struct TfLiteTensor TfLiteTensor;

typedef struct TfLiteContext {
  TfLiteStatus (*ResizeTensor)(struct TfLiteContext*, TfLiteTensor*, TfLiteIntArray*);
  void (*ReportError)(struct TfLiteContext*, const char*, ...);
} TfLiteContext;

typedef struct TfLiteNode {
  void* builtin_data;
} TfLiteNode;

struct TfLiteTensor {
  union {
    int32_t* i32;
    float* f;
  } data;
  int dims_signature;
};

struct TfLiteIntArray {
  int size;
  int data[];
};

typedef enum {
  kTfLiteCombinerTypeSum,
  kTfLiteCombinerTypeMean,
  kTfLiteCombinerTypeSqrtn
} TfLiteCombinerType;

typedef struct {
  TfLiteCombinerType combiner;
} TfLiteEmbeddingLookupSparseParams;

#define TF_LITE_ENSURE_OK(context, ...) \
  do { if ((__VA_ARGS__) != kTfLiteOk) return kTfLiteError; } while (0)
#define TF_LITE_ENSURE_EQ(context, a, b) \
  do { if ((a) != (b)) return kTfLiteError; } while (0)
#define TF_LITE_ENSURE(context, condition) \
  do { if (!(condition)) return kTfLiteError; } while (0)
#define TF_LITE_ENSURE_MSG(context, condition, msg) \
  do { if (!(condition)) return kTfLiteError; } while (0)
#define TF_LITE_ENSURE_STATUS(a) \
  do { if ((a) != kTfLiteOk) return kTfLiteError; } while (0)

TfLiteIntArray* TfLiteIntArrayCreate(int size);
int SizeOfDimension(const TfLiteTensor* tensor, int dimension);
int NumDimensions(const TfLiteTensor* tensor);
TfLiteStatus GetOutputSafe(TfLiteContext* context, TfLiteNode* node, int index, TfLiteTensor** tensor);
TfLiteStatus GetInputSafe(TfLiteContext* context, TfLiteNode* node, int index, const TfLiteTensor** tensor);
TfLiteStatus MultiplyAndCheckOverflow(size_t a, size_t b, size_t* product);
void TfLiteTensorRealloc(size_t num_bytes, TfLiteTensor* tensor);
template<typename T> T* GetTensorData(TfLiteTensor* tensor);
template<typename T> const T* GetTensorData(const TfLiteTensor* tensor);
void FinalizeAggregation(TfLiteCombinerType combiner, int num_elements, float total_weight, float squares_weight, int embedding_size, float* output);