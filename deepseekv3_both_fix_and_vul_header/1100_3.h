#include <vector>
#include <functional>
#include <memory>
#include <string>
#include <iostream>

#define VLOG(level) std::cout
#define DCHECK(condition) if (!(condition)) std::cerr
#define LOG(severity) std::cerr
#define WARNING 1

class Edge;
class FullTypeDef;

enum DataType {};

template <typename T>
class StatusOr {
 public:
  const T& ValueOrDie() const;
};

class NodeDef {
 public:
  bool has_experimental_type() const;
  const FullTypeDef& experimental_type() const;
  FullTypeDef* mutable_experimental_type();
  std::string DebugString() const;
};

class FullTypeDef {
 public:
  int type_id() const;
  int args_size() const;
  const FullTypeDef& args(int index) const;
  std::string DebugString() const;
};

enum TFT {
  TFT_UNSET
};

struct NodeProperties {
  std::function<StatusOr<FullTypeDef>(const std::vector<std::reference_wrapper<const FullTypeDef>>&)> fwd_type_fn;
  std::vector<DataType> input_types;
  NodeDef node_def;
};

class Node {
 public:
  void RunForwardTypeInference();
  const std::vector<Edge*>& in_edges() const;
  const std::string& name() const;
  const NodeDef& def() const;
  void ClearTypeInfo();
  void MaybeCopyOnWrite();
  std::string DebugString() const;
  
 private:
  NodeProperties* props_;
  std::vector<Edge*> in_edges_;
};

class Edge {
 public:
  bool IsControlEdge() const;
  Node* src() const;
  Node* dst() const;
  int src_output() const;
  int dst_input() const;
};