#include <vector>
#include <cstdint>

using Status = int;

class xla {
public:
    class Literal {};
    enum class ValueInferenceMode {};
};

class TensorShape {
public:
    TensorShape(const std::vector<int64_t>& dims);
};

class errors {
public:
    static Status InvalidArgument(const char* msg1, const char* msg2, int64_t i, const char* msg3, int64_t num_elements);
};

#define TF_RETURN_IF_ERROR(expr) \
    do {                         \
        Status _status = (expr); \
        if (_status != 0)        \
            return _status;      \
    } while (0)

class XlaOpKernelContext {
public:
    Status ConstantInput(int index, xla::Literal* literal, xla::ValueInferenceMode mode);
    Status ConstantInputAsShape(int index, TensorShape* shape, xla::ValueInferenceMode mode);
};

Status OkStatus();
Status LiteralToInt64Vector(const xla::Literal& literal, std::vector<int64_t>* dims);
int64_t MultiplyWithoutOverflow(int64_t a, int64_t b);