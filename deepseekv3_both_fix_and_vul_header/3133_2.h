#include <string>

class XSLStyleSheet;

class String {
public:
    String(const String&);
    ~String();
};

class KURL {
public:
    KURL(const KURL&);
    ~KURL();
};

class XSLImportRule {
public:
    XSLStyleSheet* parentStyleSheet() const;
};

class XSLStyleSheet {
public:
    XSLStyleSheet(XSLImportRule* parentRule, const String& originalURL, const KURL& finalURL);
    
    void* m_ownerNode;
    String m_originalURL;
    KURL m_finalURL;
    bool m_isDisabled;
    bool m_embedded;
    bool m_processed;
    void* m_stylesheetDoc;
    bool m_stylesheetDocTaken;
    bool m_compilationFailed;
    XSLStyleSheet* m_parentStyleSheet;
};