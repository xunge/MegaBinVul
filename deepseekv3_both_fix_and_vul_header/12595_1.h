#include <stdint.h>

typedef enum {
  kTfLiteInt64,
  kTfLiteInt32,
  // Add other necessary enum values here
} TfLiteType;

typedef enum {
  kTfLiteOk,
  kTfLiteError,
  // Add other necessary status values here
} TfLiteStatus;

struct TfLiteTensor {
  TfLiteType type;
  // Add other necessary members here
};

struct TfLiteIntArray {
  int size;
  int data[];
  // Add other necessary members here
};

struct TfLiteContext {
  TfLiteStatus (*ResizeTensor)(TfLiteContext*, TfLiteTensor*, TfLiteIntArray*);
  // Add other necessary members here
};

int NumDimensions(const TfLiteTensor* tensor);
int SizeOfDimension(const TfLiteTensor* tensor, int dim);
template<typename T> T* GetTensorData(const TfLiteTensor* tensor);
TfLiteIntArray* TfLiteIntArrayCreate(int size);
#define TF_LITE_ENSURE(context, condition) ((condition) ? kTfLiteOk : kTfLiteError)