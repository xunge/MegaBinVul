#include <vector>
#include <string>

using std::vector;
using std::string;

typedef int INDEX_TYPE;

class Status {
public:
    static Status OK() { return Status(); }
};

class OpKernelContext {};

class RowPartitionTensor {
public:
    INDEX_TYPE size() const { return 0; }
    INDEX_TYPE operator()(INDEX_TYPE) const { return 0; }
};

class errors {
public:
    template<typename T, typename U>
    static Status InvalidArgument(const string& s1, const T& t, const string& s2, const U& u) { 
        return Status::OK(); 
    }
    static Status InvalidArgument(const string&) { 
        return Status::OK(); 
    }
};

#define DCHECK_LT(a, b)
#define OP_REQUIRES(ctx, expr, status)