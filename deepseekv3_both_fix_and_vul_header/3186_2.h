#include <string>
#include <iostream>

class HttpResponseHeaders;
class HttpRequestInfo;
class HttpStreamParser;

#define DCHECK_EQ(a, b)
#define DVLOG(a) if (false) std::cout
#define OK 0
#define ERR_RESPONSE_HEADERS_MULTIPLE_CONTENT_LENGTH -1
#define ERR_RESPONSE_HEADERS_MULTIPLE_CONTENT_DISPOSITION -2
#define ERR_RESPONSE_HEADERS_MULTIPLE_LOCATION -3

template <typename T>
class scoped_refptr {
public:
    scoped_refptr() : ptr_(nullptr) {}
    scoped_refptr(T* ptr) : ptr_(ptr) {}
    T* get() { return ptr_; }
    T* operator->() { return ptr_; }
    operator T*() { return ptr_; }
private:
    T* ptr_;
};

class HttpResponseHeaders {
public:
    HttpResponseHeaders(const std::string& raw_headers);
    bool HasHeader(const std::string& name);
    int GetContentLength();
};

class HttpUtil {
public:
    static std::string AssembleRawHeaders(const char* data, int length);
};

class HttpResponseInfo {
public:
    enum ConnectionInfo {
        CONNECTION_INFO_HTTP1
    };
    scoped_refptr<HttpResponseHeaders> headers;
    ConnectionInfo connection_info;
    struct {
        void Init(const HttpRequestInfo& request, const HttpResponseHeaders& headers);
    } vary_data;
};

class HttpRequestInfo {};

class IOBuffer {
public:
    char* StartOfBuffer();
};

class HttpStreamParser {
public:
    int DoParseResponseHeaders(int end_offset);
    int response_header_start_offset_;
    int read_buf_unused_offset_;
    IOBuffer* read_buf_;
    HttpResponseInfo* response_;
    HttpRequestInfo* request_;
};

bool HeadersContainMultipleCopiesOfField(const HttpResponseHeaders& headers, const std::string& field);
std::string GetResponseHeaderLines(const HttpResponseHeaders& headers);