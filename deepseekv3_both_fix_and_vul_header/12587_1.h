#include <stdint.h>
#include <cstring>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef struct TfLiteContext {
  void (*ReportError)(struct TfLiteContext*, const char*, ...);
} TfLiteContext;

typedef struct TfLiteNode {
} TfLiteNode;

typedef struct TfLiteTensor {
  int bytes;
} TfLiteTensor;

template <typename T>
T* GetTensorData(const TfLiteTensor* tensor) {
  return nullptr;
}

int SizeOfDimension(const TfLiteTensor* tensor, int dimension) {
  return 0;
}