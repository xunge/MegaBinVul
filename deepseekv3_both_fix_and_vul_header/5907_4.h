#include <cassert>

class Node {
public:
    Node* parentNode();
    bool isDocumentFragment();
    Node* previousSibling();
    Node* nextSibling();
    unsigned connectedSubframeCount();
    void notifyMutationObserversNodeWillDetach();
};

class ContainerNode;

class ChildFrameDisconnector {
public:
    explicit ChildFrameDisconnector(Node& node);
    void disconnect();
};

class ChildListMutationScope {
public:
    explicit ChildListMutationScope(ContainerNode& node);
    void willRemoveChild(Node& child);
};

struct ChildrenChangeSourceParser {};

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

#define ASSERT(expr) assert(expr)

ChildrenChangeSourceParser ChildrenChangeSourceParser;