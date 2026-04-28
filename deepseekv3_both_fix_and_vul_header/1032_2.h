#include <cstdint>

struct Status {
  static Status OK();
};

struct ConvolutionDimensions {
  int64_t batch;
  int64_t ix;
  int64_t iy;
  int64_t iz;
  int64_t kx;
  int64_t ky;
  int64_t ox;
  int64_t oy;
  int64_t oz;
  int64_t sx;
  int64_t sy;
};

struct NodeCosts {
  int64_t num_compute_ops;
  int64_t num_input_bytes_accessed;
  int64_t num_output_bytes_accessed;
  int64_t max_memory;
  bool inaccurate;
  int num_nodes_with_unknown_shapes;
};

struct Tensor {
  struct Shape {};
  const Shape& shape() const;
  int dtype() const;
};

struct OpInfo {
  const Tensor& inputs(int) const;
};

struct OpContext {
  const OpInfo& op_info;
};

class OpLevelCostEstimator {
public:
  Status PredictMaxPool(const OpContext& op_context, NodeCosts* node_costs) const;
};

int64_t CalculateTensorSize(const Tensor&, bool*);
int64_t CalculateOutputSize(const OpInfo&, bool*);
int DataTypeSize(int);
int BaseType(int);
ConvolutionDimensions OpDimensionsFromInputs(const Tensor::Shape&, const OpInfo&, bool*);

#define TF_ASSIGN_OR_RETURN(lhs, rexpr) \
  lhs = rexpr