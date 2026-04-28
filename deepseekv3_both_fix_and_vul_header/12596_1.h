#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef enum {
  kTfLiteString = 4
} TfLiteType;

typedef struct TfLiteContext TfLiteContext;
typedef struct TfLiteNode TfLiteNode;

typedef struct {
  union {
    uint8_t* uint8;
    int32_t* i32;
    char* raw;
  } data;
  int bytes;
  TfLiteType type;
} TfLiteTensor;

typedef struct DynamicBuffer DynamicBuffer;

#define TF_LITE_ENSURE_OK(context, status) (status)
#define TF_LITE_ENSURE(context, condition) (condition)

static inline TfLiteStatus GetOutputSafe(TfLiteContext* context, TfLiteNode* node, int index, TfLiteTensor** tensor) {
  return kTfLiteOk;
}

static inline TfLiteStatus GetInputSafe(TfLiteContext* context, TfLiteNode* node, int index, const TfLiteTensor** tensor) {
  return kTfLiteOk;
}

static inline int SizeOfDimension(const TfLiteTensor* tensor, int dimension) {
  return 0;
}

static int greater(const void* a, const void* b) {
  return 0;
}

struct DynamicBuffer {
  void AddString(const char* str, size_t len) {}
  void AddString(const struct TfLiteString* str) {}
  void WriteToTensorAsVector(TfLiteTensor* tensor) {}
};

static inline const struct TfLiteString* GetString(const TfLiteTensor* tensor, int index) {
  return nullptr;
}

struct TfLiteString {};