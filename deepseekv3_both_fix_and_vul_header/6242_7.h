#include <vector>
#include <unordered_set>
#include <cstdint>

using int64 = int64_t;
using int32 = int32_t;

class Status {
public:
    static Status OK();
    bool ok() const;
};

class Tensor {
public:
    template<typename T>
    class Flat {
    public:
        T operator()(int) const;
        int size() const;
    };
    
    template<typename T>
    Flat<T> flat() const;
};

class ShapeHandle {};
class DimensionHandle {};

class InferenceContext {
public:
    Status GetAttr(const char*, bool*);
    const Tensor* input_tensor(int);
    DimensionHandle MakeDim(int64_t);
    ShapeHandle MakeShape(const std::vector<DimensionHandle>&);
    void set_output(int, ShapeHandle);
};

Status UnknownShape(InferenceContext*);
Status InvalidArgument(const char*);

#define TF_RETURN_IF_ERROR(expr) \
    do { \
        Status _status = (expr); \
        if (!_status.ok()) return _status; \
    } while (0)

namespace absl {
    template<typename T>
    using flat_hash_set = std::unordered_set<T>;
}

namespace errors {
    using ::InvalidArgument;
}