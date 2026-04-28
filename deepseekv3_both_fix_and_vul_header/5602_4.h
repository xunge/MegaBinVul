#include <cstddef>
#include <cassert>

#define ASSERT assert

class Node;

struct ChildrenChange {
    enum Source { ChildrenChangeSourceParser };
    static ChildrenChange forRemoval(Node&, Node*, Node*, Source);
};

class ContainerNode;

class ChildListMutationScope {
public:
    explicit ChildListMutationScope(ContainerNode&);
    void willRemoveChild(Node&);
};

class ChildFrameDisconnector {
public:
    explicit ChildFrameDisconnector(Node&);
    void disconnect();
};

class Node {
public:
    ContainerNode* parentNode();
    bool isDocumentFragment();
    Node* previousSibling();
    Node* nextSibling();
    unsigned connectedSubframeCount();
    void updateAncestorConnectedSubframeCountForRemoval();
    void notifyMutationObserversNodeWillDetach();
};

class ContainerNode {
public:
    void parserRemoveChild(Node& oldChild);
    void removeBetween(Node* prev, Node* next, Node& oldChild);
    void notifyNodeRemoved(Node& oldChild);
    void childrenChanged(const ChildrenChange& change);
};

constexpr ChildrenChange::Source ChildrenChangeSourceParser = ChildrenChange::ChildrenChangeSourceParser;