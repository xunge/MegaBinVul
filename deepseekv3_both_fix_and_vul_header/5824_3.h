#include <stdbool.h>
#include <string>

class StyleSheetContents;

class CSSStyleSheetResource {
public:
    std::string sheetText(bool* hasValidMIMEType) const;
    std::string sheetText(bool enforceMIMEType, bool* hasValidMIMEType) const;
};

class SecurityOrigin {
public:
    bool canRequest(void* url) const;
};

class String {
public:
    String(const std::string& str);
};

class CSSParserContext {
public:
    CSSParserContext(void* context, void* counter);
};

class UseCounter {
public:
    static void* getFrom(StyleSheetContents*);
};

class TextPosition {
public:
    static TextPosition minimumPosition();
};

class CSSParser {
public:
    static void parseSheet(CSSParserContext&, StyleSheetContents*, const String&, TextPosition, int, bool);
};

class StyleSheetContents {
public:
    void parseAuthorStyleSheet(const CSSStyleSheetResource*, const SecurityOrigin*);
    void* parserContext() const;
    bool hasSyntacticallyValidCSSHeader() const;
    void clearRules();
    bool isQuirksModeBehavior(int mode);
    void* baseURL();
    
    struct ParserContext {
        int mode() const { return m_mode; }
        int m_mode;
    } m_parserContext;
};

#define TRACE_EVENT0(category, name)
#define TRACE_EVENT1(disabled, name, arg1, arg2)
#define TRACE_DISABLED_BY_DEFAULT(name)

struct InspectorParseAuthorStyleSheetEvent {
    static void* data(const CSSStyleSheetResource*);
};

inline String::String(const std::string& str) {}