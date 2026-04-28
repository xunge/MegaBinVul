#include <cstdint>
#include <initializer_list>

class OpKernelContext;

class DatasetBase {
public:
    virtual ~DatasetBase() = default;
};

class DatasetContext {
public:
    struct Params {
        Params(std::initializer_list<const char*> list);
    };
    DatasetContext(Params params);
};

class Dataset : public DatasetBase {
public:
    Dataset(OpKernelContext* ctx, DatasetContext context, DatasetBase* input, int32_t num_threads);
};

class errors {
public:
    class InvalidArgument {
    public:
        InvalidArgument(const char* message);
    };
};

class PrivateThreadPoolDatasetOp {
public:
    static const char* const kDatasetType;
    static const char* const kDatasetOp;
    void MakeDatasetFromOptions(OpKernelContext* ctx, DatasetBase* input, int32_t num_threads, DatasetBase** output);
};

#define OP_REQUIRES(CTX, COND, ...)
#define OP_REQUIRES_OK(CTX, ...)

bool ValidateNumThreads(int32_t num_threads);