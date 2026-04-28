#include <stdint.h>
#include <stddef.h>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef struct TfLiteContext TfLiteContext;
typedef struct TfLiteNode TfLiteNode;
typedef struct TfLiteTensor TfLiteTensor;
typedef struct TfLiteIntArray TfLiteIntArray;

struct TfLiteFullyConnectedParams {
  int activation;
};

struct FullyConnectedParams {
  float float_activation_min;
  float float_activation_max;
  bool lhs_cacheable;
  bool rhs_cacheable;
};

struct OpData {};

struct SparsityParams {
  int dim_metadata_size;
  struct {
    int dense_size;
  } dim_metadata[4];
};

struct TfLiteTensor {
  SparsityParams* sparsity;
};

enum KernelType {
  kReference,
  kLegacyPie
};
extern KernelType kernel_type;

#define kDimMetadataSizeRandomSparse 2
#define kDimMetadataSizeBlockSparse 3

void CalculateActivationRange(int activation, float* min, float* max);
bool IsConstantTensor(const TfLiteTensor* tensor);
bool SupportedSparsityFormat(const SparsityParams& sparsity);
bool VerifySparsity(const TfLiteIntArray* filter_shape,
                   const TfLiteIntArray* input_shape,
                   const TfLiteIntArray* output_shape,
                   const SparsityParams* sparsity);

TfLiteIntArray* GetTensorShape(const TfLiteTensor* tensor);
template <typename T> T* GetTensorData(const TfLiteTensor* tensor);

TfLiteStatus EvalPie(TfLiteContext* context, TfLiteNode* node,
                    TfLiteFullyConnectedParams* params, OpData* data,
                    const TfLiteTensor* input, const TfLiteTensor* filter,
                    const TfLiteTensor* bias, TfLiteTensor* output);

void TF_LITE_KERNEL_LOG(TfLiteContext* context, const char* format, ...);

namespace reference_ops {
void FullyConnectedSparseWeight(
    const SparsityParams& sparsity, const FullyConnectedParams& params,
    const TfLiteIntArray* input_shape, const float* input_data,
    const TfLiteIntArray* filter_shape, const float* filter_data,
    const TfLiteIntArray* bias_shape, const float* bias_data,
    const TfLiteIntArray* output_shape, float* output_data);

void FullyConnected(
    const FullyConnectedParams& params, const TfLiteIntArray* input_shape,
    const float* input_data, const TfLiteIntArray* filter_shape,
    const float* filter_data, const TfLiteIntArray* bias_shape,
    const float* bias_data, const TfLiteIntArray* output_shape,
    float* output_data);
}

namespace optimized_ops {
void FullyConnectedSparseWeight(
    const SparsityParams& sparsity, const FullyConnectedParams& params,
    const TfLiteIntArray* input_shape, const float* input_data,
    const TfLiteIntArray* filter_shape, const float* filter_data,
    const TfLiteIntArray* bias_shape, const float* bias_data,
    const TfLiteIntArray* output_shape, float* output_data);

void FullyConnectedSparseWeight1x4(
    const SparsityParams& sparsity, const FullyConnectedParams& params,
    const TfLiteIntArray* input_shape, const float* input_data,
    const TfLiteIntArray* filter_shape, const float* filter_data,
    const TfLiteIntArray* bias_shape, const float* bias_data,
    const TfLiteIntArray* output_shape, float* output_data,
    void* context);

void FullyConnected(
    const FullyConnectedParams& params, const TfLiteIntArray* input_shape,
    const float* input_data, const TfLiteIntArray* filter_shape,
    const float* filter_data, const TfLiteIntArray* bias_shape,
    const float* bias_data, const TfLiteIntArray* output_shape,
    float* output_data, void* context);
}

struct CpuBackendContext {
  static CpuBackendContext* GetFromContext(TfLiteContext* context);
};