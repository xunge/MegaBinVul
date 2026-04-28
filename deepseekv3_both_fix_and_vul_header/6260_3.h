#include <stdint.h>
#include <stddef.h>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef enum {
  kTfLiteNoQuantization = 0,
} TfLiteQuantizationType;

typedef struct TfLiteIntArray {
  int* data;
} TfLiteIntArray;

typedef struct TfLiteAffineQuantization {
  TfLiteIntArray* zero_point;
} TfLiteAffineQuantization;

typedef struct TfLiteQuantization {
  TfLiteQuantizationType type;
  TfLiteAffineQuantization* params;
} TfLiteQuantization;

typedef struct TfLiteTensor {
  TfLiteQuantization quantization;
  struct {
    int32_t zero_point;
  } params;
} TfLiteTensor;

typedef struct TfLiteContext {
  TfLiteTensor* tensors;
} TfLiteContext;

typedef struct TfLiteNode {
  TfLiteIntArray* intermediates;
} TfLiteNode;

#define TF_LITE_ENSURE(context, condition) \
  do {                                     \
    if (!(condition)) return kTfLiteError; \
  } while (0)

#define TF_LITE_ENSURE_OK(context, status) \
  do {                                     \
    if ((status) != kTfLiteOk) return kTfLiteError; \
  } while (0)

namespace lstm {
namespace full {
constexpr int kInputTensor = 0;
constexpr int kOutputStateTensor = 1;
constexpr int kInputToInputWeightsTensor = 2;
constexpr int kInputToForgetWeightsTensor = 3;
constexpr int kInputToCellWeightsTensor = 4;
constexpr int kInputToOutputWeightsTensor = 5;
constexpr int kRecurrentToInputWeightsTensor = 6;
constexpr int kRecurrentToForgetWeightsTensor = 7;
constexpr int kRecurrentToCellWeightsTensor = 8;
constexpr int kRecurrentToOutputWeightsTensor = 9;
constexpr int kProjectionWeightsTensor = 10;
constexpr int kProjectionBiasTensor = 11;
constexpr int kForgetGateBiasTensor = 12;
constexpr int kCellGateBiasTensor = 13;
constexpr int kOutputGateBiasTensor = 14;
constexpr int kInputGateBiasTensor = 15;
}  // namespace full
}  // namespace lstm

namespace lstm_eval {
struct IntegerLstmParameter {
  int32_t input_to_forget_effective_bias;
  int32_t recurrent_to_forget_effective_bias;
  int32_t input_to_cell_effective_bias;
  int32_t recurrent_to_cell_effective_bias;
  int32_t input_to_output_effective_bias;
  int32_t recurrent_to_output_effective_bias;
  int32_t input_to_input_effective_bias;
  int32_t recurrent_to_input_effective_bias;
  int32_t projection_effective_bias;
};
}  // namespace lstm_eval

struct OpData {
  lstm_eval::IntegerLstmParameter integer_lstm_param;
  bool use_layer_norm;
};

TfLiteStatus GetInputSafe(TfLiteContext* context, TfLiteNode* node, int index,
                         const TfLiteTensor** tensor);
const TfLiteTensor* GetVariableInput(TfLiteContext* context, TfLiteNode* node,
                                    int index);
const TfLiteTensor* GetOptionalInputTensor(TfLiteContext* context,
                                          TfLiteNode* node, int index);
const TfLiteTensor* GetInput(TfLiteContext* context, TfLiteNode* node,
                            int index);
TfLiteStatus PrecomputeZeroPointTimesWeightWithBias(
    TfLiteContext* context, int32_t zero_point, const TfLiteTensor* weight,
    const TfLiteTensor* bias, int32_t* effective_bias);