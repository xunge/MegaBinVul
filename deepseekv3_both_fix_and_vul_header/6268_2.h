#include <stddef.h>
#include <stdbool.h>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

struct TfLiteTensor {
  size_t bytes;
};

typedef struct TfLiteContext TfLiteContext;
typedef struct TfLiteTensor TfLiteTensor;

typedef int PositionT;

#define TF_LITE_ENSURE(ctx, condition) \
  do { if (!(condition)) return kTfLiteError; } while (0)

class DynamicBuffer {
public:
  void AddString(const char* str, size_t len);
  void WriteToTensor(TfLiteTensor* output, int* new_shape);
};

template <typename T>
const T* GetTensorData(const TfLiteTensor* tensor) {
  return reinterpret_cast<const T*>(tensor);
}

size_t GetStringCount(const TfLiteTensor* input);
int NumElements(const TfLiteTensor* tensor);

struct StringRef {
  const char* str;
  size_t len;
};

StringRef GetString(const TfLiteTensor* input, PositionT pos);