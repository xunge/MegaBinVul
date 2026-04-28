#include <cassert>

#define ASSERT(expr) assert(expr)

class ScriptForbiddenScope {
public:
    ScriptForbiddenScope();
    ~ScriptForbiddenScope();
};

class ContainerNode;

class Node {
public:
    ContainerNode* parentNode();
    bool isDocumentFragment();
    Node* previousSibling();
    Node* nextSibling();
    void updateAncestorConnectedSubframeCountForRemoval();
    void notifyMutationObserversNodeWillDetach();
};

class ChildListMutationScope {
public:
    explicit ChildListMutationScope(ContainerNode& node);
    void willRemoveChild(Node& oldChild);
};

class ContainerNode {
public:
    void parserRemoveChild(Node& oldChild);
    void removeBetween(Node* prev, Node* next, Node& oldChild);
    void notifyNodeRemoved(Node& oldChild);
    void childrenChanged(bool change, Node* prev, Node* next, int count);
};