#include <stdint.h>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef struct TfLiteContext TfLiteContext;
typedef struct TfLiteNode TfLiteNode;

typedef struct {
  int activation;
  int stride_width;
  int stride_height;
  int dilation_width_factor;
  int dilation_height_factor;
} TfLiteConvParams;

typedef struct {
  struct {
    int width;
    int height;
  } padding;
  int input_quantized_index;
  int scaling_factors_index;
} OpData;

typedef struct {
  struct {
    float scale;
  } params;
} TfLiteTensor;

typedef enum {
  kReference,
  kGenericOptimized,
  kMultithreadOptimized,
  kCblasOptimized
} KernelType;

typedef struct {
  int width;
  int height;
} PaddingValues;

typedef enum {
  kSame,
  kValid
} PaddingType;

typedef struct {
  PaddingType padding_type;
  PaddingValues padding_values;
  int stride_width;
  int stride_height;
  int dilation_width_factor;
  int dilation_height_factor;
  float float_activation_min;
  float float_activation_max;
} ConvParams;

#define TF_LITE_ENSURE(ctx, condition) ((condition) ? kTfLiteOk : kTfLiteError)
#define TF_LITE_ENSURE_OK(ctx, status) (status)

namespace ruy {
namespace profiler {
class ScopeLabel {
 public:
  explicit ScopeLabel(const char*) {}
};
}  // namespace profiler
}  // namespace ruy

namespace tensor_utils {
void SymmetricQuantizeFloats(const float*, int, int8_t*, float*, float*, float*);
}  // namespace tensor_utils

namespace optimized_ops {
void HybridConv(const ConvParams&, const float*, const void*, const int8_t*,
                const void*, const int8_t*, const void*, const float*,
                const void*, const int32_t*, const void*, float*, const void*,
                const int8_t*, void*);
}  // namespace optimized_ops

class CpuBackendContext {
 public:
  static void* GetFromContext(TfLiteContext*);
};

int SizeOfDimension(const TfLiteTensor*, int);
int NumElements(const TfLiteTensor*);
template<typename T> T* GetTensorData(const TfLiteTensor*);
void* GetTensorShape(const TfLiteTensor*);
TfLiteStatus GetTemporarySafe(TfLiteContext*, TfLiteNode*, int, TfLiteTensor**);
void CalculateActivationRange(int, float*, float*);

extern KernelType kernel_type;