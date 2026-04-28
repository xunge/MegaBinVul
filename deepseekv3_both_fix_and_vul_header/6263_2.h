#include <stdint.h>
#include <stdlib.h>
#include <vector>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1,
  kTfLiteDelegateError = 2,
  kTfLiteApplicationError = 3,
  kTfLiteDelegateDataNotFound = 4,
  kTfLiteDelegateDataWriteError = 5,
  kTfLiteUnresolvedOps = 6,
  kTfLiteCancelled = 7,
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
} TfLiteType;

typedef enum {
  kTfLiteNoQuantization = 0,
  kTfLiteAffineQuantization = 1,
} TfLiteQuantizationType;

typedef enum {
  kTfLitePaddingUnknown = 0,
  kTfLitePaddingSame = 1,
  kTfLitePaddingValid = 2,
} TfLitePadding;

typedef enum {
  kTfLiteActNone = 0,
  kTfLiteActRelu = 1,
  kTfLiteActReluN1To1 = 2,
  kTfLiteActRelu6 = 3,
  kTfLiteActTanh = 4,
  kTfLiteActSignBit = 5,
  kTfLiteActSigmoid = 6,
} TfLiteFusedActivation;

typedef enum {
  kTfLiteMemNone = 0,
  kTfLiteMmapRw = 1,
  kTfLiteArenaRw = 2,
  kTfLiteArenaRwPersistent = 3,
  kTfLiteDynamic = 4,
} TfLiteAllocationType;

typedef struct TfLiteContext TfLiteContext;
typedef struct TfLiteNode TfLiteNode;
typedef struct TfLiteTensor TfLiteTensor;
typedef struct TfLiteIntArray TfLiteIntArray;
typedef struct TfLiteFloatArray TfLiteFloatArray;
typedef struct TfLiteAffineQuantization TfLiteAffineQuantization;

struct TfLiteIntArray {
  int size;
  int data[1];
};

struct TfLiteFloatArray {
  int size;
  float data[1];
};

struct TfLiteAffineQuantization {
  TfLiteFloatArray* scale;
  TfLiteIntArray* zero_point;
  int32_t quantized_dimension;
};

typedef struct {
  TfLiteQuantizationType type;
  void* params;
} TfLiteQuantization;

typedef struct {
  float scale;
  int32_t zero_point;
} TfLiteQuantizationParams;

struct TfLiteTensor {
  TfLiteType type;
  TfLiteQuantizationParams params;
  TfLiteQuantization quantization;
  TfLiteIntArray* dims;
  int32_t* data;
  TfLiteAllocationType allocation_type;
};

typedef struct {
  TfLitePadding padding;
  int stride_width;
  int stride_height;
  int dilation_width_factor;
  int dilation_height_factor;
  TfLiteFusedActivation activation;
} TfLiteDepthwiseConvParams;

struct TfLiteNode {
  void* builtin_data;
  void* user_data;
  TfLiteIntArray* inputs;
  TfLiteIntArray* outputs;
  TfLiteIntArray* temporaries;
};

struct TfLiteContext {
  TfLiteStatus (*ResizeTensor)(TfLiteContext*, TfLiteTensor*, TfLiteIntArray*);
  TfLiteStatus (*AddTensors)(TfLiteContext*, int, int*);
  TfLiteTensor* (*GetTensor)(const TfLiteContext*, int);
  TfLiteIntArray* (*GetExecutionPlan)(TfLiteContext*);
};

typedef struct {
  int padding;
  int output_multiplier;
  int output_shift;
  int output_activation_min;
  int output_activation_max;
  int input_quantized_id;
  int scaling_factors_id;
  int input_offset_id;
  int input_quantized_index;
  int scaling_factors_index;
  int input_offset_index;
  std::vector<int32_t> per_channel_output_multiplier;
  std::vector<int32_t> per_channel_output_shift;
} OpData;

#define kInputTensor 0
#define kFilterTensor 1
#define kBiasTensor 2
#define kOutputTensor 0
#define kTensorNotAllocated -1
#define TF_LITE_ENSURE_STATUS(x) if ((x) != kTfLiteOk) return kTfLiteError;

static inline int NumInputs(const TfLiteNode* node) { return node->inputs->size; }
static inline int NumOutputs(const TfLiteNode* node) { return node->outputs->size; }
static inline int NumDimensions(const TfLiteTensor* tensor) { return tensor->dims->size; }
static inline int SizeOfDimension(const TfLiteTensor* tensor, int dim) { return tensor->dims->data[dim]; }

#define TF_LITE_ENSURE(context, condition) \
  if (!(condition)) return kTfLiteError;

#define TF_LITE_ENSURE_EQ(context, a, b) \
  if ((a) != (b)) return kTfLiteError;

#define TF_LITE_ENSURE_TYPES_EQ(context, a, b) \
  if ((a) != (b)) return kTfLiteError;

#define TF_LITE_ENSURE_OK(context, status) \
  if ((status) != kTfLiteOk) return status;

static inline TfLiteStatus GetInputSafe(const TfLiteContext* context, const TfLiteNode* node, int index, const TfLiteTensor** tensor) {
  *tensor = context->GetTensor(context, node->inputs->data[index]);
  return kTfLiteOk;
}

static inline TfLiteStatus GetOutputSafe(const TfLiteContext* context, const TfLiteNode* node, int index, TfLiteTensor** tensor) {
  *tensor = context->GetTensor(context, node->outputs->data[index]);
  return kTfLiteOk;
}

static inline TfLiteStatus GetTemporarySafe(const TfLiteContext* context, const TfLiteNode* node, int index, TfLiteTensor** tensor) {
  *tensor = context->GetTensor(context, node->temporaries->data[index]);
  return kTfLiteOk;
}

static inline TfLiteIntArray* TfLiteIntArrayCreate(int size) {
  TfLiteIntArray* ret = (TfLiteIntArray*)malloc(sizeof(*ret) + sizeof(ret->data[0]) * (size - 1));
  ret->size = size;
  return ret;
}

static inline void TfLiteIntArrayFree(TfLiteIntArray* a) { free(a); }

static inline bool TfLiteIntArrayEqual(const TfLiteIntArray* a, const TfLiteIntArray* b) {
  if (a == b) return true;
  if (a == NULL || b == NULL) return false;
  if (a->size != b->size) return false;
  for (int i = 0; i < a->size; ++i) {
    if (a->data[i] != b->data[i]) return false;
  }
  return true;
}

static inline bool TfLiteIntArrayEqualsArray(const TfLiteIntArray* a, int b_size, const int b_data[]) {
  if (a == NULL) return false;
  if (a->size != b_size) return false;
  for (int i = 0; i < a->size; ++i) {
    if (a->data[i] != b_data[i]) return false;
  }
  return true;
}

static inline TfLiteIntArray* TfLiteIntArrayCopy(const TfLiteIntArray* src) {
  if (!src) return NULL;
  TfLiteIntArray* ret = TfLiteIntArrayCreate(src->size);
  for (int i = 0; i < src->size; ++i) {
    ret->data[i] = src->data[i];
  }
  return ret;
}

static inline int ComputePaddingHeightWidth(int stride_height, int stride_width,
                                          int dilation_height_factor, int dilation_width_factor,
                                          int in_height, int in_width, int filter_height,
                                          int filter_width, TfLitePadding padding,
                                          int* out_height, int* out_width) {
  int effective_filter_height = (filter_height - 1) * dilation_height_factor + 1;
  int effective_filter_width = (filter_width - 1) * dilation_width_factor + 1;

  switch (padding) {
    case kTfLitePaddingSame:
      *out_height = (in_height + stride_height - 1) / stride_height;
      *out_width = (in_width + stride_width - 1) / stride_width;
      break;
    case kTfLitePaddingValid:
      *out_height = (in_height - effective_filter_height + stride_height) / stride_height;
      *out_width = (in_width - effective_filter_width + stride_width) / stride_width;
      break;
    default:
      return 0;
  }
  return 0;
}

namespace tflite {
TfLiteStatus PopulateConvolutionQuantizationParams(
    TfLiteContext* context, const TfLiteTensor* input, const TfLiteTensor* filter,
    const TfLiteTensor* bias, TfLiteTensor* output, TfLiteFusedActivation activation,
    int32_t* output_multiplier, int* output_shift, int32_t* output_activation_min,
    int32_t* output_activation_max, int32_t* per_channel_output_multiplier,
    int* per_channel_output_shift, int channels) {
  return kTfLiteOk;
}
}  // namespace tflite