#include <cstdint>
#include <vector>

#define TF_ASSIGN_OR_RETURN(lhs, rhs) lhs = rhs

struct Status {
  static Status OK() { return Status(); }
};

struct OpContext {
  struct OpInfo {
    struct Tensor {
      struct Shape {};
      Shape shape() const { return Shape(); }
    };
    Tensor inputs(int) const { return Tensor(); }
  };
  OpInfo op_info;
};

struct NodeCosts {
  int64_t num_compute_ops;
  std::vector<int64_t> num_input_bytes_accessed;
  std::vector<int64_t> num_output_bytes_accessed;
  int64_t internal_read_bytes;
  int64_t max_memory;
  bool inaccurate;
  int num_nodes_with_unknown_shapes;
  int64_t num_total_output_bytes() const { return 0; }
};

struct ConvolutionDimensions {
  int64_t iz;
  int64_t batch;
  int64_t ix;
  int64_t iy;
};

namespace Eigen {
namespace internal {
template<typename T>
struct scalar_rsqrt_op {
  static const int Cost;
};
template<typename T>
struct functor_traits {
  static const int Cost;
};
}  // namespace internal
}  // namespace Eigen

template<>
const int Eigen::internal::scalar_rsqrt_op<float>::Cost = 0;

template<>
const int Eigen::internal::functor_traits<Eigen::internal::scalar_rsqrt_op<float>>::Cost = 0;

ConvolutionDimensions OpDimensionsFromInputs(const OpContext::OpInfo::Tensor::Shape&, const OpContext::OpInfo&, bool*) {
  return ConvolutionDimensions();
}

int64_t CalculateTensorSize(const OpContext::OpInfo::Tensor&, bool*) {
  return 0;
}

class OpLevelCostEstimator {
public:
  Status PredictFusedBatchNormGrad(const OpContext& op_context, NodeCosts* node_costs) const;
};