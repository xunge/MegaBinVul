#include <memory>
#include <string>

class HTMLHtmlElement;
class HTMLHeadElement;
class HTMLMetaElement;
class HTMLVideoElement;
class HTMLSourceElement;
class HTMLBodyElement;
class Document;
class DocumentLoader;
class Frame;

template<typename T> class RefPtrWillBeRawPtr;

struct WillBeGarbageCollectedMixin {};
template<typename T> class RefCounted : public WillBeGarbageCollectedMixin {};

class AtomicString {
public:
    AtomicString(const char*);
};

extern AtomicString nameAttr;
extern AtomicString contentAttr;
extern AtomicString controlsAttr;
extern AtomicString autoplayAttr;

class Node : public RefCounted<Node> {
public:
    void appendChild(Node*);
};

class Element : public Node {
public:
    void setAttribute(const AtomicString&, const AtomicString&);
    void insertedByParser();
};

class HTMLHtmlElement : public Element {
public:
    static RefPtrWillBeRawPtr<HTMLHtmlElement> create(Document&);
};

class HTMLHeadElement : public Element {
public:
    static RefPtrWillBeRawPtr<HTMLHeadElement> create(Document&);
};

class HTMLMetaElement : public Element {
public:
    static RefPtrWillBeRawPtr<HTMLMetaElement> create(Document&);
};

class HTMLVideoElement : public Element {
public:
    static RefPtrWillBeRawPtr<HTMLVideoElement> create(Document&);
};

class HTMLSourceElement : public Element {
public:
    static RefPtrWillBeRawPtr<HTMLSourceElement> create(Document&);
    void setSrc(const std::string&);
    void setType(const std::string&);
};

class HTMLBodyElement : public Element {
public:
    static RefPtrWillBeRawPtr<HTMLBodyElement> create(Document&);
};

class Document : public Node {
public:
    Frame* frame();
    DocumentLoader* loader();
    std::string url();
    bool isDetached();
    Document* document();
};

class Frame {
public:
    struct Loader {
        void dispatchDocumentElementAvailable();
        void runScriptsAtDocumentElementAvailable();
    };
    Loader& loader();
};

class DocumentLoader {
public:
    std::string responseMIMEType();
};

class MediaDocumentParser {
public:
    Document* document();
    bool isDetached();
    bool m_didBuildDocumentStructure;
    void createDocumentStructure();
};

#define ASSERT(expr) ((void)0)

template<typename T>
class RefPtrWillBeRawPtr {
public:
    RefPtrWillBeRawPtr(T*);
    T* operator->();
    T* release();
    T* get() const;
    operator T*() const { return get(); }
};