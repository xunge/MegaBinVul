#include <utility>
#include <cstdlib>

struct GpuExecutor;

class TensorDescriptor {
public:
    void* get();
    TensorDescriptor() = default;
    TensorDescriptor(TensorDescriptor&&);
    TensorDescriptor& operator=(TensorDescriptor&&);
};

class CudnnRnnSequenceTensorDescriptor {
public:
    CudnnRnnSequenceTensorDescriptor(GpuExecutor*, int, int, int, int, void*, TensorDescriptor&&);
};

enum cudnnDataType_t {
    CUDNN_DATA_FLOAT
};

int cudnnSetTensorNdDescriptor(void*, cudnnDataType_t, int, const int*, const int*);

namespace port {
enum error {
    INVALID_ARGUMENT,
    INTERNAL
};

class Status {
public:
    Status(error code, const char* message);
};

template <typename T>
class StatusOr {
public:
    StatusOr(T&& value);
    StatusOr(const Status& status);
};
}  // namespace port

TensorDescriptor CreateTensorDescriptor();

#define CHECK_GT(a, b) ((a) > (b) ? (void)0 : abort())
#define RETURN_IF_CUDNN_ERROR(expr) \
  do {                              \
    int status = (expr);            \
    if (status != 0) {              \
      abort();                      \
    }                               \
  } while (0)