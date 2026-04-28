#include <cassert>
#include <string>
#include <memory>

class String;
class KURL;
class Document;
class ProcessingInstruction;

class XSLStyleSheet {
public:
    static XSLStyleSheet* create(ProcessingInstruction*, const String&, const KURL&);
};

class ProcessingInstruction {
public:
    bool inDocument() const;
    Document& document();
    void parseStyleSheet(const String& sheet);
    void setXSLStyleSheet(const String& href, const KURL& baseURL, const String& sheet);

    bool m_isXSL;
    XSLStyleSheet* m_sheet;
};

template<typename T> class RefPtrWillBeRawPtr {
public:
    RefPtrWillBeRawPtr(T* ptr);
};

#define ASSERT assert