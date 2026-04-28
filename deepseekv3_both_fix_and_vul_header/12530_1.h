#include <string>

class OpKernelConstruction;
class OpKernel {
public:
    OpKernel(OpKernelConstruction* context);
};

class TensorShape {};

enum DataType {
    DT_RESOURCE,
    DT_VARIANT
};

class ImmutableConstantOp : public OpKernel {
public:
    explicit ImmutableConstantOp(OpKernelConstruction* context);
private:
    std::string region_name_;
    DataType dtype_;
    TensorShape shape_;
};

#define OP_REQUIRES_OK(context, expr)
#define OP_REQUIRES(context, expr, error)

class errors {
public:
    static void InvalidArgument(const char* msg);
};

const char* kMemoryRegionNameAttr = "";
const char* kDTypeAttr = "";
const char* kShapeAttr = "";