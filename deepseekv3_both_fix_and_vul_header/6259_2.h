#include <stdint.h>
#include <stdlib.h>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef enum {
  kTfLiteNoType = 0,
  kTfLiteFloat32 = 1,
  kTfLiteInt32 = 2,
  kTfLiteInt8 = 9
} TfLiteType;

typedef enum {
  kTfLiteNoQuantization = 0,
  kTfLiteAffineQuantization = 1
} TfLiteQuantizationType;

typedef enum {
  kTfLiteArenaRw = 0,
  kTfLiteArenaRwPersistent = 1
} TfLiteAllocationType;

typedef struct TfLiteFloatArray {
  int size;
  float data[1];
} TfLiteFloatArray;

typedef struct TfLiteAffineQuantization {
  TfLiteFloatArray* scale;
  int32_t* zero_point;
} TfLiteAffineQuantization;

typedef struct TfLiteQuantization {
  TfLiteQuantizationType type;
  void* params;
} TfLiteQuantization;

typedef struct TfLiteIntArray {
  int size;
  int data[1];
} TfLiteIntArray;

typedef struct TfLiteTensor {
  TfLiteType type;
  TfLiteAllocationType allocation_type;
  TfLiteIntArray* dims;
  TfLiteQuantization quantization;
} TfLiteTensor;

typedef struct TfLiteContext {
  TfLiteStatus (*ResizeTensor)(struct TfLiteContext*, TfLiteTensor*, TfLiteIntArray*);
} TfLiteContext;

typedef struct TfLiteNode {
  void* builtin_data;
  void* user_data;
  TfLiteIntArray* inputs;
  TfLiteIntArray* outputs;
  TfLiteIntArray* temporaries;
} TfLiteNode;

typedef struct TfLiteSVDFParams {
  int rank;
} TfLiteSVDFParams;

typedef struct OpData {
  int scratch_tensor_index;
  int32_t effective_scale_1_a;
  int effective_scale_1_b;
  int32_t effective_scale_2_a;
  int effective_scale_2_b;
  bool compute_row_sums;
} OpData;

#define TF_LITE_ENSURE_EQ(context, a, b) ((a) == (b) ? kTfLiteOk : kTfLiteError)
#define TF_LITE_ENSURE(context, condition) ((condition) ? kTfLiteOk : kTfLiteError)
#define TF_LITE_ENSURE_OK(context, expr) (expr)

static inline TfLiteStatus GetInputSafe(TfLiteContext* context, TfLiteNode* node, int index, const TfLiteTensor** tensor) {
  *tensor = &((TfLiteTensor*)node->inputs->data)[index];
  return kTfLiteOk;
}

static inline TfLiteStatus GetOutputSafe(TfLiteContext* context, TfLiteNode* node, int index, TfLiteTensor** tensor) {
  *tensor = &((TfLiteTensor*)node->outputs->data)[index];
  return kTfLiteOk;
}

static inline TfLiteStatus GetTemporarySafe(TfLiteContext* context, TfLiteNode* node, int index, TfLiteTensor** tensor) {
  *tensor = &((TfLiteTensor*)node->temporaries->data)[index];
  return kTfLiteOk;
}

static inline const TfLiteTensor* GetOptionalInputTensor(TfLiteContext* context, TfLiteNode* node, int index) {
  return &((TfLiteTensor*)node->inputs->data)[index];
}

static inline int NumDimensions(const TfLiteTensor* tensor) {
  return tensor->dims->size;
}

static inline int SizeOfDimension(const TfLiteTensor* tensor, int dim) {
  return tensor->dims->data[dim];
}

static inline bool TfLiteIntArrayEqual(const TfLiteIntArray* a, const TfLiteIntArray* b) {
  if (a->size != b->size) return false;
  for (int i = 0; i < a->size; ++i) {
    if (a->data[i] != b->data[i]) return false;
  }
  return true;
}

static inline bool TfLiteIntArrayEqualsArray(const TfLiteIntArray* a, int b_size, const int b_data[]) {
  if (a->size != b_size) return false;
  for (int i = 0; i < a->size; ++i) {
    if (a->data[i] != b_data[i]) return false;
  }
  return true;
}

static inline TfLiteIntArray* TfLiteIntArrayCreate(int size) {
  TfLiteIntArray* ret = (TfLiteIntArray*)malloc(sizeof(*ret) + sizeof(ret->data[0]) * size);
  ret->size = size;
  return ret;
}

static inline TfLiteIntArray* TfLiteIntArrayCopy(const TfLiteIntArray* src) {
  TfLiteIntArray* ret = TfLiteIntArrayCreate(src->size);
  for (int i = 0; i < src->size; ++i) {
    ret->data[i] = src->data[i];
  }
  return ret;
}

static inline void TfLiteIntArrayFree(TfLiteIntArray* a) {
  free(a);
}

static inline bool IsHybridOp(const TfLiteTensor* input, const TfLiteTensor* weights_feature) {
  return input->type == kTfLiteFloat32 && weights_feature->type == kTfLiteInt8;
}

static inline void QuantizeMultiplier(double scale, int32_t* quantized_multiplier, int* shift) {
  *quantized_multiplier = 1;
  *shift = 0;
}

enum {
  kInputTensor = 0,
  kWeightsFeatureTensor = 1,
  kWeightsTimeTensor = 2,
  kBiasTensor = 3,
  kStateTensor = 4,
  kOutputTensor = 0
};