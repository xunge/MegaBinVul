#include <string>

class Status {
public:
    Status() {}
    Status(const Status&) {}
    bool ok() const { return true; }
    int code() const { return 0; }
    static Status OK() { return Status(); }
};

namespace error {
    const int NOT_FOUND = 0;
}

namespace errors {
    Status InvalidArgument(const char*, int);
}

class DimensionHandle {
public:
    DimensionHandle() {}
};

class ShapeHandle {
public:
    ShapeHandle() {}
};

class InferenceContext {
public:
    Status GetAttr(const std::string&, int*) { return Status::OK(); }
    Status WithRank(ShapeHandle, int, ShapeHandle*) { return Status::OK(); }
    Status WithRankAtLeast(ShapeHandle, int, ShapeHandle*) { return Status::OK(); }
    Status Merge(DimensionHandle, DimensionHandle, DimensionHandle*) { return Status::OK(); }
    ShapeHandle input(int) { return ShapeHandle(); }
    DimensionHandle Dim(ShapeHandle, int) { return DimensionHandle(); }
    void set_output(int, ShapeHandle) {}
};

namespace shape_inference {
    Status UnchangedShape(InferenceContext*) { return Status::OK(); }
}

#define TF_RETURN_IF_ERROR(expr) \
    do {                         \
        Status _status = (expr); \
        if (!_status.ok())       \
            return _status;     \
    } while (0)

namespace errors {
    Status InvalidArgument(const char*, int) { return Status(); }
}