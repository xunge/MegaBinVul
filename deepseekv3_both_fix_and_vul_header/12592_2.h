#include <stdint.h>

typedef enum {
  kTfLiteOk = 0,
} TfLiteStatus;

typedef enum {
  kTfLiteActNone = 0,
} TfLiteFusedActivation;

typedef enum {
  kTfLiteFloat32 = 0,
  kTfLiteUInt8 = 2,
  kTfLiteInt8 = 3,
  kTfLiteInt16 = 4,
  kTfLiteInt32 = 5,
  kTfLiteInt64 = 6,
  kTfLiteBool = 7,
} TfLiteType;

typedef struct TfLiteIntArray {
  int size;
  int data[];
} TfLiteIntArray;

typedef struct TfLiteQuantizationParams {
  float scale;
  int32_t zero_point;
} TfLiteQuantizationParams;

typedef struct TfLiteTensor {
  TfLiteType type;
  TfLiteIntArray* dims;
  TfLiteQuantizationParams params;
} TfLiteTensor;

typedef struct TfLiteNode {
  void* builtin_data;
  TfLiteIntArray* inputs;
  TfLiteIntArray* outputs;
} TfLiteNode;

typedef struct TfLiteContext {
  TfLiteStatus (*ResizeTensor)(struct TfLiteContext*, TfLiteTensor*, TfLiteIntArray*);
} TfLiteContext;

typedef struct TfLiteConcatenationParams {
  int axis;
  TfLiteFusedActivation activation;
} TfLiteConcatenationParams;

#define TF_LITE_ENSURE_EQ(context, a, b) kTfLiteOk
#define TF_LITE_ENSURE(context, condition) kTfLiteOk
#define TF_LITE_ENSURE_OK(context, status) kTfLiteOk
#define TF_LITE_ENSURE_TYPES_EQ(context, a, b) kTfLiteOk

TfLiteStatus GetInputSafe(TfLiteContext* context, TfLiteNode* node, int index, const TfLiteTensor** tensor);
TfLiteStatus GetOutputSafe(TfLiteContext* context, TfLiteNode* node, int index, TfLiteTensor** tensor);
const TfLiteTensor* GetInput(TfLiteContext* context, TfLiteNode* node, int index);
TfLiteIntArray* TfLiteIntArrayCreate(int size);

template <typename T>
struct VectorOfTensors {
  VectorOfTensors(TfLiteContext& context, TfLiteIntArray& inputs) {}
};