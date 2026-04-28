#include <vector>
#include <string>

struct DataType {
    bool operator==(const DataType&) const { return true; }
};

struct Variant {
    template<typename T>
    const T* get() const { return nullptr; }
    Variant operator()() { return *this; }
};

struct Tensor {
    template<typename T>
    T scalar() const { return T(); }
    DataType dtype() const { return DataType(); }
};

struct CompressedElement {};

struct OpKernelContext {
    Tensor input(int);
    void set_output(int, const Tensor&);
};

struct Status {
    bool ok() const { return true; }
};

struct UncompressElementOp {
    std::vector<DataType> output_types_;
    void Compute(OpKernelContext* ctx);
};

Status UncompressElement(const CompressedElement&, std::vector<Tensor>*);

std::string DataTypeString(DataType);

struct errors {
    struct FailedPrecondition {
        FailedPrecondition(const char*, size_t, const char*, size_t);
    };
};

#define OP_REQUIRES(ctx, expr, err)
#define OP_REQUIRES_OK(ctx, expr)