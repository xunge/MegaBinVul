#include <string>
#include <map>
#include <utility>

enum DataType {};

struct AttrValue {
    DataType type() const;
    void set_type(DataType type);
};

class NodeDef {
public:
    std::string op() const;
    void set_op(const std::string& op);
    const std::map<std::string, AttrValue>& attr() const;
    std::map<std::string, AttrValue>* mutable_attr();
    std::string input(int index) const;
    std::string* mutable_input(int index);
    void EraseRegularNodeAttributes();
};

void EraseRegularNodeAttributes(NodeDef* node) {
    node->EraseRegularNodeAttributes();
}

class GraphProperties {};

class Status {
public:
    bool ok() const;
    explicit operator bool() const;
};

Status IsSimplifiableReshape(const NodeDef& node, const GraphProperties& properties);

std::string AsControlDependency(const std::string& input);

class ConstantFolding {
public:
    bool SimplifyReshape(const GraphProperties& properties, bool use_shape_info, NodeDef* node);
};