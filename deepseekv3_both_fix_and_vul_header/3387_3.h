#include <memory>

class Node {
public:
    bool isDocumentNode() const;
};

class Event {
public:
    static Event* create(const char* type);
    static Event* createBubble(const char* type);
    void setTarget(Node* target);
    void deref();
};

namespace EventTypeNames {
    const char* const scroll = "scroll";
}

template<typename T> class RefPtr {
public:
    RefPtr(T* ptr) : m_ptr(ptr) {}
    ~RefPtr() { if (m_ptr) m_ptr->deref(); }
    T* release() { T* ptr = m_ptr; m_ptr = nullptr; return ptr; }
    T* get() const { return m_ptr; }
    T* operator->() const { return m_ptr; }
private:
    T* m_ptr;
};

class ScriptedAnimationController {
public:
    void enqueuePerFrameEvent(Event* event);
};

class Document {
public:
    void enqueueScrollEventForNode(Node* target);
    ScriptedAnimationController& ensureScriptedAnimationController();
    void scheduleAnimationFrameEvent(Event* event);
};