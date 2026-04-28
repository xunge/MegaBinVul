#include <string>

class Node {
public:
    // 空定义，仅用于编译
};

class String {
public:
    String() {}
    String(const String&) {}
    // 空定义，仅用于编译
};

class KURL {
public:
    KURL() {}
    KURL(const KURL&) {}
    // 空定义，仅用于编译
};

class XSLStyleSheet {
public:
    XSLStyleSheet(Node* parentNode, const String& originalURL, const KURL& finalURL, bool embedded);

private:
    Node* m_ownerNode;
    String m_originalURL;
    KURL m_finalURL;
    bool m_isDisabled;
    bool m_embedded;
    bool m_processed;
    int m_stylesheetDoc;
    bool m_stylesheetDocTaken;
    bool m_compilationFailed;
    int m_parentStyleSheet;
};