#include <vector>
#include <cstdint>
#include <string>

class Status {
public:
    static Status OK();
    bool ok() const;
    static Status InvalidArgument(const std::string& message);
    static Status InvalidArgument(const std::string& message1, const std::string& message2);
    static Status InvalidArgument(const std::string& message1, int num, const std::string& message2);
};

template <typename T>
class StatusOr {
public:
    StatusOr(const T& value);
    StatusOr(const Status& status);
    bool ok() const;
    const T& ValueOrDie() const;
    const Status& status() const;
};

class TensorShape {
public:
    TensorShape();
    int num_elements() const;
    std::string DebugString() const;
};

class XlaOpKernelContext {
public:
    int num_inputs() const;
    TensorShape InputShape(int index) const;
    Status ConstantInputAsIntVector(int index, std::vector<int64_t>* vec);
};

namespace TensorShapeUtils {
    bool IsVector(const TensorShape& shape);
}

namespace errors {
    Status InvalidArgument(const std::string& message);
    Status InvalidArgument(const std::string& message1, const std::string& message2);
    Status InvalidArgument(const std::string& message1, int num, const std::string& message2);
}

#define TF_RETURN_IF_ERROR(expr) \
  do { \
    const Status _status = (expr); \
    if (!_status.ok()) return _status; \
  } while (0)

Status ValidateKernelSizes(const std::vector<int64_t>& ksize);

extern std::vector<int64_t> ksize_;
extern int num_dims();