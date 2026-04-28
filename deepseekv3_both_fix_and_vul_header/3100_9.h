#include <vector>
#include <memory>

template<typename T> class RefPtr {
public:
    RefPtr(T*);
    T* operator->();
    T* get();
};

template<typename T> class Vector {
public:
    void append(const T&);
    class iterator;
    iterator begin();
    iterator end();
};

class DocumentStyleSheetCollection;
class StyleSheet;
class CSSStyleSheet;
class Node;
class Document;
class ProcessingInstruction;
class Element;
class HTMLLinkElement;
class SVGStyleElement;
class HTMLStyleElement;
class AtomicString;
class Settings;
class SVGNames;

class DocumentOrderedList {
public:
    class iterator {
    public:
        Node* operator*();
        iterator& operator++();
        bool operator!=(const iterator&);
    };
    iterator begin();
    iterator end();
};

class StyleSheetCollection {
public:
    void collectStyleSheets(DocumentStyleSheetCollection*, Vector<RefPtr<StyleSheet>>&, Vector<RefPtr<CSSStyleSheet>>&);
    Document* document();
    DocumentOrderedList m_styleSheetCandidateNodes;
};

class Node {
public:
    enum NodeType {
        PROCESSING_INSTRUCTION_NODE = 1
    };
    NodeType nodeType();
    bool isHTMLElement();
    bool isSVGElement();
    bool hasTagName(int);
};

class Document {
public:
    bool isHTMLDocument();
    bool transformSourceDocument();
    bool parsing();
    void applyXSLTransform(ProcessingInstruction*);
    Settings* settings();
};

class Settings {
public:
    bool authorAndUserStylesEnabled();
};

class Element : public Node {
public:
    AtomicString getAttribute(int);
    bool hasLocalName(int);
};

Element* toElement(Node* n);

class HTMLLinkElement : public Element {
public:
    bool isEnabledViaScript();
    bool isDisabled();
    bool styleSheetIsLoading();
    StyleSheet* sheet();
};

HTMLLinkElement* toHTMLLinkElement(Node* n);

class SVGStyleElement : public Element {
public:
    StyleSheet* sheet();
};

class HTMLStyleElement : public Element {
public:
    StyleSheet* sheet();
};

class ProcessingInstruction : public Node {
public:
    bool isXSL();
    bool isLoading();
    StyleSheet* sheet();
};

class StyleSheet {
public:
    bool disabled();
    bool isCSSStyleSheet();
};

class CSSStyleSheet : public StyleSheet {
};

class DocumentStyleSheetCollection {
public:
    AtomicString preferredStylesheetSetName();
    void setPreferredStylesheetSetName(const AtomicString&);
    void setSelectedStylesheetSetName(const AtomicString&);
};

class AtomicString {
public:
    AtomicString();
    bool isEmpty() const;
    bool contains(const char*) const;
    bool operator!=(const AtomicString&);
};

class SVGNames {
public:
    static const int styleTag;
};

const int linkTag = 0;
const int styleTag = 1;
const int titleAttr = 2;
const int relAttr = 3;
const AtomicString nullAtom;