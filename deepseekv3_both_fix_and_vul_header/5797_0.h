#include <cstdlib>

struct AXNode;
struct AXTree {
    AXNode* root_;
    void DestroyNodeAndSubtree(AXNode* node, void*);
    void DestroyNodeAndSubtree(AXNode* node);
    ~AXTree();
};