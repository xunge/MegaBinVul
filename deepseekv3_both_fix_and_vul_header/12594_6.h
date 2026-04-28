#include <stdint.h>

typedef enum {
  kTfLiteOk = 0,
} TfLiteStatus;

typedef struct TfLiteContext TfLiteContext;
typedef struct TfLiteTensor TfLiteTensor;

typedef int16_t int16;

int SizeOfDimension(const TfLiteTensor* tensor, int dimension);

#define TF_LITE_ENSURE_EQ(context, a, b) /* implementation would go here */