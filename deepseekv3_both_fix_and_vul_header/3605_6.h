#include <memory>
#include <cassert>

#define ASSERT(expr) assert(expr)

class Element;
class ContainerNode;
class TreeScope;
class StyleSheet;

class StyleEngine {
public:
    void removeStyleSheetCandidateNode(Element*, ContainerNode*, TreeScope&);
};

class Document {
public:
    StyleEngine* styleEngine();
    void removedStyleSheet(StyleSheet*, int, int);
};

const int RecalcStyleDeferred = 0;
const int AnalyzedStyleUpdate = 1;

template<typename T> class RefPtrWillBeRawPtr {
public:
    RefPtrWillBeRawPtr(T* p = nullptr) : ptr(p) {}
    T* get() const { return ptr; }
    operator bool() const { return ptr != nullptr; }
    bool operator!() const { return ptr == nullptr; }
private:
    T* ptr;
};

class StyleElement {
protected:
    bool m_registeredAsCandidate;
    RefPtrWillBeRawPtr<StyleSheet> m_sheet;

    void clearSheet(Element* element) {}
public:
    void removedFromDocument(Document&, Element*, ContainerNode*, TreeScope&);
};