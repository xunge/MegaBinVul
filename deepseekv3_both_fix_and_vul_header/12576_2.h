#include <stddef.h>
#include <memory>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef enum {
  kStateUninvokable,
  kStateInvokable
} SubgraphState;

typedef struct TfLiteContext {
  int unused;
} TfLiteContext;

typedef struct TfLiteProfiler {
  int unused;
} TfLiteProfiler;

typedef struct TfLiteMemoryPlanner {
  bool HasNonPersistentMemory();
  TfLiteStatus AcquireNonPersistentMemory();
  TfLiteStatus ResetAllocations();
} TfLiteMemoryPlanner;

#define TFLITE_SCOPED_TAGGED_DEFAULT_PROFILE(profiler, tag)
#define TF_LITE_ENSURE_STATUS(x) (x)
#define TF_LITE_ENSURE_OK(ctx, status) (status)

struct Subgraph {
  bool consistent_;
  SubgraphState state_;
  TfLiteContext* context_;
  bool is_subgraph_in_use_;
  std::unique_ptr<TfLiteProfiler> profiler_;
  TfLiteMemoryPlanner* memory_planner_;
  int next_execution_plan_index_to_prepare_;
  int next_execution_plan_index_to_plan_allocation_;
  int next_original_execution_plan_index_to_prepare_;

  void ReportError(const char* message);
  TfLiteStatus RedoAllDelegates();
  bool HasDynamicTensorImpl(TfLiteContext* context, void* inputs);
  TfLiteStatus PrepareOpsAndTensors();
  void ResetVariableTensors();
  void* inputs();
  TfLiteStatus AllocateTensors();
};

struct SubgraphGuard {
  TfLiteContext** context_;
  bool* is_subgraph_in_use_;
  TfLiteStatus status_;
  
  SubgraphGuard(TfLiteContext** context, bool* is_subgraph_in_use);
  ~SubgraphGuard();
  TfLiteStatus status() const { return status_; }
};