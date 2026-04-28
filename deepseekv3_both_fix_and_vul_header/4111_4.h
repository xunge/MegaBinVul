#include <stddef.h>

#define ASSERT(expr) ((void)0)

class Node {
public:
    Node* parentNode();
    bool isDocumentFragment();
    unsigned connectedSubframeCount();
    Node* previousSibling();
    Node* nextSibling();
    void notifyMutationObserversNodeWillDetach();
};

class ChildrenChangeSourceParser {};

class ChildrenChange {
public:
    static ChildrenChange forRemoval(Node& child, Node* prev, Node* next, ChildrenChangeSourceParser source);
};

class ContainerNode : public Node {
public:
    void parserRemoveChild(Node& oldChild);
    void removeBetween(Node* prev, Node* next, Node& oldChild);
    void notifyNodeRemoved(Node& oldChild);
    void childrenChanged(const ChildrenChange& change);
};

class ChildFrameDisconnector {
public:
    ChildFrameDisconnector(Node& node);
    void disconnect();
};

class ChildListMutationScope {
public:
    ChildListMutationScope(ContainerNode& node);
    void willRemoveChild(Node& child);
};

class HTMLFrameOwnerElement {
public:
    class UpdateSuspendScope {
    public:
        UpdateSuspendScope();
        ~UpdateSuspendScope();
    };
};

ChildrenChangeSourceParser ChildrenChangeSourceParser;