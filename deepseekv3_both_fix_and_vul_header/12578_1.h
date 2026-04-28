#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include <memory>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

struct TfLiteIntArray {
  int size;
  int data[];
};

struct TfLiteTensor {
  int type;
  TfLiteIntArray* dims;
};

struct TfLiteNode {
  void* user_data;
  TfLiteIntArray* inputs;
  TfLiteIntArray* outputs;
};

struct TfLiteContext {
  void* impl_;
  TfLiteStatus (*ResizeTensor)(TfLiteContext*, TfLiteTensor*, TfLiteIntArray*);
};

typedef struct {
  int cond_subgraph_index;
  int body_subgraph_index;
  bool cond_has_dynamic_output_tensors;
  bool body_has_dynamic_output_tensors;
} OpData;

class Subgraph {
 public:
  const std::vector<int>& inputs() const;
  const std::vector<int>& outputs() const;
  TfLiteTensor* tensor(int index);
  TfLiteStatus AllocateTensors();
  bool HasDynamicTensors();
  std::vector<std::unique_ptr<Subgraph>>* GetSubgraphs();
};

struct TfLiteIntArrayView {
  explicit TfLiteIntArrayView(const TfLiteIntArray* array);
};

#define TF_LITE_ENSURE_EQ(context, a, b) (kTfLiteOk)
#define TF_LITE_ENSURE(context, condition) (kTfLiteOk)
#define TF_LITE_ENSURE_OK(context, status) (status)
#define TF_LITE_ENSURE_TYPES_EQ(context, type1, type2) (kTfLiteOk)
#define TF_LITE_ENSURE_STATUS(status) (status)

TfLiteStatus CopyTensorsShapeAndType(TfLiteContext* context, Subgraph* src_subgraph,
                                   TfLiteIntArrayView src_tensors_indices,
                                   Subgraph* dst_subgraph,
                                   const std::vector<int>& dst_tensors_indices,
                                   bool copy_shape);
TfLiteStatus GetOutputSafe(TfLiteContext* context, TfLiteNode* node, int index,
                          TfLiteTensor** tensor);
bool IsDynamicTensor(const TfLiteTensor* tensor);
TfLiteStatus CheckCondOutput(TfLiteContext* context, TfLiteTensor* cond_output);
void SetTensorToDynamic(TfLiteTensor* tensor);
TfLiteIntArray* TfLiteIntArrayCopy(const TfLiteIntArray* src);
bool TfLiteIntArrayEqual(const TfLiteIntArray* a, const TfLiteIntArray* b);