#include <memory>
#include <stdexcept>

template<typename T> class PassRefPtrWillBeRawPtr {
public:
    PassRefPtrWillBeRawPtr(T* ptr) : m_ptr(ptr) {}
    T* get() const { return m_ptr; }
    T* operator->() const { return m_ptr; }
    operator T*() const { return m_ptr; }
    T& operator*() const { return *m_ptr; }
private:
    T* m_ptr;
};

class Node;
class Document;

class ChildListMutationScope {
public:
    ChildListMutationScope(Node&) {}
    void childAdded(Node&) {}
};

#define ASSERT(expr) ((void)0)
#define ASSERT_NO_EXCEPTION 0
#define InsertedByParser 0

template<typename T>
class RefPtrWillBeRawPtr {
public:
    RefPtrWillBeRawPtr(T* ptr) : m_ptr(ptr) {}
    T* get() const { return m_ptr; }
    T* operator->() const { return m_ptr; }
private:
    T* m_ptr;
};

class Document {
public:
    void adoptNode(Node*, int) {}
    Document& document() { return *static_cast<Document*>(nullptr); }
    bool operator!=(const Document&) const { return false; }
};

class Node {
public:
    Node* parentNode() { return nullptr; }
    Node* previousSibling() { return nullptr; }
    bool isDocumentFragment() { return false; }
    void updateAncestorConnectedSubframeCountForInsertion() {}
    Document& document() { return *static_cast<Document*>(nullptr); }
    bool operator==(Node*) const { return false; }
};

class ContainerNode : public Node {
public:
    void parserInsertBefore(PassRefPtrWillBeRawPtr<Node>, Node&);
    void insertBeforeCommon(Node&, Node&) {}
    void childrenChanged(bool, Node*, Node*, int) {}
    void notifyNodeInserted(Node&) {}
    void notifyNodeInserted(Node&, int) {}
    bool isHTMLTemplateElement(ContainerNode*) { return false; }
};