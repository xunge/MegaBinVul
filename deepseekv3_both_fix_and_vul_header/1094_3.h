#include <cstdint>
#include <string>
#include <map>
#include <iostream>

using int64_t = std::int64_t;

enum LogSeverity {
  WARNING
};

#define LOG(severity) std::cerr

class Status {
public:
    static Status InvalidArgument(const char* fmt, ...);
};

class AttrValue {
public:
    std::string s() const { return ""; }
};

class TensorShapeProto {
public:
    class Dimension {
    public:
        int64_t size() const { return 0; }
    };
    Dimension dim(int index) const { return Dimension(); }
    const TensorShapeProto& shape() const { return *this; }
};

class OpInfo {
public:
    std::map<std::string, AttrValue> attr() const { return {}; }
    const TensorShapeProto& inputs(int index) const { static TensorShapeProto t; return t; }
    const TensorShapeProto& outputs(int index) const { static TensorShapeProto t; return t; }
};

class OpContext {
public:
    OpInfo op_info;
};

class NodeCosts {};

TensorShapeProto MaybeGetMinimumShape(const TensorShapeProto& shape, int rank, bool* found) {
    return TensorShapeProto();
}

int64_t CalculateTensorElementCount(const TensorShapeProto& tensor_shape, bool* found) {
    return 0;
}

int64_t MultiplyWithoutOverflow(int64_t x, int64_t y) {
    return x * y;
}

namespace errors {
    Status InvalidArgument(const char* fmt, ...);
}

namespace Eigen {
namespace internal {
template<typename> struct functor_traits {
    enum { Cost = 1 };
};
template<typename, typename> struct scalar_cast_op {};
template<typename> struct scalar_difference_op {};
template<typename> struct scalar_sum_op {};
template<typename> struct scalar_product_op {};
template<typename> struct scalar_div_cost {};
template<typename> struct scalar_floor_op {};
template<typename> struct scalar_ceil_op {};
template<typename> struct scalar_round_op {};
}
}

class OpLevelCostEstimator {
public:
    Status PredictCropAndResize(const OpContext& op_context, NodeCosts* node_costs) const;
    Status PredictCostOfAnUnknownOp(const OpContext&, NodeCosts*) const { return Status(); }
    Status PredictDefaultNodeCosts(int64_t, const OpContext&, bool*, NodeCosts*) const { return Status(); }
};