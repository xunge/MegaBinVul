#include <string>
#include <exception>
#include <cassert>

#define ASSERT assert

enum DOMExceptionType {
    SyntaxError,
    InvalidAccessError
};

using String = std::string;

class KURL {
public:
    String elidedString() const;
    bool protocolIsInHTTPFamily() const;
};

class ExceptionState {
public:
    void throwDOMException(DOMExceptionType code, const String& message);
    void throwSecurityError(const String& message);
};

class ContentSecurityPolicy {
public:
    bool allowConnectToSource(const KURL& url);
    static bool shouldBypassMainWorld(void* context);
};

class ScriptExecutionContext {
public:
    ContentSecurityPolicy* contentSecurityPolicy();
    bool isDocument();
};

class Document : public ScriptExecutionContext {
public:
    class Settings {
    public:
        bool syncXHRInDocumentsEnabled();
    };
    Settings* settings();
};

class ExceptionMessages {
public:
    static String failedToExecute(const char* func, const char* interface, const String& detail);
};

enum State {
    UNSENT,
    OPENED
};

enum ResponseTypeCode {
    ResponseTypeDefault
};

class XMLHttpRequest {
public:
    void open(const String& method, const KURL& url, bool async, ExceptionState& es);
    bool internalAbort();
    void clearResponse();
    void clearRequest();
    bool isValidHTTPToken(const String& method);
    bool isAllowedHTTPMethod(const String& method);
    ScriptExecutionContext* scriptExecutionContext();
    Document* document();
    String uppercaseKnownHTTPMethod(const String& method);
    void changeState(State state);

    State m_state;
    bool m_error;
    bool m_uploadComplete;
    ResponseTypeCode m_responseTypeCode;
    unsigned long m_timeoutMilliseconds;
    String m_method;
    KURL m_url;
    bool m_async;
    void* m_loader;
};