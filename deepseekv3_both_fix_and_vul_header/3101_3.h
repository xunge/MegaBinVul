#include <string>
#include <memory>

class Frame;
class XSLStyleSheet;

class Document {
public:
    Frame* frame();
    void applyXSLTransform(class ProcessingInstruction* pi);
};

class ProcessingInstruction {
public:
    bool isLoading();
    void* sheet();
};

class XSLTProcessor {
public:
    static XSLTProcessor* create();
    void setXSLStyleSheet(XSLStyleSheet*);
    bool transformToString(Document*, std::string&, std::string&, std::string&);
    void createDocumentFromSource(const std::string&, const std::string&, const std::string&, Document*, Frame*);
};

class UseCounter {
public:
    enum CounterType { XSLProcessingInstruction };
    static void count(Document*, CounterType);
};

class InspectorInstrumentation {
public:
    static void frameDocumentUpdated(Frame*);
};

template<typename T> class RefPtr {
public:
    RefPtr(T* ptr) : m_ptr(ptr) {}
    T* operator->() { return m_ptr; }
    T* get() { return m_ptr; }
private:
    T* m_ptr;
};

#define ASSERT(expr) ((void)0)

using String = std::string;