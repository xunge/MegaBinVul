#include <string>
#include <cstdint>
#include <sstream>

class TensorShape {
public:
    std::string DebugString() const;
};

class Tensor {
public:
    const TensorShape& shape() const;
    int64_t NumElements() const;
    int64_t dim_size(int dim) const;
    std::string DebugString() const;
};

class TensorShapeUtils {
public:
    static bool IsMatrix(const TensorShape& shape);
    static bool IsVector(const TensorShape& shape);
};

class Status {
public:
    static Status OK();
};

class OpKernelContext {};

namespace errors {
    Status InvalidArgument(const std::string& message);
    Status InvalidArgument(const std::string& message1, const std::string& message2);
    Status InvalidArgument(const std::string& message1, const std::string& message2, const std::string& message3);
    Status InvalidArgument(const std::string& message1, const std::string& message2, const std::string& message3, const std::string& message4);
    Status InvalidArgument(const std::string& message, int64_t value);
};