#include <vector>
#include <memory>

typedef enum {
  kTfLiteOk = 0,
} TfLiteStatus;

struct TfLiteIntArray {
  int size;
  int data[1];
};

struct TfLiteTensor {
  int type;
  TfLiteIntArray* dims;
};

struct TfLiteContext {
  void* impl_;
  TfLiteStatus (*ResizeTensor)(TfLiteContext*, TfLiteTensor*, TfLiteIntArray*);
};

struct TfLiteNode {
  void* user_data;
  TfLiteIntArray* inputs;
  TfLiteIntArray* outputs;
};

struct Subgraph {
  std::vector<int> inputs() const;
  std::vector<int> outputs() const;
  TfLiteTensor* tensor(int index);
  TfLiteStatus AllocateTensors();
  bool HasDynamicTensors();
  std::vector<std::unique_ptr<Subgraph>>* GetSubgraphs();
};

struct OpData {
  int cond_subgraph_index;
  int body_subgraph_index;
  bool cond_has_dynamic_output_tensors;
  bool body_has_dynamic_output_tensors;
};

class TfLiteIntArrayView {
 public:
  TfLiteIntArrayView(TfLiteIntArray* array);
};

#define TF_LITE_ENSURE_EQ(context, a, b) kTfLiteOk
#define TF_LITE_ENSURE(context, condition) kTfLiteOk
#define TF_LITE_ENSURE_OK(context, status) status
#define TF_LITE_ENSURE_STATUS(status) status
#define TF_LITE_ENSURE_TYPES_EQ(context, a, b) kTfLiteOk

TfLiteStatus CopyTensorsShapeAndType(TfLiteContext* context, Subgraph* src_subgraph,
                                    TfLiteIntArrayView src_tensors,
                                    Subgraph* dst_subgraph,
                                    const std::vector<int>& dst_tensors,
                                    bool copy_data);
bool IsDynamicTensor(const TfLiteTensor* tensor);
TfLiteStatus CheckCondOutput(TfLiteContext* context, TfLiteTensor* tensor);
bool TfLiteIntArrayEqual(const TfLiteIntArray* a, const TfLiteIntArray* b);
TfLiteIntArray* TfLiteIntArrayCopy(const TfLiteIntArray* src);
TfLiteStatus GetOutputSafe(TfLiteContext* context, TfLiteNode* node, int index,
                          TfLiteTensor** tensor);
void SetTensorToDynamic(TfLiteTensor* tensor);