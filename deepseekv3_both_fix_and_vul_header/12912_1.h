#include <vector>
#include <cmath>
#include <cstdint>

struct DimensionHandle {};
struct ShapeHandle {};
struct InferenceContext {
    int WithRank(ShapeHandle input, int rank, ShapeHandle* output);
    ShapeHandle input(int index);
    int GetAttr(const char* name, std::vector<float>* value);
    DimensionHandle Dim(ShapeHandle shape, int index);
    bool ValueKnown(DimensionHandle d);
    int64_t Value(DimensionHandle d);
    DimensionHandle MakeDim(int64_t val);
    DimensionHandle UnknownDim();
    void set_output(int index, ShapeHandle shape);
    ShapeHandle MakeShape(const std::vector<DimensionHandle>& dims);
    ShapeHandle Vector(DimensionHandle dim);
};

using Status = int;

#define TF_RETURN_IF_ERROR(expr) \
  do {                           \
    int _status = (expr);        \
    if (_status != 0) {          \
      return _status;            \
    }                            \
  } while (0)

#define OkStatus() 0

struct errors {
    static Status InvalidArgument(const char* msg);
    static Status InvalidArgument(const char* msg, float value);
    static Status InvalidArgument(const char* msg, int dim, const char* msg2, int64_t val);
};