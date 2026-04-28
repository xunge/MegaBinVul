#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef int NPT_Result;
#define NPT_SUCCESS 0
#define NPT_FAILED(x) (x != NPT_SUCCESS)
#define NPT_SUCCEEDED(x) (x == NPT_SUCCESS)
#define NPT_ERROR_NO_SUCH_ITEM -1

typedef unsigned int NPT_UInt32;

class NPT_String {
public:
    NPT_String() {}
    NPT_String(const char* str) {}
    int Find(const char* str) const { return 0; }
    const char* GetChars() const { return ""; }
    const char* ToString() const { return ""; }
};

class NPT_HttpHeaders {
public:
    const NPT_String* GetHeaderValue(const char* name) const { return nullptr; }
    void SetHeader(const char* name, const NPT_String& value, bool replace) {}
};

class NPT_HttpMessage {
public:
    virtual const NPT_HttpHeaders& GetHeaders() const = 0;
};

class NPT_HttpRequest : public NPT_HttpMessage {
public:
    const NPT_String& GetUrl() const { static NPT_String s; return s; }
    const NPT_HttpHeaders& GetHeaders() const override { static NPT_HttpHeaders h; return h; }
};

class NPT_HttpResponse {
public:
    void SetStatus(int code, const char* text, const char* protocol) {}
    NPT_HttpHeaders& GetHeaders() { static NPT_HttpHeaders h; return h; }
};

class NPT_InputStreamReference {
public:
    bool IsNull() const { return false; }
};

enum NPT_FileOpenMode {
    NPT_FILE_OPEN_MODE_READ
};

class NPT_File {
public:
    NPT_File(const NPT_String& path) {}
    NPT_Result Open(NPT_FileOpenMode mode) { return NPT_SUCCESS; }
    NPT_Result GetInputStream(NPT_InputStreamReference& stream) { return NPT_SUCCESS; }
    static NPT_Result GetInfo(const NPT_String& path, void* info) { return NPT_SUCCESS; }
};

struct NPT_FileInfo {
    time_t m_ModificationTime;
};

class NPT_TimeStamp {
public:
    NPT_TimeStamp() {}
    NPT_UInt32 ToSeconds() const { return 0; }
    bool operator>=(const time_t& other) const { return false; }
};

class NPT_DateTime {
public:
    enum {
        FORMAT_RFC_1123
    };
    NPT_DateTime() {}
    NPT_DateTime(time_t timestamp) {}
    NPT_String ToString() const { return NPT_String(); }
    NPT_String ToString(int format) const { return NPT_String(); }
    NPT_Result ToTimeStamp(NPT_TimeStamp& timestamp) { return NPT_SUCCESS; }
};

class NPT_HttpRequestContext {
public:
    NPT_HttpRequestContext(const NPT_HttpRequest& request, const NPT_HttpRequestContext& context) {}
};

class PLT_HttpRequestContext : public NPT_HttpRequestContext {
public:
    PLT_HttpRequestContext(const NPT_HttpRequest& request, const NPT_HttpRequestContext& context) 
        : NPT_HttpRequestContext(request, context) {}
};

class PLT_UPnPMessageHelper {
public:
    static NPT_Result GetIfModifiedSince(NPT_HttpMessage& request, NPT_DateTime& date) { return NPT_SUCCESS; }
};

class PLT_MimeType {
public:
    static NPT_String GetMimeType(const NPT_String& filename, NPT_HttpRequestContext* context) { return NPT_String(); }
};

class PLT_HttpServer {
public:
    NPT_Result ServeFile(const NPT_HttpRequest& request, 
                        const NPT_HttpRequestContext& context,
                        NPT_HttpResponse& response,
                        NPT_String file_path);
    NPT_Result ServeStream(const NPT_HttpRequest& request,
                          const NPT_HttpRequestContext& context,
                          NPT_HttpResponse& response,
                          NPT_InputStreamReference& stream,
                          const NPT_String& mime_type);
};

#define NPT_HTTP_HEADER_RANGE "Range"
#define NPT_HTTP_PROTOCOL_1_1 "HTTP/1.1"

#define NPT_LOG_INFO_5(fmt, a1, a2, a3, a4, a5)
#define NPT_LOG_FINE_1(fmt, a1)