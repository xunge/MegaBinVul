#include <stddef.h>
#include <algorithm>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

#define TF_LITE_ENSURE_OK(context, ...) (kTfLiteOk)
#define TF_LITE_ENSURE_EQ(context, a, b) (kTfLiteOk)
#define TF_LITE_ENSURE(context, condition) (kTfLiteOk)
#define TF_LITE_ENSURE_MSG(context, condition, msg) (kTfLiteOk)
#define TF_LITE_ENSURE_STATUS(status) (status)

struct TfLiteIntArray {
  int* data;
  int size;
};

struct TfLiteTensor {
  struct {
    int32_t* i32;
    float* f;
    void* data;
  } data;
  TfLiteIntArray* dims;
};

struct TfLiteNode {
  void* builtin_data;
};

struct TfLiteContext {
  TfLiteStatus (*ResizeTensor)(TfLiteContext*, TfLiteTensor*, TfLiteIntArray*);
  void (*ReportError)(TfLiteContext*, const char*, ...);
};

typedef struct {
  int combiner;
} TfLiteEmbeddingLookupSparseParams;

TfLiteIntArray* TfLiteIntArrayCreate(int size);
int SizeOfDimension(const TfLiteTensor* tensor, int dimension);
int NumDimensions(const TfLiteTensor* tensor);
int NumElements(const TfLiteTensor* tensor);
TfLiteStatus GetOutputSafe(TfLiteContext* context, TfLiteNode* node, int index, TfLiteTensor** tensor);
TfLiteStatus GetInputSafe(TfLiteContext* context, TfLiteNode* node, int index, const TfLiteTensor** tensor);
TfLiteStatus MultiplyAndCheckOverflow(size_t a, size_t b, size_t* product);
void TfLiteTensorRealloc(size_t num_bytes, TfLiteTensor* tensor);
template<typename T> T* GetTensorData(const TfLiteTensor* tensor);
void FinalizeAggregation(int combiner, int num_elements, float total_weight, float squares_weight, int embedding_size, float* output_ptr);