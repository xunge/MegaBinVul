#include <vector>
#include <deque>
#include <string>
#include <unordered_set>
#include <cstddef>

using std::string;

class Status {
public:
    static Status OK();
    bool ok() const;
};

class AttrSlice {};

class Edge;
class Node;

class Graph {
public:
    int num_node_ids() const;
    std::vector<Node*> nodes() const;
};

class Node {
public:
    int id() const;
    std::vector<const Edge*> in_edges() const;
    std::vector<const Edge*> out_edges() const;
    const AttrSlice& attrs() const;
};

class Edge {
public:
    Node* dst() const;
};

struct ControlFlowInfo {
    std::vector<std::string> frame_names;
    std::unordered_set<std::string> unique_frame_names;
};

class ImmutableExecutorState {
public:
    Status BuildControlFlowInfo(const Graph* g, ControlFlowInfo* cf_info);
};

namespace errors {
    Status InvalidArgument(const string& message);
}

#define TF_RETURN_IF_ERROR(expr) \
  do { \
    const Status _status = (expr); \
    if (!_status.ok()) return _status; \
  } while (0)

bool IsEnter(Node* node);
bool IsExit(Node* node);
bool IsSink(Node* node);
Status GetNodeAttr(const AttrSlice& attrs, const string& attr_name, string* value);