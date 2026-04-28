#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef int NPT_Result;
#define NPT_SUCCESS 0
#define NPT_FAILED(x) ((x) != NPT_SUCCESS)
#define NPT_ERROR_NO_SUCH_ITEM -1
#define NPT_SUCCEEDED(x) ((x) == NPT_SUCCESS)

typedef uint32_t NPT_UInt32;

#define NPT_HTTP_HEADER_RANGE "Range"
#define NPT_HTTP_PROTOCOL_1_1 "HTTP/1.1"
#define NPT_FILE_OPEN_MODE_READ "r"

class NPT_String {
public:
    NPT_String();
    NPT_String(const char* str);
    int Find(const char* str) const;
    const char* GetChars() const;
    const char* ToString() const;
    operator const char*() const;
};

class NPT_HttpHeaders {
public:
    const NPT_String* GetHeaderValue(const char* name) const;
    void SetHeader(const char* name, const NPT_String& value, bool replace);
};

class NPT_HttpUrl {
public:
    NPT_String GetPath() const;
};

class NPT_HttpMessage {
public:
    const NPT_HttpHeaders& GetHeaders() const;
    NPT_HttpHeaders& GetHeaders();
};

class NPT_HttpRequest : public NPT_HttpMessage {
public:
    NPT_HttpUrl GetUrl() const;
};

class NPT_HttpResponse {
public:
    void SetStatus(int code, const char* text, const char* protocol);
    NPT_HttpHeaders& GetHeaders();
};

class NPT_InputStreamReference {
public:
    bool IsNull() const;
};

class NPT_File {
public:
    NPT_File(const NPT_String& path);
    NPT_Result Open(const char* mode);
    NPT_Result GetInputStream(NPT_InputStreamReference& stream);
    static NPT_Result GetInfo(const NPT_String& path, void* info);
};

struct NPT_FileInfo {
    time_t m_ModificationTime;
};

class NPT_TimeStamp {
public:
    NPT_TimeStamp();
    time_t ToSeconds() const;
    bool operator>=(time_t other) const;
};

class NPT_DateTime {
public:
    NPT_DateTime();
    NPT_DateTime(time_t timestamp);
    enum Format {
        FORMAT_RFC_1123
    };
    NPT_String ToString(Format format = FORMAT_RFC_1123) const;
    NPT_Result ToTimeStamp(NPT_TimeStamp& timestamp) const;
};

class NPT_HttpRequestContext {
public:
    NPT_HttpRequestContext(const NPT_HttpRequest& request, const NPT_HttpRequestContext& context);
};

class PLT_HttpRequestContext : public NPT_HttpRequestContext {
public:
    PLT_HttpRequestContext(const NPT_HttpRequest& request, const NPT_HttpRequestContext& context);
};

class PLT_UPnPMessageHelper {
public:
    static NPT_Result GetIfModifiedSince(NPT_HttpMessage& message, NPT_DateTime& date);
};

class PLT_MimeType {
public:
    static NPT_String GetMimeType(const NPT_String& filename, NPT_HttpRequestContext* context);
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

#define NPT_LOG_INFO_5(fmt, a, b, c, d, e) printf(fmt, a, b, c, d, e)
#define NPT_LOG_FINE_1(fmt, a) printf(fmt, a)