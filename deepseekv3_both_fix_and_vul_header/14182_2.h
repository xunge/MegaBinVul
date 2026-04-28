#include <cstddef>
#include <memory>

struct Status {
  static Status OK();
  bool ok() const;
};

class ShapeHandle {};

class InferenceContext {
public:
  Status WithRank(ShapeHandle input, int rank, ShapeHandle* out);
  ShapeHandle Dim(ShapeHandle input, int dim);
  ShapeHandle UnknownDim();
  ShapeHandle Matrix(ShapeHandle dim0, ShapeHandle dim1);
  ShapeHandle Vector(ShapeHandle dim);
  ShapeHandle input(int index);
  void set_output(int index, ShapeHandle shape);
};

#define TF_RETURN_IF_ERROR(expr) \
  do {                           \
    const Status _status = (expr); \
    if (!_status.ok())           \
      return _status;            \
  } while (0)