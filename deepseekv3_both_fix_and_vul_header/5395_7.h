#include <memory>
#include <string>
#include <functional>

namespace net {
struct HttpResponseInfo {};

class URLRequest {
public:
    struct Status {
        bool is_success() const { return true; }
    };
    struct SSLInfo {
        int cert_status;
    };
    class HttpResponseHeaders {
    public:
        bool HasHeaderValue(const std::string&, const std::string&) { return false; }
    };

    Status status() const;
    int GetResponseCode() const;
    const SSLInfo& ssl_info() const;
    const HttpResponseInfo& response_info() const;
    HttpResponseHeaders* response_headers() const;
    void Cancel();
};

bool IsCertStatusError(int cert_status) { return false; }
}  // namespace net

class GURL {
public:
    bool SchemeIsSecure() const { return false; }
    std::string GetOrigin() const { return ""; }
};

class ResponseWriter {
public:
    void WriteInfo(class HttpResponseInfoIOBuffer*, std::function<void(int)>);
};

class HttpResponseInfoIOBuffer {
public:
    explicit HttpResponseInfoIOBuffer(net::HttpResponseInfo* info) {}
};

enum ResultType {
    SERVER_ERROR,
    NETWORK_ERROR,
    SECURITY_ERROR
};

enum FetchType {
    URL_FETCH,
    MASTER_ENTRY_FETCH
};

class AppCacheUpdateJob {
public:
    void MadeProgress() {}
    GURL manifest_url_;
    ResponseWriter* CreateResponseWriter() { return nullptr; }

    class URLFetcher {
    public:
        void OnResponseStarted(net::URLRequest* request);
        void OnResponseCompleted() {}
        void ReadResponseData() {}
        void OnWriteComplete(int result) {}
        
        net::URLRequest* request_;
        AppCacheUpdateJob* job_;
        GURL url_;
        int redirect_response_code_ = -1;
        ResultType result_;
        FetchType fetch_type_;
        std::unique_ptr<ResponseWriter> response_writer_;
    };
};

#define DCHECK(cond) 
#define DCHECK_EQ(a, b) 

template <typename T>
class scoped_refptr {
public:
    explicit scoped_refptr(T* ptr) {}
    T* get() const { return nullptr; }
};

namespace base {
template <typename T>
class Unretained {
public:
    explicit Unretained(T* ptr) : ptr_(ptr) {}
    T* get() const { return ptr_; }
private:
    T* ptr_;
};

template <typename T>
static std::function<void(int)> Bind(void (T::*func)(int), Unretained<T> obj) {
    return [=](int result) { (obj.get()->*func)(result); };
}
}  // namespace base