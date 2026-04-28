#include <vector>
#include <numeric>
#include <string>
#include <cstdint>

struct Status {
    bool ok() const { return true; }
};

using int32_t = int32_t;

namespace errors {
Status InvalidArgument(const std::string& message);
}

class Tensor {
public:
    int dims() const { return 0; }
    template<typename T> const std::vector<T>& vec() const { 
        static std::vector<T> v; 
        return v; 
    }
};

class TensorShape {
public:
    static Status BuildTensorShape(const std::vector<int64_t>& shape_data, TensorShape* shape);
    int dims() const { return 0; }
};

class OpKernelContext {
public:
    const Tensor& input(int index) const { static Tensor t; return t; }
};

namespace sparse {
class SparseTensor {
public:
    Status IndicesValid() const { return Status(); }
    static Status Create(const Tensor& indices, const Tensor& values,
                        const TensorShape& shape, const std::vector<int64_t>& order,
                        SparseTensor* tensor) { return Status(); }
};
}

#define TF_RETURN_IF_ERROR(expr) do { \
    const Status& _status = (expr); \
    if (!_status.ok()) return _status; \
} while (0)

void CheckRankAtLeast2(OpKernelContext* ctx, const TensorShape& shape) {}