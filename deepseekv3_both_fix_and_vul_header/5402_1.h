#include <stddef.h>

struct Node {
    bool isShadowRoot() const;
    Node* nonBoundaryShadowTreeRootNode() const;
};

class VisibleSelection {
public:
    struct Position {
        Node* deprecatedNode() const;
    };
    Position start() const;
    Node* nonBoundaryShadowTreeRootNode() const;
};