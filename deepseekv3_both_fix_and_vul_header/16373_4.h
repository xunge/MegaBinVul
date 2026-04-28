#include <utility>
#include <memory>

struct GpuExecutor {};

enum cudnnDataType_t {};
enum cudnnRNNDataLayout_t {
    CUDNN_RNN_DATA_LAYOUT_SEQ_MAJOR_UNPACKED,
    CUDNN_RNN_DATA_LAYOUT_BATCH_MAJOR_UNPACKED
};

struct TensorDescriptor {
    void* get();
};
TensorDescriptor CreateTensorDescriptor();

struct RNNDataDescriptor {
    void* get();
};
RNNDataDescriptor CreateRNNDataDescriptor();

struct CudnnRnnSequenceTensorDescriptor {
    CudnnRnnSequenceTensorDescriptor(GpuExecutor*, int, int, int, cudnnDataType_t, RNNDataDescriptor&&, TensorDescriptor&&);
};

namespace port {
    enum error {
        INVALID_ARGUMENT
    };
    struct Status {
        Status(error, const char*);
    };
    template <typename T>
    struct StatusOr {
        StatusOr(T&&);
        StatusOr(Status&&);
    };
}

#define RETURN_IF_CUDNN_ERROR(expr) (expr)
#define CHECK_GT(a, b) ((void)0)

namespace absl {
    template <typename T>
    class Span {
    public:
        const T* data() const;
    };
}

int cudnnSetTensorNdDescriptor(void*, cudnnDataType_t, int, const int*, const int*);
int cudnnSetRNNDataDescriptor(void*, cudnnDataType_t, cudnnRNNDataLayout_t, int, int, int, const int*, void*);