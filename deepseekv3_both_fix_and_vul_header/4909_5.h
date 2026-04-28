#include <memory>
#include <cassert>

template<typename T> class PassRefPtrWillBeRawPtr {
public:
    T* get();
    T* operator->();
    operator T*();
};

template<typename T> class RefPtrWillBeRawPtr {
public:
    RefPtrWillBeRawPtr(T*);
    T* operator->();
};

class Node;

class Document {
public:
    void adoptNode(Node*, int);
    bool operator!=(const Document&) const;
    Document& document();
};

class TreeScope {
public:
    void adoptIfNeeded(Node&);
};

class Node {
public:
    Node* parentNode();
    bool isDocumentFragment();
    Document& document();
    void updateAncestorConnectedSubframeCountForInsertion();
};

class ContainerNode : public Node {
public:
    void parserAppendChild(PassRefPtrWillBeRawPtr<Node> newChild);
    TreeScope& treeScope();
    Document& document();
    void appendChildToContainer(Node&, ContainerNode&);
    void notifyNodeInserted(Node&);
    void notifyNodeInserted(Node&, int);
    void childrenChanged(bool, Node*, int, int);
    Node* m_lastChild;
    bool isHTMLTemplateElement(ContainerNode*);
};

class NoEventDispatchAssertion {};
class ScriptForbiddenScope {};
class ChildListMutationScope {
public:
    ChildListMutationScope(ContainerNode&);
    void childAdded(Node&);
};

#define ASSERT(expr) assert(expr)
#define ASSERT_NO_EXCEPTION 0

enum { InsertedByParser };