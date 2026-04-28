#include <stdint.h>
#include <stdbool.h>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef enum {
  kTfLiteFloat32,
  kTfLiteUInt8,
  kTfLiteInt8,
  kTfLiteInt16,
  kTfLiteInt32
} TfLiteType;

typedef enum {
  kTfLiteActRelu
} TfLiteFusedActivation;

typedef struct TfLiteContext {
  void (*ReportError)(struct TfLiteContext*, const char*, ...);
} TfLiteContext;

typedef struct TfLiteNode {
  void* builtin_data;
  void* user_data;
} TfLiteNode;

typedef struct TfLiteQuantizationParams {
  float scale;
  int32_t zero_point;
} TfLiteQuantizationParams;

typedef struct TfLiteTensor {
  TfLiteType type;
  TfLiteQuantizationParams params;
  void* data;
  struct {
    void* params;
  } quantization;
} TfLiteTensor;

typedef struct TfLiteSVDFParams {
  int32_t rank;
  TfLiteFusedActivation activation;
  bool asymmetric_quantize_inputs;
} TfLiteSVDFParams;

typedef struct TfLiteZeroPoints {
  int32_t data[1];
} TfLiteZeroPoints;

typedef struct TfLiteAffineQuantization {
  float* scale;
  TfLiteZeroPoints* zero_point;
} TfLiteAffineQuantization;

typedef struct OpData {
  bool float_weights_time_initialized;
  bool compute_row_sums;
  int32_t effective_scale_1_a;
  int32_t effective_scale_1_b;
  int32_t effective_scale_2_a;
  int32_t effective_scale_2_b;
} OpData;

enum {
  kInputTensor,
  kWeightsFeatureTensor,
  kWeightsTimeTensor,
  kBiasTensor,
  kStateTensor,
  kOutputTensor
};

#define TF_LITE_ENSURE_OK(context, status) (status)
#define TF_LITE_ENSURE_EQ(context, a, b) ((a) == (b) ? kTfLiteOk : kTfLiteError)
#define TF_LITE_ENSURE(context, condition) ((condition) ? kTfLiteOk : kTfLiteError)

const char* TfLiteTypeGetName(TfLiteType type);

TfLiteStatus GetInputSafe(TfLiteContext* context, TfLiteNode* node, int index, const TfLiteTensor** tensor);
TfLiteStatus GetTemporarySafe(TfLiteContext* context, TfLiteNode* node, int index, TfLiteTensor** tensor);
TfLiteStatus GetOutputSafe(TfLiteContext* context, TfLiteNode* node, int index, TfLiteTensor** tensor);
TfLiteTensor* GetOptionalInputTensor(TfLiteContext* context, TfLiteNode* node, int index);
TfLiteTensor* GetVariableInput(TfLiteContext* context, TfLiteNode* node, int index);

template <typename T>
T* GetTensorData(TfLiteTensor* tensor) {
  return static_cast<T*>(tensor->data);
}

template <typename T>
const T* GetTensorData(const TfLiteTensor* tensor) {
  return static_cast<const T*>(tensor->data);
}

void* GetTensorShape(const TfLiteTensor* tensor);
int NumElements(const TfLiteTensor* tensor);

namespace reference_ops {
void EvalFloatSVDF(const TfLiteSVDFParams* params, const void* input_shape, const float* input_data,
                   const void* weights_feature_shape, const float* weights_feature_data,
                   const void* weights_time_shape, const float* weights_time_data,
                   const void* bias_shape, const float* bias_data, float* scratch_data,
                   float* state_data, const void* output_shape, float* output_data);

void EvalHybridSVDF(const TfLiteSVDFParams* params, const void* input_shape, const float* input_data,
                    const void* weights_feature_shape, const int8_t* weights_feature_data,
                    float weights_feature_scale, const void* weights_time_shape,
                    const float* weights_time_data, const void* bias_shape, const float* bias_data,
                    float* scratch_data, float* scaling_factors, int8_t* input_quantized,
                    float* state_data, const void* output_shape, float* output_data,
                    int32_t* zero_points_ptr, int32_t* row_sums_ptr, bool* compute_row_sums);

void EvalIntegerSVDF(const TfLiteSVDFParams* params, const void* input_shape, const int8_t* input_data,
                     const void* weights_feature_shape, const int8_t* weights_feature_data,
                     const void* weights_time_shape, const int16_t* weights_time_data,
                     const void* bias_shape, const int32_t* bias_data, int16_t* state_data,
                     const void* output_shape, int8_t* output_data, int32_t* scratch_data,
                     int32_t* output_temp_data, int32_t effective_scale_1_a,
                     int32_t effective_scale_1_b, int32_t effective_scale_2_a,
                     int32_t effective_scale_2_b, int32_t input_zp, int32_t output_zp);
}