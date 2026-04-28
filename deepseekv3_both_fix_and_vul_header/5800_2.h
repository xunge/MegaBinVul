#include <vector>
#include <string>
#include <set>

class AXNode;

enum AXRole {
  AX_ROLE_ROOT_WEB_AREA
};

struct AXNodeData {
  int id;
  AXRole role;
  std::vector<int> child_ids;
};

struct AXTreeUpdateState {
  std::set<AXNode*> pending_nodes;
  std::set<AXNode*> new_nodes;
  AXNode* new_root;
};

class AXTreeDelegate {
public:
  virtual void OnNodeChanged(AXNode* node) = 0;
};

class AXTree {
public:
  AXNode* root_;
  std::string error_;
  AXTreeDelegate* delegate_;

  bool UpdateNode(const AXNodeData& src, AXTreeUpdateState* update_state);
  AXNode* GetFromId(int id);
  AXNode* CreateNode(AXNode* parent, int id, int index);
  void DestroySubtree(AXNode* node, AXTreeUpdateState* update_state);
  void DestroySubtree(AXNode* node);
  bool DeleteOldChildren(AXNode* node, const std::vector<int>& child_ids, AXTreeUpdateState* update_state);
  bool DeleteOldChildren(AXNode* node, const std::vector<int>& child_ids);
  bool CreateNewChildVector(AXNode* parent, const std::vector<int>& child_ids, std::vector<AXNode*>* new_children, AXTreeUpdateState* update_state);
};

class AXNode {
public:
  void SetData(const AXNodeData& src);
  void SwapChildren(const std::vector<AXNode*>& new_children);
  int id() const;
};

namespace base {
std::string StringPrintf(const char* format, ...);
}