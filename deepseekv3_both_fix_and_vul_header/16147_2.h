#include <stddef.h>
#include <utility>
#include <vector>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef enum {
  kStateUninvokable,
  // Add other states as needed
} State;

typedef enum {
  kTfLiteBuiltinReshape,
  // Add other builtin codes as needed
} TfLiteBuiltinOperator;

typedef struct {
  // Add context members as needed
} TfLiteContext;

typedef struct {
  int size;
  int* data;
} TfLiteIntArray;

typedef struct {
  void* delegate;
  bool data_is_stale;
  union {
    void* raw;
    // Add other data types as needed
  } data;
  size_t bytes;
  // Add other tensor members as needed
} TfLiteTensor;

typedef struct {
  TfLiteIntArray* inputs;
  TfLiteIntArray* outputs;
  void* delegate;
  // Add other node members as needed
} TfLiteNode;

typedef struct {
  int builtin_code;
  // Add other registration members as needed
} TfLiteRegistration;

typedef std::pair<TfLiteNode, TfLiteRegistration> NodeRegistration;

#define kTfLiteOptionalTensor -1
#define TF_LITE_ENSURE_STATUS(x) (x)
#define TF_LITE_ENSURE_OK(ctx, expr) ((expr) == kTfLiteOk ? kTfLiteOk : kTfLiteError)
#define TF_LITE_ENSURE(ctx, expr) ((expr) ? kTfLiteOk : kTfLiteError)
#define TFLITE_SCOPED_TAGGED_OPERATOR_PROFILE(profiler, op_name, node_index)

class MemoryPlanner {
 public:
  bool HasNonPersistentMemory();
  TfLiteStatus ResetAllocationsAfter(int allocation_index);
};

class Subgraph {
 private:
  bool consistent_;
  State state_;
  TfLiteContext context_;
  std::vector<NodeRegistration> nodes_and_registration_;
  std::vector<int> execution_plan_;
  int next_execution_plan_index_to_prepare_;
  int next_execution_plan_index_to_plan_allocation_;
  bool should_apply_nnapi_delegate_;
  bool applied_nnapi_delegate_;
  bool tensor_resized_since_op_invoke_;
  void* profiler_;
  bool (*check_cancelled_func_)(void*);
  void* cancellation_data_;
  std::vector<TfLiteTensor> tensors_;
  MemoryPlanner* memory_planner_;
  // Add other members as needed

 public:
  TfLiteStatus Invoke();
  TfLiteStatus PrepareOpsAndTensors();
  TfLiteStatus ModifyGraphWithDelegate(void* delegate);
  TfLiteStatus EnsureTensorDataIsReadable(int tensor_index);
  TfLiteStatus OpInvoke(const TfLiteRegistration& registration, TfLiteNode* node);
  void ReportError(const char* format, ...);
  const char* GetTFLiteOpName(const TfLiteRegistration& registration);
  void EnsureTensorsVectorCapacity();
  bool HasDynamicTensor(TfLiteContext& context, TfLiteIntArray* tensors);
  void* NnApiDelegate();
  TfLiteStatus ReportOpError(TfLiteContext* context, const TfLiteNode& node,
                            const TfLiteRegistration& registration, int node_index,
                            const char* message);
};