#include <memory>

template<typename T> class RefPtrWillBeRawPtr {
    T* m_ptr;
public:
    RefPtrWillBeRawPtr(T* ptr) : m_ptr(ptr) {}
    operator bool() const { return m_ptr; }
    T* get() const { return m_ptr; }
    T* operator->() const { return m_ptr; }
};

class Document {
public:
    class ScriptRunner {
    public:
        void movePendingAsyncScript(ScriptRunner*, void*);
    };
    ScriptRunner* scriptRunner();
    RefPtrWillBeRawPtr<Document> contextDocument();
    bool frame();
};

class HTMLElement {
public:
    void didMoveToNewDocument(Document&);
};

class HTMLScriptElement : public HTMLElement {
    RefPtrWillBeRawPtr<void> m_loader;
public:
    Document& document();
    void didMoveToNewDocument(Document&);
};

#define ASSERT(expr) ((void)0)