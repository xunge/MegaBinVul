#include <stddef.h>

class String {
public:
    bool isEmpty() const;
    const char* string() const;
    String(const char*);
};

class AtomicString {
public:
    bool isEmpty() const;
    bool operator==(const char*) const;
};

class Frame;
class DOMWindow;
class FloatRect;
class WindowFeatures;

template<typename T> class PassRefPtr {
public:
    PassRefPtr(T* ptr = 0) : m_ptr(ptr) {}
    operator T*() const { return m_ptr; }
    T* operator->() const { return m_ptr; }
    T* get() const { return m_ptr; }
private:
    T* m_ptr;
};

class FrameTree {
public:
    Frame* find(const AtomicString&) const;
    Frame* parent() const;
    Frame* top() const;
};

class Page {
public:
    Frame* mainFrame() const;
};

class View;

class WindowFeatures {
public:
    bool xSet;
    bool ySet;
    bool widthSet;
    bool heightSet;
    float x;
    float y;
    float width;
    float height;
    WindowFeatures(const String&);
};

class DOMWindow {
public:
    Frame* frame() const;
    bool allowPopUp() const;
    static void adjustWindowRect(const FloatRect&, const FloatRect&, FloatRect&);
    static bool isInsecureScriptAccess(DOMWindow*, const String&);
    PassRefPtr<DOMWindow> open(const String&, const AtomicString&, const String&, DOMWindow*, DOMWindow*);
    static Frame* createWindow(const String&, const AtomicString&, const WindowFeatures&, DOMWindow*, Frame*, Frame*);
    Frame* m_frame;
};

class Loader {
public:
    String outgoingReferrer() const;
    bool shouldAllowNavigation(Frame*) const;
};

class Document {
public:
    String completeURL(const String&) const;
    class SecurityOrigin* securityOrigin() const;
};

class ScriptController {
public:
    bool anyPageIsProcessingUserGesture() const;
};

class NavigationScheduler {
public:
    void scheduleLocationChange(class SecurityOrigin*, const String&, const String&, bool, bool);
};

class Frame {
public:
    FrameTree* tree() const;
    Page* page() const;
    DOMWindow* domWindow() const;
    Loader* loader() const;
    Document* document() const;
    ScriptController* script() const;
    NavigationScheduler* navigationScheduler() const;
    View* view() const;
};

class FloatRect {
public:
    FloatRect(float x, float y, float width, float height);
    float x() const;
    float y() const;
    float width() const;
    float height() const;
};

FloatRect screenAvailableRect(View*);