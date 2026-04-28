#include <cstdint>

struct Status {};
struct TensorShapeProto {
  void Clear();
  struct Dim {
    void set_size(int);
  };
  Dim* add_dim();
};
struct TensorProto {};
struct InputInfo {
  bool has_value() const;
  const TensorProto& value() const;
  const TensorShapeProto& shape() const;
};
struct OutputInfo {
  const TensorShapeProto& shape() const;
};
struct OpInfo {
  int inputs_size() const;
  const InputInfo& inputs(int) const;
  int outputs_size() const;
  const OutputInfo& outputs(int) const;
};
struct OpContext {
  const OpInfo& op_info;
};
struct NodeCosts {
  int64_t max_memory;
  int64_t num_total_output_bytes();
};
struct ConvolutionDimensions {
  int64_t kx;
  int64_t ky;
  int64_t sx;
  int64_t sy;
  int64_t batch;
  int64_t iz;
  int64_t ix;
  int64_t iy;
  int64_t ox;
  int64_t oy;
};
struct OpLevelCostEstimator {
  Status PredictAvgPoolGrad(const OpContext&, NodeCosts*) const;
};

bool GetTensorShapeProtoFromTensorProto(const TensorProto&, TensorShapeProto*);
ConvolutionDimensions OpDimensionsFromInputs(const TensorShapeProto&, const OpInfo&, bool*);
Status PredictDefaultNodeCosts(int64_t, const OpContext&, bool*, NodeCosts*);

#define TF_ASSIGN_OR_RETURN(lhs, rexpr) lhs = rexpr