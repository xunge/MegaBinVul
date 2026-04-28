#include <memory>

class Document;
class ScriptRunner;

class SVGElement {
public:
    void didMoveToNewDocument(Document& oldDocument);
};

template<typename T> class RefPtrWillBeRawPtr {
    T* m_ptr;
public:
    RefPtrWillBeRawPtr(T* ptr = nullptr) : m_ptr(ptr) {}
    T* get() const { return m_ptr; }
    operator bool() const { return m_ptr; }
    T* operator->() const { return m_ptr; }
};

class SVGScriptElement : public SVGElement {
    std::shared_ptr<ScriptRunner> m_loader;
public:
    Document& document();
    void didMoveToNewDocument(Document& oldDocument);
};

class Document {
public:
    ScriptRunner* scriptRunner();
    RefPtrWillBeRawPtr<Document> contextDocument();
};

class ScriptRunner {
public:
    static void movePendingAsyncScript(Document& oldDocument, Document& newDocument, ScriptRunner* loader);
    void movePendingAsyncScript(ScriptRunner* newRunner, ScriptRunner* loader);
};