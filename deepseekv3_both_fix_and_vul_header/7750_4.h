#include <cstdint>
#include <string>
#include <sstream>

class Status {
public:
    static Status OK();
};

class DimensionHandle {};
class DimensionOrConstant {};

constexpr int64_t kUnknownDim = -1;

class errors {
public:
    template <typename... Args>
    static Status InvalidArgument(Args&&... args);
};

class InferenceContext {
public:
    DimensionHandle UnknownDim();
    int64_t Value(DimensionHandle d);
    int64_t Value(DimensionOrConstant d);
    DimensionHandle MakeDim(DimensionOrConstant d);
    DimensionHandle MakeDim(int64_t value);
    Status Multiply(DimensionHandle first, DimensionOrConstant second, DimensionHandle* out);
};

int64_t MultiplyWithoutOverflow(int64_t a, int64_t b);