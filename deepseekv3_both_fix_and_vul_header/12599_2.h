#include <stdint.h>
#include <vector>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef enum {
  kTfLiteInt32 = 3,
  kTfLiteInt64 = 4
} TfLiteType;

typedef struct TfLiteContext {
  void (*ReportError)(struct TfLiteContext*, const char*);
  TfLiteStatus (*ResizeTensor)(struct TfLiteContext*, struct TfLiteTensor*, struct TfLiteIntArray*);
} TfLiteContext;

typedef struct TfLiteNode {
  int (*NumOutputs)(const struct TfLiteNode*);
} TfLiteNode;

typedef struct TfLiteTensor {
  TfLiteType type;
  struct TfLiteIntArray* dims;
} TfLiteTensor;

typedef struct TfLiteIntArray {
  int size;
  int data[];
} TfLiteIntArray;

template<typename T>
T* GetTensorData(const TfLiteTensor* tensor) { return nullptr; }

template<typename T>
void GetSizeSplitsVector(const TfLiteTensor* size_splits, std::vector<int64_t>* size_splits_vector) {}

int NumDimensions(const TfLiteTensor* tensor) { return 0; }
int SizeOfDimension(const TfLiteTensor* tensor, int axis) { return 0; }
int NumOutputs(const TfLiteNode* node) { return 0; }
TfLiteIntArray* TfLiteIntArrayCopy(const TfLiteIntArray* src) { return nullptr; }
TfLiteStatus GetOutputSafe(TfLiteContext* context, TfLiteNode* node, int index, TfLiteTensor** tensor) { return kTfLiteOk; }

#define TF_LITE_ENSURE(context, condition) \
  do { \
    if (!(condition)) { \
      return kTfLiteError; \
    } \
  } while (0)

#define TF_LITE_ENSURE_OK(context, status) \
  do { \
    if ((status) != kTfLiteOk) { \
      return kTfLiteError; \
    } \
  } while (0)

#define TF_LITE_ENSURE_STATUS(status) \
  do { \
    if ((status) != kTfLiteOk) { \
      return kTfLiteError; \
    } \
  } while (0)