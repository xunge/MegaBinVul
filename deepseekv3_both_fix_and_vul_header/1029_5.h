#include <cstdint>
#include <cstddef>

struct Status {
  static Status OK();
};

struct ConvolutionDimensions {
  int64_t batch;
  int64_t ox;
  int64_t oy;
  int64_t oz;
  int64_t kx;
  int64_t ky;
  int64_t sy;
  int64_t ix;
  int64_t iz;
};

struct NodeCosts {
  int64_t num_compute_ops;
  int64_t num_input_bytes_accessed;
  int64_t num_output_bytes_accessed;
  int64_t max_memory;
  bool inaccurate;
  int64_t num_nodes_with_unknown_shapes;
};

struct OpInfo {
  struct Input {
    struct Shape {
    };
    enum DType {
    };
    Shape shape_field;
    DType dtype_field;
    const Shape& shape() const { return shape_field; }
    DType dtype() const { return dtype_field; }
  };
  Input inputs_array[1];
  const Input& inputs(int) const { return inputs_array[0]; }
};

struct OpContext {
  OpInfo op_info;
};

class OpLevelCostEstimator {
 public:
  Status PredictAvgPool(const OpContext& op_context, NodeCosts* node_costs) const;
 private:
  int64_t CalculateTensorSize(const OpInfo::Input& input, bool* found_unknown_shapes) const;
  int64_t CalculateOutputSize(const OpInfo& op_info, bool* found_unknown_shapes) const;
  ConvolutionDimensions OpDimensionsFromInputs(const OpInfo::Input::Shape& shape, const OpInfo& op_info, bool* found_unknown_shapes) const;
  size_t DataTypeSize(OpInfo::Input::DType dtype) const;
  OpInfo::Input::DType BaseType(OpInfo::Input::DType dtype) const;
};

#define TF_ASSIGN_OR_RETURN(lhs, rexpr) \
  lhs = rexpr