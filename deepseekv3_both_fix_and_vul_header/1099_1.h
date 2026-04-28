#include <string>
#include <vector>

#define TF_RETURN_IF_ERROR(expr) (expr)

struct NodeDef {
};

struct FunctionDef {
  std::vector<NodeDef> node_def() const;
};

struct FunctionDefLibrary {
  std::vector<FunctionDef> function() const;
};

struct GraphDef {
  std::vector<NodeDef> node() const;
  bool has_library() const;
  FunctionDefLibrary library() const;
};

struct Status {
  static Status OK();
};

Status ValidateNode(const NodeDef& node);
Status ValidateFunctionNotRecursive(const FunctionDef& function);