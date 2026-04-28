#include <string>
#include <memory>

class String {
public:
    bool isEmpty() const;
};

class AtomicString {
public:
    bool isEmpty() const;
    bool operator==(const char*) const;
};

class DOMWindow;
class Document;
class SecurityOrigin;
class ScriptController;
class NavigationScheduler;
class Loader;
class Page;
class View;

class KURL {
public:
    String string() const;
    operator String() const;
};

class FloatRect {
public:
    FloatRect(float x, float y, float width, float height);
    float x() const;
    float y() const;
    float width() const;
    float height() const;
};

class Frame {
public:
    class Tree {
    public:
        Frame* find(const AtomicString&) const;
        Frame* top() const;
        Frame* parent() const;
    };
    
    Tree* tree() const;
    DOMWindow* domWindow() const;
    Document* document() const;
    Loader* loader() const;
    ScriptController* script() const;
    Page* page() const;
    NavigationScheduler* navigationScheduler() const;
    View* view() const;
};

class Document {
public:
    KURL completeURL(const String&) const;
    SecurityOrigin* securityOrigin() const;
};

class SecurityOrigin {};

class ScriptController {
public:
    bool anyPageIsProcessingUserGesture() const;
};

class NavigationScheduler {
public:
    void scheduleLocationChange(SecurityOrigin*, const String&, const String&, bool, bool);
};

class Loader {
public:
    String outgoingReferrer() const;
    bool shouldAllowNavigation(Frame*) const;
};

class Page {
public:
    Frame* mainFrame() const;
};

class View {};

struct WindowFeatures {
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

template<typename T> class PassRefPtr {
public:
    PassRefPtr(T* = 0);
    T* operator->() const;
    operator T*() const;
};

class DOMWindow {
public:
    Frame* frame() const;
    bool allowPopUp() const;
    bool isInsecureScriptAccess(DOMWindow*, const String&);
    bool isInsecureScriptAccess(DOMWindow*, const KURL&);
    static void adjustWindowRect(const FloatRect&, FloatRect&, FloatRect&);
    PassRefPtr<DOMWindow> open(const String&, const AtomicString&, const String&, DOMWindow*, DOMWindow*);
    Frame* m_frame;
};

Frame* createWindow(const String&, const AtomicString&, const WindowFeatures&, DOMWindow*, Frame*, Frame*);
FloatRect screenAvailableRect(View*);