#include <functional>
#include <vector>
#include <string>

class Tensor {
public:
    const Tensor& shape() const;
    std::string DebugString() const;
    int NumElements() const;
};

struct OpKernelContext {
    const Tensor& input(int index) const;
};

class AsyncOpKernel {
public:
    using DoneCallback = std::function<void()>;
};

namespace TensorShapeUtils {
    bool IsVector(const Tensor& shape);
    bool IsMatrix(const Tensor& shape);
    bool IsScalar(const Tensor& shape);
}

namespace errors {
    struct InvalidArgument {
        InvalidArgument(const char* msg);
        InvalidArgument(const char* msg, const std::string& str);
    };
}

#define OP_REQUIRES_ASYNC(context, condition, error, done)
#define OP_REQUIRES_OK_ASYNC(context, condition, done)

struct Device {};
typedef int T;
typedef int Tindex;

template<typename Device, typename T, typename Tindex>
struct SparseFillEmptyRowsFunctor {
    void operator()(OpKernelContext* context, const Tensor& default_value_t,
                   const Tensor& indices_t, const Tensor& values_t,
                   const Tensor& dense_shape_t, AsyncOpKernel::DoneCallback done);
};

namespace functor {
    template<typename Device, typename T, typename Tindex>
    using SparseFillEmptyRows = SparseFillEmptyRowsFunctor<Device, T, Tindex>;
}