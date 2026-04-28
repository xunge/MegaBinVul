#include <map>
#include <unordered_set>
#include <unordered_map>

class AXTreeUpdateState {
public:
    std::unordered_set<class AXNode*> pending_nodes;
};

class AXNode {
public:
    int id();
    int child_count();
    AXNode* ChildAtIndex(int i);
    void Destroy();
};

class AXTree {
public:
    std::unordered_map<int, AXNode*> id_map_;
    class Delegate {
    public:
        virtual void OnNodeWillBeDeleted(AXNode* node) = 0;
    };
    Delegate* delegate_ = nullptr;
    
    void DestroyNodeAndSubtree(AXNode* node, AXTreeUpdateState* update_state);
    void DestroyNodeAndSubtree(AXNode* node);
};