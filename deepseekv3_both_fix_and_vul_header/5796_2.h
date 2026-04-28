#include <stdlib.h>

struct AXNode;
struct AXTreeUpdateState;
class AXDelegate {
public:
    void OnSubtreeWillBeDeleted(AXNode* node);
};
class AXTree {
public:
    void DestroySubtree(AXNode* node, AXTreeUpdateState* update_state);
    void DestroySubtree(AXNode* node);
    void DestroyNodeAndSubtree(AXNode* node, AXTreeUpdateState* update_state);
    void DestroyNodeAndSubtree(AXNode* node);
    AXDelegate* delegate_;
};