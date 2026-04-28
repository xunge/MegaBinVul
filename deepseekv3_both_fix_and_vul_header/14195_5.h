#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::map;
using std::set;

#define INFO 0
#define VLOG(level) std::cout
#define LOG(severity) std::cout
#define TF_RETURN_IF_ERROR(expr) do { if (!(expr).ok()) return (expr); } while (0)

namespace error {
const int INVALID_ARGUMENT = 0;
}

class NodeDef {
public:
    string name() const { return ""; }
    string op() const { return ""; }
    string input(int i) const { return ""; }
    string* mutable_input(int i) { return nullptr; }
};

class GraphDef {
public:
    int node_size() const { return 0; }
    const NodeDef& node(int i) const { static NodeDef n; return n; }
    NodeDef* mutable_node(int i) { return nullptr; }
};

class GrapplerItem {
public:
    GraphDef graph;
    vector<string> fetch;
    vector<string> init_ops;
    vector<NodeDef*> MainVariables() const { return {}; }
};

struct Status {
    Status() : ok_(true) {}
    Status(int code, const string& message) : ok_(false), code_(code), message_(message) {}
    static Status OK() { return Status(); }
    bool ok() const { return ok_; }
    bool ok_;
    int code_;
    string message_;
};

int GetNumAvailableGPUs() { return 0; }
string NodeName(const string& name) { return ""; }
bool IsDequeueOp(const NodeDef& node) { return false; }

class AutoParallel {
public:
    Status Initialize(const GrapplerItem& item);

private:
    int num_gpus_;
    const GrapplerItem* item_;
    GraphDef graph_;
    map<string, NodeDef*> all_nodes_;
    set<string> apply_gradients_nodes_;
    set<string> replica_nodes_;
    set<string> shared_nodes_;

    NodeDef* AddNodeDivConst() { return nullptr; }
    NodeDef* AddNodeDiv(const string& name, const string& input_a,
                       const string& input_b) { return nullptr; }
    Status ComputeTransitiveFanin(const GraphDef& graph,
                                const vector<string>& fetch_nodes,
                                vector<const NodeDef*>* fanin) { return Status::OK(); }
    Status ComputeTransitiveFanin(const GraphDef& graph,
                                const vector<string>& fetch_nodes,
                                const vector<string>& boundary_nodes,
                                vector<const NodeDef*>* fanin) { return Status::OK(); }
};