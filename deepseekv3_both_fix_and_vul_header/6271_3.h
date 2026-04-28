#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using std::string;
using std::vector;
using std::ostringstream;

class Status {
public:
    static Status OK();
    bool ok() const;
};

class AttrSlice;

class Node {
public:
    string type_string() const;
    struct Def {
        const AttrSlice& attrs() const;
    };
    const Def& def() const;
};

class AttrSlice {
public:
    AttrSlice(const Node::Def& def);
};

class StringPiece {
public:
    StringPiece(const string& str);
    bool operator==(const char* str) const;
};

class TensorShapeProto {};

class ShapeHandle {
public:
    bool SameHandle(ShapeHandle other) const;
};

class ShapeAndType {
public:
    ShapeHandle shape;
    int dtype;
    string type;
    ShapeAndType(ShapeHandle s, int d, const string& t) : shape(s), dtype(d), type(t) {}
};

class InferenceContext {
public:
    int num_inputs() const;
    int num_outputs() const;
    ShapeHandle input(int index) const;
    const std::vector<ShapeAndType>* input_handle_shapes_and_types(int index) const;
    void set_output(int index, ShapeHandle handle);
    void set_output_handle_shapes_and_types(int index, const std::vector<ShapeAndType>& shapes_and_types);
    ShapeHandle UnknownShape();
    void ShapeHandleToProto(ShapeHandle handle, TensorShapeProto* proto);
    Status MakeShapeFromShapeProto(const TensorShapeProto& proto, ShapeHandle* handle);
};

class errors {
public:
    static Status Internal(const string& message);
    static Status Internal(const char* msg1, int val1, const char* msg2, int val2, const char* msg3);
};

class ShapeRefiner {
public:
    Status InferShapesForFunctionSubNode(const Node* node, InferenceContext* outer_context);
    Status AddNodeInternal(const Node* node, InferenceContext* outer_context);
    InferenceContext* GetContext(const Node* node);
};

static const char* kArgOp = "_Arg";
static const char* kRetvalOp = "_Retval";

#define TF_RETURN_IF_ERROR(expr) \
    do { \
        const Status _status = (expr); \
        if (!_status.ok()) \
            return _status; \
    } while (0)

#define CHECK_NOTNULL(ptr) \
    ((ptr) == nullptr ? (abort(), (ptr)) : (ptr))

#define VLOG(level) \
    if (false) \
        std::cout

Status GetNodeAttr(const AttrSlice& attrs, const string& attr_name, int* value);