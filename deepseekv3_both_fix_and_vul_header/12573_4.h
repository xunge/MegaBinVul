#include <stdint.h>
#include <cstddef>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef enum {
  kTfLiteFloat32,
  kTfLiteUInt8,
  kTfLiteInt8,
  kTfLiteInt16
} TfLiteType;

typedef struct TfLiteContext {
  void (*ReportError)(TfLiteContext*, const char*, ...);
} TfLiteContext;

typedef struct TfLiteNode {
  void* user_data;
  void* builtin_data;
} TfLiteNode;

typedef struct TfLiteTensor {
  TfLiteType type;
} TfLiteTensor;

typedef struct {
  int stride_height;
  int stride_width;
  int padding;
} TfLiteTransposeConvParams;

typedef struct {
  int has_col2im;
  int col2im_index;
  int weights_are_transposed;
  int transposed_weights_index;
  int scratch_tensor_index;
  int padding;
} OpData;

enum KernelType {
  kReference,
  kGenericOptimized
};

#define TF_LITE_ENSURE_OK(context, status) (status)
#define TF_LITE_ENSURE(context, condition) ((condition) ? kTfLiteOk : kTfLiteError)
#define GetInputSafe(context, node, index, tensor) (kTfLiteOk)
#define GetOptionalInputTensor(context, node, index) (nullptr)
#define GetOutputSafe(context, node, index, tensor) (kTfLiteOk)
#define GetTemporary(context, node, index) (nullptr)
#define GetTemporarySafe(context, node, index, tensor) (kTfLiteOk)
#define IsDynamicTensor(tensor) (0)
#define IsConstantTensor(tensor) (1)
#define NumInputs(node) (0)
#define SizeOfDimension(tensor, dim) (0)
#define TfLiteTypeGetName(type) ("")
#define kOutputShapeTensor (0)
#define kWeightsTensor (0)
#define kDataInputTensor (0)
#define kBiasTensor (0)
#define kOutputTensor (0)

static const KernelType kernel_type = kReference;

static int ComputePaddingHeightWidth(int stride_height, int stride_width, 
                                   int dilation_height, int dilation_width,
                                   int height, int width,
                                   int filter_height, int filter_width,
                                   int padding, int* output_height, 
                                   int* output_width) {
  return 0;
}

static TfLiteStatus ResizeTensor(TfLiteContext* context, 
                               const TfLiteTensor* output_shape,
                               TfLiteTensor* tensor) {
  return kTfLiteOk;
}

static TfLiteStatus ResizeCol2ImTensor(TfLiteContext* context,
                                     const TfLiteTensor* output_shape,
                                     const TfLiteTensor* weights,
                                     const TfLiteTensor* input,
                                     TfLiteTensor* col2im) {
  return kTfLiteOk;
}

static TfLiteStatus ResizeAndTransposeWeights(TfLiteContext* context,
                                            const TfLiteTensor* weights,
                                            TfLiteTensor* transposed_weights) {
  return kTfLiteOk;
}

template <KernelType kernel_type>
static void EvalFloat(TfLiteContext* context, 
                     const TfLiteTransposeConvParams* params,
                     OpData* data, const TfLiteTensor* input,
                     const TfLiteTensor* weights, const TfLiteTensor* bias,
                     TfLiteTensor* transposed_weights, TfLiteTensor* col2im,
                     TfLiteTensor* output) {}

template <KernelType kernel_type>
static void EvalQuantized(TfLiteContext* context,
                        const TfLiteTransposeConvParams* params,
                        OpData* data, const TfLiteTensor* input,
                        const TfLiteTensor* weights,
                        TfLiteTensor* transposed_weights,
                        const TfLiteTensor* bias, TfLiteTensor* col2im,
                        TfLiteTensor* output, TfLiteTensor* scratch_buffer) {}

template <KernelType kernel_type>
static void EvalQuantizedPerChannel(TfLiteContext* context,
                                  const TfLiteTransposeConvParams* params,
                                  OpData* data, const TfLiteTensor* input,
                                  const TfLiteTensor* weights,
                                  TfLiteTensor* transposed_weights,
                                  const TfLiteTensor* bias, TfLiteTensor* col2im,
                                  TfLiteTensor* output, 
                                  TfLiteTensor* scratch_buffer) {}

static void EvalQuantizedPerChannel16x8(TfLiteContext* context,
                                      const TfLiteTransposeConvParams* params,
                                      OpData* data, const TfLiteTensor* input,
                                      const TfLiteTensor* weights,
                                      TfLiteTensor* transposed_weights,
                                      const TfLiteTensor* bias, 
                                      TfLiteTensor* col2im,
                                      TfLiteTensor* output,
                                      TfLiteTensor* scratch_buffer) {}