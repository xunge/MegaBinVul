#include <vector>
#include <cstdint>

using DimensionHandle = void*;
using ShapeHandle = void*;
struct Status {
    static Status OK();
    bool operator!=(const Status&) const;
};
struct Tensor {
    int dtype() const;
    int64_t NumElements() const;
};
class InferenceContext {
public:
    ShapeHandle input(int);
    const Tensor* input_tensor(int);
    DimensionHandle NumElements(ShapeHandle);
    bool RankKnown(ShapeHandle);
    bool ValueKnown(DimensionHandle);
    void set_output(int, ShapeHandle);
    int64_t Rank(ShapeHandle);
    int64_t Value(DimensionHandle);
    Status WithRank(ShapeHandle, int64_t, ShapeHandle*);
    Status WithValue(DimensionHandle, int64_t, DimensionHandle*);
    ShapeHandle UnknownShape();
    ShapeHandle MakeShape(const std::vector<DimensionHandle>&);
    DimensionHandle Dim(ShapeHandle, int64_t);
    DimensionHandle UnknownDim();
};

#define TF_RETURN_IF_ERROR(expr) \
  do {                           \
    Status _status = (expr);     \
    if (_status != Status::OK()) { \
      return _status;            \
    }                            \
  } while (0)

#define DT_INT32 0

namespace errors {
Status InvalidArgument(const char*, ...);
}

template <typename T>
std::vector<int64_t> AsInt64(const Tensor*, int64_t);

inline Status Status::OK() { return Status(); }
inline bool Status::operator!=(const Status& other) const { return this != &other; }
typedef int32_t int32;