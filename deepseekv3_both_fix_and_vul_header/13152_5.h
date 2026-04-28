#include <vector>
#include <cstdint>
#include <string>
#include <sstream>

#define TF_RETURN_IF_ERROR(expr) \
  do { \
    const Status _status = (expr); \
    if (!_status.ok()) return _status; \
  } while (0)

class Status;

template <typename T>
class StatusOr {
public:
    StatusOr(T value);
    StatusOr(const Status& status);
    bool ok() const;
    const T& value() const;
    const Status& status() const;
};

class Status {
public:
    Status();
    static Status OK();
    bool ok() const;
};

class TensorShape {
public:
    TensorShape();
    bool IsVector() const;
    int num_elements() const;
    std::string DebugString() const;
};

class TensorShapeUtils {
public:
    static bool IsVector(const TensorShape& shape);
};

class errors {
public:
    static Status InvalidArgument(const std::string& message);
    static Status InvalidArgument(const std::string& message, const std::string& arg);
    static Status InvalidArgument(const std::string& message, int arg);
    static Status InvalidArgument(const std::string& message, int arg1, const std::string& arg2);
};

class XlaOpKernelContext {
public:
    int num_inputs() const;
    TensorShape InputShape(int index) const;
    Status ConstantInputAsIntVector(int index, std::vector<int64_t>* vec);
};

extern std::vector<int64_t> stride_;
int num_dims();
Status ValidateStrides(const std::vector<int64_t>& stride);