#include <memory>

class ScriptRunner;

template<typename T> class RefPtrWillBeRawPtr {
public:
    RefPtrWillBeRawPtr(T* ptr = nullptr) : m_ptr(ptr) {}
    T* get() const { return m_ptr; }
    operator bool() const { return m_ptr; }
    T* operator->() const { return m_ptr; }
    RefPtrWillBeRawPtr& operator=(T* ptr) { m_ptr = ptr; return *this; }
private:
    T* m_ptr;
};

class Document {
public:
    ScriptRunner* scriptRunner();
    RefPtrWillBeRawPtr<Document> contextDocument();
    bool frame();
};

class HTMLElement {
public:
    virtual void didMoveToNewDocument(Document&);
};

class ScriptRunner {
public:
    static void movePendingAsyncScript(Document&, Document&, void*);
    void movePendingAsyncScript(ScriptRunner*, void*);
};

#define ASSERT(expr) ((void)0)

class HTMLScriptElement : public HTMLElement {
public:
    Document& document();
    void didMoveToNewDocument(Document&) override;
    std::unique_ptr<ScriptRunner> m_loader;
};