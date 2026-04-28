#include <string>
#include <memory>

class String {
public:
    bool isEmpty() const;
};

class KURL {
public:
    bool isEmpty() const;
};

class ResourceResponse {
public:
    bool wasFetchedViaServiceWorker() const;
    KURL originalURLViaServiceWorker() const;
    String httpHeaderField(const char*) const;
};

class CSSStyleSheetResource {
public:
    enum class MIMETypeCheck { Lax, Strict };
    String sheetText(MIMETypeCheck) const;
    const ResourceResponse& response() const;
};

class SecurityOrigin {
public:
    bool canRequest(const KURL&) const;
};

class CSSParserContext {
public:
    CSSParserContext(const CSSParserContext&, int);
    int mode() const;
};

class UseCounter {
public:
    static int getFrom(const void*);
};

class CSSParser {
public:
    static void parseSheet(const CSSParserContext&, void*, const String&);
};

class StyleSheetContents {
public:
    void parseAuthorStyleSheet(const CSSStyleSheetResource*, const SecurityOrigin*);
    const CSSParserContext& parserContext() const;
    const KURL& baseURL() const;
    bool isQuirksModeBehavior(int) const;
    CSSParserContext m_parserContext;
    String m_sourceMapURL;
};

class InspectorParseAuthorStyleSheetEvent {
public:
    static const char* data(const CSSStyleSheetResource*);
};

class TRACE_EVENT1 {
public:
    TRACE_EVENT1(const char*, const char*, const char*, const char*);
};

namespace HTTPNames {
    extern const char* SourceMap;
    extern const char* X_SourceMap;
}