#include <stddef.h>
#include <stdint.h>

#define ENABLE(OILPAN) 0
#define ASSERT(expr) ((void)0)

class Node {
public:
    virtual ~Node() = default;
    virtual Node* parentNode() = 0;
    virtual bool isPseudoElement() = 0;
    virtual Node* previousSibling() = 0;
    virtual Node* nextSibling() = 0;
};

class ExceptionState {
public:
    void throwDOMException(int code, const char* message);
};

class Document {
public:
    void removeFocusedElementOfSubtree(Node* node);
    class FullscreenElementStack* fullscreenElementStack();
};

class FullscreenElementStack {
public:
    static FullscreenElementStack* fromIfExists(Document& doc);
    void removeFullScreenElementOfSubtree(Node* node);
};

class HTMLFrameOwnerElement {
public:
    class UpdateSuspendScope {
    public:
        UpdateSuspendScope();
        ~UpdateSuspendScope();
    };
};

template<typename T> class RefPtrWillBeRawPtr {
    T* m_ptr;
public:
    RefPtrWillBeRawPtr(T* ptr) : m_ptr(ptr) {}
    T* get() { return m_ptr; }
    T* operator->() { return m_ptr; }
    T& operator*() { return *m_ptr; }
};

class ContainerNode : public Node {
public:
    void removeChild(Node* oldChild, ExceptionState& exceptionState);
    Node* parentOrShadowHostNode();
    size_t refCount();
    Document& document();
    void willRemoveChild(Node& child);
    void removeBetween(Node* prev, Node* next, Node& child);
    void notifyNodeRemoved(Node& child);
    void childrenChanged(bool changed, Node* prev, Node* next, int delta);
    void dispatchSubtreeModifiedEvent();
    Node* parentNode() override;
};

enum DOMExceptionCode {
    NotFoundError
};