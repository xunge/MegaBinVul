#include <stddef.h>
#include <stdint.h>
#include <vector>
#include <memory>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef enum {
  kStateUninvokable,
  kStateInvokable
} SubgraphState;

struct TfLiteContext {
  // Minimal context definition
};

struct MemoryPlanner {
  bool HasNonPersistentMemory();
  TfLiteStatus ResetAllocationsAfter(int allocation_index);
};

struct Profiler {
  // Minimal profiler definition
};

typedef struct {
  int size;
  int* data;
} IntArray;

typedef struct {
  struct {
    const char* raw;
  } data;
  size_t bytes;
  IntArray* dims;
  void* delegate;
  bool data_is_stale;
} TfLiteTensor;

typedef struct {
  int builtin_code;
  void* (*init)(void*, const char*, size_t);
  void (*free)(void*, void*);
  TfLiteStatus (*prepare)(void*, struct TfLiteNode*);
  TfLiteStatus (*invoke)(void*, struct TfLiteNode*);
} TfLiteRegistration;

struct TfLiteNode {
  IntArray* inputs;
  IntArray* outputs;
  void* delegate;
};

typedef struct {
  TfLiteNode first;
  TfLiteRegistration second;
} NodeAndRegistration;

struct Subgraph {
  bool consistent_;
  SubgraphState state_;
  MemoryPlanner* memory_planner_;
  TfLiteContext context_;
  std::vector<int> execution_plan_;
  std::vector<NodeAndRegistration> nodes_and_registration_;
  std::vector<TfLiteTensor> tensors_;
  int next_execution_plan_index_to_prepare_;
  int next_execution_plan_index_to_plan_allocation_;
  bool tensor_resized_since_op_invoke_;
  std::unique_ptr<Profiler> profiler_;
  bool (*check_cancelled_func_)(void*);
  void* cancellation_data_;

  TfLiteStatus Invoke();
  void ReportError(const char* format, ...);
  TfLiteStatus PrepareOpsAndTensors();
  TfLiteStatus EnsureTensorDataIsReadable(int tensor_index);
  void EnsureTensorsVectorCapacity();
  TfLiteStatus OpInvoke(const TfLiteRegistration& registration, TfLiteNode* node);
  TfLiteStatus ReportOpError(TfLiteContext* context, const TfLiteNode& node,
                           const TfLiteRegistration& registration, int node_index,
                           const char* message);
  bool HasDynamicTensor(const TfLiteContext& context, const IntArray* tensors);
  const char* GetTFLiteOpName(const TfLiteRegistration& registration);
};

#define kTfLiteOptionalTensor -1
#define kTfLiteBuiltinReshape 1
#define TF_LITE_ENSURE_STATUS(x) if ((x) != kTfLiteOk) return kTfLiteError
#define TF_LITE_ENSURE(ctx, condition) if (!(condition)) return kTfLiteError
#define TFLITE_SCOPED_TAGGED_DEFAULT_PROFILE(profiler, tag)
#define TFLITE_SCOPED_TAGGED_OPERATOR_PROFILE(profiler, op_name, node_index)