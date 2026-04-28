#include <cstdint>
#include <vector>
#include <string>

struct Status {
  static Status OK();
};

struct errors {
  static Status InvalidArgument(const std::string& message, const std::string& details);
};

struct OpContext {
  struct OpInfo {
    int inputs_size() const;
    std::string ShortDebugString() const;
    struct Input {
      struct Shape {
      };
      Shape shape() const;
    };
    Input inputs(int) const;
  };
  const OpInfo& op_info;
};

struct NodeCosts {
  int64_t num_compute_ops;
  std::vector<int64_t> num_input_bytes_accessed;
  std::vector<int64_t> num_output_bytes_accessed;
  int64_t max_memory;
  bool inaccurate;
  int num_nodes_with_unknown_shapes;
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
  int64_t sx;
  int64_t sy;
};

class OpLevelCostEstimator {
public:
  Status PredictMaxPoolGrad(const OpContext& op_context, NodeCosts* node_costs) const;
private:
  ConvolutionDimensions OpDimensionsFromInputs(const OpContext::OpInfo::Input::Shape& shape,
                                             const OpContext::OpInfo& op_info,
                                             bool* found_unknown_shapes) const;
  int64_t CalculateTensorSize(const OpContext::OpInfo::Input& input,
                              bool* found_unknown_shapes) const;
};

#define TF_ASSIGN_OR_RETURN(lhs, rexpr) lhs = rexpr