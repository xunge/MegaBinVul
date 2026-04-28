#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include <utility>
#include <iostream>
#include <sstream>

struct Status {
    bool ok;
    std::string error_message;
};

struct AttrSlice {
    AttrSlice(const void*) {}
};

struct GraphDef {
    struct Library {
        int function_size() const { return 0; }
        const Library& operator=(const GraphDef&) { return *this; }
    };
    Library library_;
    Library* mutable_library() { return &library_; }
    const Library& library() const { return library_; }
};

struct OpDef {
    struct AttrDef {
        std::string type_value;
        const std::string& type() const { return type_value; }
    };
    std::string name() const { return ""; }
    std::string description() const { return ""; }
    bool is_stateful() const { return false; }
    const std::vector<AttrDef>& attr() const { static std::vector<AttrDef> v; return v; }
};

struct FunctionDef {
    struct signature_type : public OpDef {};
    const signature_type& signature() const { static signature_type s; return s; }
    struct attr_type {};
    const attr_type& attr() const { static attr_type a; return a; }
    struct control_ret_type {
        std::string first;
        std::string second;
    };
    const std::vector<control_ret_type>& control_ret() const { static std::vector<control_ret_type> v; return v; }
    struct ArgAttrs {};
    const std::vector<std::pair<int, ArgAttrs>>& arg_attr() const { static std::vector<std::pair<int, ArgAttrs>> v; return v; }
    int control_ret_size() const { return 0; }
};

struct FunctionLibraryDefinition {
    int num_functions() const { return 0; }
    struct ReachableDefinitions {
        GraphDef ToProto() const { return GraphDef(); }
        ReachableDefinitions() = default;
    };
    ReachableDefinitions ReachableDefinitions(const FunctionDef&) const { return {}; }
};

struct DataType {};

struct Node {
    std::string name() const { return ""; }
};

struct FunctionBody {
    struct graph_type {
        void ToGraphDef(GraphDef*) {}
    } *graph;
    std::vector<DataType> arg_types;
    std::vector<DataType> ret_types;
    std::vector<const Node*> arg_nodes;
    std::vector<const Node*> ret_nodes;
};

struct InputArgInstantiation {
    InputArgInstantiation(const std::string&, const DataType&) {}
};

struct OutputArgInstantiation {
    OutputArgInstantiation(const std::string&, const DataType&) {}
};

struct ControlOutput {
    ControlOutput(const std::string&, const std::string&) {}
    bool operator<(const ControlOutput&) const { return false; }
};

struct GrapplerFunctionItem {
    GrapplerFunctionItem(const std::string&, const std::string&, AttrSlice, 
                        std::vector<const FunctionDef::ArgAttrs*>, 
                        std::vector<InputArgInstantiation>, 
                        std::vector<OutputArgInstantiation>, 
                        std::vector<ControlOutput>, 
                        int, bool, GraphDef) {}
};

Status FunctionDefToBodyHelper(const FunctionDef&, const AttrSlice&, 
                              const FunctionLibraryDefinition*, 
                              std::unique_ptr<FunctionBody>*) {
    return Status{true, ""};
}

Status OkStatus() {
    return Status{true, ""};
}

namespace errors {
    Status InvalidArgument(const std::string& msg) {
        return Status{false, msg};
    }
    Status InvalidArgument(const std::string& msg1, int val, const std::string& msg2, size_t size) {
        std::ostringstream oss;
        oss << msg1 << val << msg2 << size;
        return Status{false, oss.str()};
    }
}

#define TF_RETURN_IF_ERROR(expr) \
    do { \
        Status _status = (expr); \
        if (!_status.ok) return _status; \
    } while (0)

#define VLOG(x) std::cout

namespace absl {
    std::string Substitute(const std::string&, int, const std::string&, int) {
        return "";
    }
}