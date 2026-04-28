#include <vector>
#include <string>
#include <cstdint>
#include <sstream>

using std::string;
using std::vector;
using std::ostringstream;

struct Status {
    bool ok() const { return true; }
    static Status OK() { return Status(); }
};

enum Padding {
    VALID,
    SAME
};

class ShapeHandle {};
class DimensionHandle {};

class InferenceContext {
public:
    Status WithRank(ShapeHandle input, int rank, ShapeHandle* output);
    ShapeHandle input(int index);
    Status GetAttr(const string& attr_name, string* value);
    Status GetAttr(const string& attr_name, vector<int32_t>* value);
    Status GetAttr(const string& attr_name, Padding* value);
    DimensionHandle Dim(ShapeHandle shape, int index);
    int64_t Value(DimensionHandle dim);
    bool ValueKnown(DimensionHandle dim);
    ShapeHandle MakeShape(const vector<DimensionHandle>& dims);
    void set_output(int index, ShapeHandle shape);
};

template <int dims>
int GetTensorDimIndex(int format, char dim) {
    return 0;
}

Status GetWindowedOutputSizeFromDimsV2(InferenceContext* c, DimensionHandle input_size, 
                                     DimensionHandle filter_size, int dilation_rate, 
                                     int stride, Padding padding, int min_size, 
                                     int max_size, DimensionHandle* output_size);

#define TF_RETURN_IF_ERROR(expr) \
    do {                         \
        Status _status = (expr); \
        if (!_status.ok())       \
            return _status;      \
    } while (0)

#define FORMAT_NCHW 0

namespace shape_inference {
    using ::InferenceContext;
}

namespace errors {
    Status InvalidArgument(const string& message) {
        return Status();
    }
    
    template<typename... Args>
    Status InvalidArgument(Args&&... args) {
        ostringstream oss;
        (oss << ... << args);
        return Status();
    }
}

typedef int32_t int32;