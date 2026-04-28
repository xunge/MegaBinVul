#include <stdbool.h>

typedef struct Node Node;
typedef struct HTMLFrameOwnerElement HTMLFrameOwnerElement;

struct Node {
    Node* parentOrShadowHostNode();
};

struct Document {
    bool unloadStarted();
};

struct HTMLFrameOwnerElement {
    Document& document();
    Node* toNode();
};

inline Node* operator&(HTMLFrameOwnerElement& owner) {
    return owner.toNode();
}

struct HashSet {
    bool contains(Node* node);
};

HashSet& disabledSubtreeRoots();