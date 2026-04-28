#include <memory>

template<typename T> class RefPtr {
public:
    T* operator->() const { return ptr; }
    T* get() const { return ptr; }
    T* release() { T* tmp = ptr; ptr = nullptr; return tmp; }
private:
    T* ptr = nullptr;
};

class Node {
public:
    // Node implementation
};

class OverflowEvent {
public:
    static RefPtr<OverflowEvent> create(bool, bool, bool, bool) { return RefPtr<OverflowEvent>(); }
    void setTarget(Node*);
};

class Document {
public:
    Node* node();
    void enqueueAnimationFrameEvent(OverflowEvent*);
};

class FrameView {
public:
    void updateOverflowStatus(bool horizontalOverflow, bool verticalOverflow);
    void scheduleOverflowEvent(RefPtr<OverflowEvent>);
    Document* document();
    
    bool m_horizontalOverflow;
    bool m_verticalOverflow;
    bool m_overflowStatusDirty;
    FrameView* m_frame;
    Document* m_viewportRenderer;
};