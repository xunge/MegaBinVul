#include <vector>
#include <memory>

class NodeVector;

class Node {
public:
    enum InsertionNotificationType {
        InsertionShouldCallDidNotifySubtreeInsertions
    };
    virtual InsertionNotificationType insertedInto(class ContainerNode*);
    virtual bool isContainerNode() const;
    virtual bool inDocument() const;
    virtual bool isInShadowTree() const;
    virtual class ShadowRoot* youngestShadowRoot();
    virtual class ShadowRoot* olderShadowRoot();
    virtual ~Node() = default;
};

class ShadowRoot : public Node {};

class ContainerNode : public Node {
public:
    virtual bool inDocument() const override;
    virtual bool isInShadowTree() const override;
    virtual void notifyNodeInsertedInternal(Node&, NodeVector&);
};

class EventDispatchForbiddenScope {};
class ScriptForbiddenScope {};

class NodeTraversal {
public:
    static std::vector<std::reference_wrapper<Node>> inclusiveDescendantsOf(Node&);
};

class NodeVector : public std::vector<Node*> {
public:
    void append(Node* node) { push_back(node); }
};