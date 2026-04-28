#include <vector>
#include <algorithm>
#include <cassert>

using INDEX_TYPE = int;
using std::vector;

struct OpKernelContext {};

struct RowPartitionTensor {
    INDEX_TYPE size() const;
    INDEX_TYPE operator()(INDEX_TYPE) const;
};

namespace errors {
    struct InvalidArgument {
        InvalidArgument(const char*);
    };
}

#define OP_REQUIRES(context, condition, error) \
    do { if (!(condition)) throw error; } while (0)

#define DCHECK_EQ(a, b) assert((a) == (b))