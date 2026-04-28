#include <vector>
#include <algorithm>
#include <stdexcept>

using INDEX_TYPE = int;
using std::vector;

namespace errors {
    class InvalidArgument : public std::runtime_error {
    public:
        InvalidArgument(const char* message) : std::runtime_error(message) {}
    };
}

class Status {
public:
    Status() = default;
    Status(const errors::InvalidArgument&) {}
    static Status OK();
};

Status Status::OK() {
    return Status();
}

class OpKernelContext {};

class RowPartitionTensor {
public:
    INDEX_TYPE size() const;
    INDEX_TYPE operator()(INDEX_TYPE index) const;
};

#define OP_REQUIRES(context, condition, error) \
    if (!(condition)) { throw error; }