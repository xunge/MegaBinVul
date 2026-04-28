#include <vector>
#include <string>
#include <cstdint>

using std::vector;
using std::string;

struct Status {
    static Status OK();
    bool ok() const;
};

using int64 = int64_t;

class OpInputList {
public:
    size_t size() const;
    const OpInputList& operator[](int) const;
};

class FeatureReaders {
public:
    void reserve(size_t size);
};

string input_order_;

Status BuildRaggedFeatureReader(const OpInputList&, const OpInputList&, FeatureReaders*);
Status BuildSparseFeatureReader(const OpInputList&, const OpInputList&, int64, FeatureReaders*);
Status BuildDenseFeatureReader(const OpInputList&, FeatureReaders*);

#define TF_RETURN_IF_ERROR(expr) \
    do { \
        Status _status = (expr); \
        if (!_status.ok()) return _status; \
    } while (0)

namespace errors {
    Status InvalidArgument(const char* format, ...);
}