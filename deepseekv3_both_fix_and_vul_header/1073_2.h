#include <stddef.h>

typedef struct Status {
    static Status OK();
} Status;

typedef struct NodeDef NodeDef;

struct ShapeHandle {};

namespace shape_inference {
    typedef ::ShapeHandle ShapeHandle;
}

typedef struct InferenceContext {
    int num_outputs();
    void set_output(int, ShapeHandle);
} InferenceContext;

namespace errors {
    Status InvalidArgument(const char*);
    Status InvalidArgument(const char*, int, const char*, int);
}

shape_inference::ShapeHandle GetUnknownOutputShape(const NodeDef* node, int output_port);
InferenceContext* GetContext(const NodeDef* node);