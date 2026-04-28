#include <cstdint>
#include <iostream>

namespace OpInfo {
struct TensorProperties {
    int dtype() const { return 0; }
};
}  // namespace OpInfo

class OpLevelCostEstimator {
public:
    int64_t CalculateTensorSize(const OpInfo::TensorProperties& tensor, bool* found_unknown_shapes);
    int64_t CalculateTensorElementCount(const OpInfo::TensorProperties& tensor, bool* found_unknown_shapes);
    static int DataTypeSize(int dtype);
    static int BaseType(int dtype);
    static int64_t MultiplyWithoutOverflow(int64_t a, int64_t b);
};

#define VLOG(level) std::cerr