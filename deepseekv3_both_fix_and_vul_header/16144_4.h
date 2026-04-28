#include <string>
#include <vector>
#include <map>
#include <sstream>

class AttrValue;
class TensorProto;
class TensorShapeProto;
class FunctionDefLibrary;

class Status {
public:
    static Status OK();
};

class PartialTensorShape {
public:
    PartialTensorShape(const TensorShapeProto& proto);
    int num_elements() const;
};

class AttrValue {
public:
    bool has_tensor() const;
    const TensorProto& tensor() const;
};

class TensorProto {
public:
    const TensorShapeProto& tensor_shape() const;
};

class NodeDefInterface {
public:
    virtual const std::map<std::string, AttrValue>& attr() const = 0;
    virtual std::string name() const = 0;
    virtual std::string op() const = 0;
    virtual ~NodeDefInterface() = default;
};

class GraphDef {
public:
    class Node : public NodeDefInterface {
    public:
        const std::map<std::string, AttrValue>& attr() const override;
        std::string name() const override;
        std::string op() const override;
    };
    const std::vector<Node>& node() const;
    bool has_library() const;
    const FunctionDefLibrary& library() const;
};

class FunctionDefLibrary {
public:
    class FunctionDef {
    public:
        class NodeDef : public NodeDefInterface {
        public:
            const std::map<std::string, AttrValue>& attr() const override;
            std::string name() const override;
            std::string op() const override;
        };
        const std::vector<NodeDef>& node_def() const;
    };
    const std::vector<FunctionDef>& function() const;
};

namespace errors {
    template<typename... Args>
    Status FailedPrecondition(Args&&... args) {
        std::ostringstream oss;
        (oss << ... << std::forward<Args>(args));
        return Status();
    }
}

Status ValidateNode(const NodeDefInterface& node);
Status TF_RETURN_IF_ERROR(Status status);