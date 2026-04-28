#include <stddef.h>

#define TRACE_EVENT0(category, name)
#define ASSERT(condition)

class Document;
class Element;

class StyleEngine {
public:
    void addStyleSheetCandidateNode(Element*, bool);
};

class Document {
public:
    StyleEngine* styleEngine();
};

class StyleElement {
public:
    void processStyleSheet(Document&, Element*);
private:
    bool m_registeredAsCandidate;
    bool m_createdByParser;
    void process(Element*);
};