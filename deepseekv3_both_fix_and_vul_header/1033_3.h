#include <cstdint>
#include <vector>

struct Status {
  static Status OK();
};

struct Shape {};

struct Input {
  Shape shape() const;
};

struct OpInfo {
  Input inputs(int) const;
  bool IsTraining() const;
};

struct OpContext {
  const OpInfo& op_info;
};

struct ConvolutionDimensions {
  int64_t iz;
  int64_t batch;
  int64_t ix;
  int64_t iy;
};

struct NodeCosts {
  int64_t num_compute_ops;
  std::vector<int64_t> num_input_bytes_accessed;
  std::vector<int64_t> num_output_bytes_accessed;
  int64_t internal_read_bytes;
  bool inaccurate;
  int num_nodes_with_unknown_shapes;
  int64_t max_memory;
  int64_t num_total_output_bytes() const;
};

namespace Eigen {
namespace internal {
template<typename T>
struct scalar_rsqrt_op {};
template<typename T>
struct functor_traits {
  static const int Cost;
};
} // namespace internal
} // namespace Eigen

class OpLevelCostEstimator {
public:
  Status PredictFusedBatchNorm(const OpContext& op_context, NodeCosts* node_costs) const;
};

ConvolutionDimensions OpDimensionsFromInputs(Shape shape, const OpInfo& op_info, bool* found_unknown_shapes);
int64_t CalculateTensorSize(const Input& input, bool* found_unknown_shapes);
bool IsTraining(const OpInfo& op_info);

#define TF_ASSIGN_OR_RETURN(lhs, rexpr) lhs = rexpr