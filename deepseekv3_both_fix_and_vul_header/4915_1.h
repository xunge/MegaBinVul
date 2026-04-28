#include <cassert>

#define ENABLE(x) 0
#define ASSERT(x) assert(x)

class Node {
public:
    Node* previousSibling();
    Node* nextSibling();
    bool refCount();
};

class ChildListMutationScope {
public:
    ChildListMutationScope(Node&);
    void childAdded(Node&);
};

class ContainerNode : public Node {
public:
    void updateTreeAfterInsertion(Node&);
    void childrenChanged(bool, Node*, Node*, int);
    void notifyNodeInserted(Node&);
    void dispatchChildInsertionEvents(Node&);
};