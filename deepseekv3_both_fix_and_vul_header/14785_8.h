#include <memory>
#include <cassert>

class Node;
class ContainerNode;
class Document;
class TreeScope;

template<typename T> class PassRefPtrWillBeRawPtr {
public:
    T* operator->() const { return ptr; }
    T* get() const { return ptr; }
    operator bool() const { return ptr; }
    T& operator*() const { return *ptr; }
    bool operator==(const Node* other) const { return ptr == other; }
    friend bool operator==(const Node* a, const PassRefPtrWillBeRawPtr& b) { return a == b.ptr; }
    T* ptr = nullptr;
};

template<typename T> class RefPtrWillBeRawPtr {
public:
    RefPtrWillBeRawPtr(T* p) : ptr(p) {}
    T* operator->() const { return ptr; }
    operator bool() const { return ptr; }
    T* ptr = nullptr;
};

class Document {
public:
    bool operator!=(const Document&) const { return false; }
    void adoptNode(Node*, int) {}
};

class TreeScope {
public:
    void adoptIfNeeded(Node&) {}
};

class Node {
public:
    ContainerNode* parentNode() { return nullptr; }
    Node* previousSibling() { return nullptr; }
    bool isDocumentFragment() { return false; }
    Document& document() { static Document d; return d; }
    void updateAncestorConnectedSubframeCountForInsertion() {}
};

class ContainerNode : public Node {
public:
    void parserInsertBefore(PassRefPtrWillBeRawPtr<Node>, Node&);
    bool checkParserAcceptChild(Node&) { return true; }
    void parserRemoveChild(Node&) {}
    void insertBeforeCommon(Node&, Node&) {}
    void notifyNodeInserted(Node&, int) {}
    static bool isHTMLTemplateElement(ContainerNode*) { return false; }
    TreeScope& treeScope() { static TreeScope t; return t; }
};

struct EventDispatchForbiddenScope {};
struct ScriptForbiddenScope {};
struct ChildListMutationScope {
    ChildListMutationScope(ContainerNode&) {}
    void childAdded(Node&) {}
};

#define ASSERT(expr) assert(static_cast<bool>(expr))
#define ASSERT_NO_EXCEPTION 0
#define ChildrenChangeSourceParser 0