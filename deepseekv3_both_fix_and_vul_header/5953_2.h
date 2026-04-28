#include <cassert>
#include <string>

class String {
public:
    String();
    String(const char*);
};

class KURL {
public:
    KURL();
    KURL(const String&);
    bool isEmpty() const;
    String string() const;
};

class Frame;
class Page;
class Document;
class SecurityOrigin;

class HTMLPlugInImageElement {
public:
    Document* document() const;
    Frame* contentFrame() const;
    Document* contentDocument() const;
    bool allowedToLoadFrameURL(const String& url);
};

class Document {
public:
    Frame* frame() const;
    KURL completeURL(const String& url) const;
    SecurityOrigin* securityOrigin() const;
    KURL url() const;
};

class Frame {
public:
    Page* page() const;
    Document* document() const;
    Frame* tree() const;
    Frame* parent() const;
};

class Page {
public:
    static int maxNumberOfFrames;
    int frameCount() const;
};

class SecurityOrigin {
public:
    bool canAccess(const SecurityOrigin*) const;
};

bool protocolIsJavaScript(const KURL&);
bool equalIgnoringFragmentIdentifier(const KURL&, const KURL&);

#define ASSERT(expr) assert(expr)