#include <string>

class String {
public:
    String();
    String(const char*);
    ~String();
};

class KURL {
public:
    KURL();
    KURL(const String&);
    ~KURL();
    bool isNull() const;
};

class Frame {
public:
    class Loader {
    public:
        bool shouldAllowNavigation(Frame*);
        String outgoingReferrer();
    };
    class Document {
    public:
        KURL completeURL(const String&);
        class SecurityOrigin {
        public:
            SecurityOrigin();
            ~SecurityOrigin();
        };
        SecurityOrigin* securityOrigin();
    };
    class Script {
    public:
        bool anyPageIsProcessingUserGesture();
    };
    class NavigationScheduler {
    public:
        void scheduleLocationChange(Document::SecurityOrigin*, const KURL&, const String&, bool, bool);
    };

    Loader* loader();
    Document* document();
    Script* script();
    NavigationScheduler* navigationScheduler();
};

enum SetLocationLocking {
    LockHistoryBasedOnGestureState
};

class DOMWindow {
public:
    void setLocation(const String&, DOMWindow*, DOMWindow*, SetLocationLocking);
    Frame* frame();
    Frame* m_frame;
    bool isInsecureScriptAccess(DOMWindow*, const KURL&);
    bool isInsecureScriptAccess(DOMWindow*, const String&);
};