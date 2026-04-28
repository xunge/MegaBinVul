#include <vector>
#include <cstddef>

template<typename T> class RefPtr {
public:
    T* operator->() const { return nullptr; }
    T* get() const { return nullptr; }
};

class DOMWindow;

class Event {
public:
    class EventTarget* target() const { return nullptr; }
};

class EventTarget {
public:
    DOMWindow* toDOMWindow();
    void dispatchEvent(const RefPtr<Event>&);
};

class DOMWindow {
public:
    void dispatchEvent(const RefPtr<Event>&, int);
};

template<typename T> class Vector {
public:
    void swap(Vector&) {}
    size_t size() const { return 0; }
    T& operator[](size_t) { static T t; return t; }
};

class ScriptedAnimationController {
public:
    void dispatchEvents();
    Vector<RefPtr<Event>> m_eventQueue;
    std::vector<EventTarget*> m_perFrameEvents;
    std::vector<EventTarget*> m_scheduledEventTargets;
};

inline DOMWindow* EventTarget::toDOMWindow() { return nullptr; }
inline void EventTarget::dispatchEvent(const RefPtr<Event>&) {}
inline void DOMWindow::dispatchEvent(const RefPtr<Event>&, int) {}