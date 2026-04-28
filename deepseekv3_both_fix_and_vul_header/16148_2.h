#include <vector>
#include <memory>
#include <cstdlib>

enum TfLiteStatus {
  kTfLiteOk,
  kTfLiteError
};

struct TfLiteIntArray {
  int size;
  int data[1];
};

struct TfLiteNode {
  TfLiteIntArray* inputs;
  TfLiteIntArray* outputs;
  TfLiteIntArray* intermediates;
  TfLiteIntArray* temporaries;
  void* user_data;
  void* builtin_data;
  const void* custom_initial_data;
  int custom_initial_data_size;
  void* delegate;
};

struct TfLiteRegistration {
  int builtin_code;
};

struct TfLiteContext {};

enum SubgraphState {
  kStateInvokableAndImmutable,
  kStateUninvokable
};

enum BuiltinOperator {
  BuiltinOperator_CUSTOM
};

#define TF_LITE_ENSURE_OK(context, status) \
  do { \
    if ((status) != kTfLiteOk) { \
      return kTfLiteError; \
    } \
  } while (0)

class Subgraph {
public:
  TfLiteStatus AddNodeWithParameters(
      const std::vector<int>& inputs, const std::vector<int>& outputs,
      const std::vector<int>& intermediates, const char* init_data,
      size_t init_data_size, void* builtin_data,
      const TfLiteRegistration* registration, int* node_index);
private:
  SubgraphState state_;
  TfLiteContext context_;
  std::vector<std::pair<TfLiteNode, TfLiteRegistration>> nodes_and_registration_;
  std::vector<int> execution_plan_;

  void ReportError(const char* error);
  TfLiteStatus CheckTensorIndices(const char* label, const int* indices, int size);
  TfLiteStatus CheckInputAndOutputForOverlap(const int* inputs, int num_inputs, const int* outputs, int num_outputs);
  TfLiteIntArray* ConvertVectorToTfLiteIntArray(const std::vector<int>& vec);
  void* OpInit(const TfLiteRegistration& registration, const char* init_data, size_t init_data_size);
  static void TfLiteIntArrayFree(TfLiteIntArray* a);
  static TfLiteIntArray* TfLiteIntArrayCreate(int size);
};