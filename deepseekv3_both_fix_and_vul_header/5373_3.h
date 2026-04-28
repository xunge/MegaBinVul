#include <memory>
#include <cassert>

class ProcessingInstruction;

class ContainerNode {
public:
    bool inDocument();
};

class CharacterData {
public:
    static void removedFrom(ContainerNode* insertionPoint);
};

class StyleEngine {
public:
    void removeStyleSheetCandidateNode(ProcessingInstruction*);
    void removeXSLStyleSheet(ProcessingInstruction*);
    void removePendingSheet(ProcessingInstruction*);
};

class StyleSheet {
public:
    ProcessingInstruction* ownerNode();
};

class Resource {
public:
    bool m_loading;
};

class Document {
public:
    StyleEngine* styleEngine();
    bool isActive();
    void removedStyleSheet(StyleSheet*);
};

template<typename T>
class RefPtrWillBeRawPtr {
public:
    T* get();
    RefPtrWillBeRawPtr(T*);
    T* operator->();
};

class ProcessingInstruction : public CharacterData {
public:
    void removedFrom(ContainerNode* insertionPoint);
    Document& document();
    void clearSheet();
    void clearResource();
    bool m_isCSS;
    bool m_isXSL;
    bool m_loading;
    StyleSheet* m_sheet;
    Resource* resource();
};

#define ASSERT(expr) assert(expr)