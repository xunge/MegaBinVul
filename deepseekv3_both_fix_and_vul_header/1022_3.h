#include <cstdint>

class OpKernelContext;

class DatasetBase {
public:
    virtual ~DatasetBase() = default;
};

class Dataset : public DatasetBase {
public:
    Dataset(OpKernelContext* ctx, DatasetBase* input, int64_t num_threads);
};

class PrivateThreadPoolDatasetOp {
public:
    void MakeDataset(OpKernelContext* ctx, DatasetBase* input, DatasetBase** output);
};

#define OP_REQUIRES_OK(ctx, expr)
#define OP_REQUIRES(ctx, expr, errors)

namespace errors {
class InvalidArgument {
public:
    InvalidArgument(const char* message);
};
}