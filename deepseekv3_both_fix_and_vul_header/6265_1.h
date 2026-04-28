#include <stddef.h>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef struct TfLiteIntArray {
  int size;
  int data[];
} TfLiteIntArray;

typedef struct TfLiteTensor {
  TfLiteIntArray* dims;
} TfLiteTensor;

typedef struct TfLiteContext {
  TfLiteStatus (*ResizeTensor)(struct TfLiteContext*, TfLiteTensor*, TfLiteIntArray*);
} TfLiteContext;

#define TF_LITE_ENSURE(context, condition) \
  do { \
    if (!(condition)) return kTfLiteError; \
  } while (0)

TfLiteIntArray* TfLiteIntArrayCreate(int size);