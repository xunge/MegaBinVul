#include <stdint.h>
#include <stdlib.h>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1,
  kTfLiteDelegateError = 2,
  kTfLiteApplicationError = 3,
  kTfLiteDelegateDataNotFound = 4,
  kTfLiteDelegateDataWriteError = 5,
  kTfLiteUnresolvedOps = 6,
  kTfLiteCancelled = 7
} TfLiteStatus;

typedef enum {
  kTfLiteNoType = 0,
  kTfLiteFloat32 = 1,
  kTfLiteInt32 = 2,
  kTfLiteUInt8 = 3,
  kTfLiteInt64 = 4,
  kTfLiteString = 5,
  kTfLiteBool = 6,
  kTfLiteInt16 = 7,
  kTfLiteComplex64 = 8,
  kTfLiteInt8 = 9,
  kTfLiteFloat16 = 10,
  kTfLiteFloat64 = 11,
  kTfLiteComplex128 = 12,
  kTfLiteUInt64 = 13,
  kTfLiteResource = 14,
  kTfLiteVariant = 15,
  kTfLiteUInt32 = 16,
  kTfLiteUInt16 = 17,
  kTfLiteInt4 = 18
} TfLiteType;

typedef enum {
  kTfLiteFullyConnectedWeightsFormatDefault = 0,
  kTfLiteFullyConnectedWeightsFormatShuffled4x16Int8 = 1
} TfLiteFullyConnectedWeightsFormat;

typedef enum {
  kTfLiteActNone = 0,
  kTfLiteActRelu = 1,
  kTfLiteActReluN1To1 = 2,
  kTfLiteActRelu6 = 3,
  kTfLiteActTanh = 4,
  kTfLiteActSignBit = 5,
  kTfLiteActSigmoid = 6
} TfLiteFusedActivation;

typedef enum {
  kTfLiteMemNone = 0,
  kTfLiteMmapRo = 1,
  kTfLiteArenaRw = 2,
  kTfLiteArenaRwPersistent = 3,
  kTfLiteDynamic = 4,
  kTfLitePersistentRo = 5,
  kTfLiteCustom = 6
} TfLiteAllocationType;

typedef struct TfLiteQuantizationParams {
  float scale;
  int32_t zero_point;
} TfLiteQuantizationParams;

typedef struct TfLiteIntArray {
  int size;
  int data[1];
} TfLiteIntArray;

typedef struct TfLiteTensor {
  TfLiteType type;
  TfLiteIntArray* dims;
  void* data;
  TfLiteQuantizationParams params;
  void* sparsity;
  TfLiteAllocationType allocation_type;
} TfLiteTensor;

typedef struct TfLiteContext {
  TfLiteTensor* tensors;
  TfLiteStatus (*ResizeTensor)(struct TfLiteContext*, TfLiteTensor*, TfLiteIntArray*);
} TfLiteContext;

typedef struct TfLiteNode {
  void* builtin_data;
  void* user_data;
  TfLiteIntArray* inputs;
  TfLiteIntArray* outputs;
  TfLiteIntArray* temporaries;
} TfLiteNode;

typedef struct TfLiteFullyConnectedParams {
  TfLiteFusedActivation activation;
  TfLiteFullyConnectedWeightsFormat weights_format;
  int keep_num_dims;
} TfLiteFullyConnectedParams;

typedef struct OpData {
  int scratch_tensor_index;
  int output_multiplier;
  int output_shift;
  int output_activation_min;
  int output_activation_max;
  bool compute_row_sums;
  bool ledger_initialized;
} OpData;

#define TF_LITE_ENSURE(context, condition) \
  do {                                     \
    if (!(condition)) return kTfLiteError; \
  } while (0)

#define TF_LITE_ENSURE_EQ(context, a, b) TF_LITE_ENSURE(context, (a) == (b))

#define TF_LITE_ENSURE_OK(context, status) \
  do {                                     \
    if ((status) != kTfLiteOk) return status; \
  } while (0)

#define TF_LITE_ENSURE_STATUS(status) \
  do {                               \
    if ((status) != kTfLiteOk) return status; \
  } while (0)

#define kInputTensor 0
#define kWeightsTensor 1
#define kBiasTensor 2
#define kOutputTensor 0

static inline int NumDimensions(const TfLiteTensor* t) {
  return t->dims->size;
}

static inline int SizeOfDimension(const TfLiteTensor* t, int dim) {
  return t->dims->data[dim];
}

static inline int NumElements(const TfLiteTensor* t) {
  int num_elements = 1;
  for (int i = 0; i < t->dims->size; ++i) {
    num_elements *= t->dims->data[i];
  }
  return num_elements;
}

static inline TfLiteStatus GetInputSafe(const TfLiteContext* context,
                                      const TfLiteNode* node, int index,
                                      const TfLiteTensor** tensor) {
  *tensor = &context->tensors[node->inputs->data[index]];
  return kTfLiteOk;
}

static inline TfLiteStatus GetOutputSafe(const TfLiteContext* context,
                                       const TfLiteNode* node, int index,
                                       TfLiteTensor** tensor) {
  *tensor = &context->tensors[node->outputs->data[index]];
  return kTfLiteOk;
}

static inline TfLiteStatus GetTemporarySafe(const TfLiteContext* context,
                                          const TfLiteNode* node, int index,
                                          TfLiteTensor** tensor) {
  *tensor = &context->tensors[node->temporaries->data[index]];
  return kTfLiteOk;
}

static inline const TfLiteTensor* GetOptionalInputTensor(
    const TfLiteContext* context, const TfLiteNode* node, int index) {
  return index < 0 ? nullptr : &context->tensors[node->inputs->data[index]];
}

static inline TfLiteIntArray* TfLiteIntArrayCreate(int size) {
  TfLiteIntArray* ret = (TfLiteIntArray*)malloc(sizeof(*ret) + sizeof(ret->data[0]) * (size - 1));
  ret->size = size;
  return ret;
}

static inline void TfLiteIntArrayFree(TfLiteIntArray* a) {
  free(a);
}

static inline bool TfLiteIntArrayEqualsArray(const TfLiteIntArray* a, int b_size,
                                           const int b_data[]) {
  if (a == NULL) return false;
  if (a->size != b_size) return false;
  for (int i = 0; i < a->size; i++) {
    if (a->data[i] != b_data[i]) return false;
  }
  return true;
}

static inline TfLiteIntArray* TfLiteIntArrayCopy(const TfLiteIntArray* src) {
  if (!src) return NULL;
  TfLiteIntArray* ret = TfLiteIntArrayCreate(src->size);
  for (int i = 0; i < ret->size; i++) {
    ret->data[i] = src->data[i];
  }
  return ret;
}

static TfLiteStatus CheckTypes(const TfLiteContext* context,
                              const TfLiteTensor* input,
                              const TfLiteTensor* filter,
                              const TfLiteTensor* bias,
                              const TfLiteTensor* output,
                              const TfLiteFullyConnectedParams* params) {
  return kTfLiteOk;
}

static TfLiteStatus GetQuantizedConvolutionMultipler(
    const TfLiteContext* context, const TfLiteTensor* input,
    const TfLiteTensor* filter, const TfLiteTensor* bias,
    const TfLiteTensor* output, double* real_multiplier) {
  return kTfLiteOk;
}

static void QuantizeMultiplier(double double_multiplier, int32_t* quantized_multiplier,
                             int* shift) {
}

static TfLiteStatus CalculateActivationRangeQuantized(
    const TfLiteContext* context, TfLiteFusedActivation activation,
    const TfLiteTensor* output, int32_t* activation_min,
    int32_t* activation_max) {
  return kTfLiteOk;
}

static TfLiteStatus CreateLedgerTensor(void* sparsity, TfLiteContext* context,
                                     TfLiteTensor* ledger) {
  return kTfLiteOk;
}