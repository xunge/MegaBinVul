#include <vector>
#include <cstdint>

using INDEX_TYPE = int64_t;
using std::vector;

template <typename T>
class RowPartitionTensorImpl {
public:
    INDEX_TYPE size() const { return 0; }
    T operator()(INDEX_TYPE index) const { return T(); }
};

using RowPartitionTensor = RowPartitionTensorImpl<INDEX_TYPE>;

class OpKernelContext {};

class errors {
public:
    class InvalidArgument {
    public:
        InvalidArgument(const char* message) {}
    };
};

#define DCHECK_LT(a, b)
#define DCHECK_EQ(a, b)
#define OP_REQUIRES(context, condition, error)