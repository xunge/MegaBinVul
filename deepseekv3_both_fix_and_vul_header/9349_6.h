#include <string>
#include <map>
#include <memory>

namespace url {
const char kHttpScheme[] = "http";
const char kHttpsScheme[] = "https";
const char kDataScheme[] = "data";
const char kFtpScheme[] = "ftp";
}

class GURL {
public:
    explicit GURL(const std::string& url);
    bool is_valid() const;
    bool SchemeIs(const char* scheme) const;
};

namespace net {
class URLFetcher;
class URLFetcherResponseWriter {
public:
    virtual ~URLFetcherResponseWriter() {}
};

class URLFetcher {
public:
    enum RequestType { GET };
    static std::unique_ptr<URLFetcher> Create(const GURL& url, RequestType type, void* delegate);
    void SetRequestContext(void* context);
    void SetExtraRequestHeaders(const std::string& headers);
    void SaveResponseWithWriter(std::unique_ptr<URLFetcherResponseWriter> writer);
    void Start();
};
}

namespace base {
class DictionaryValue {
public:
    void SetInteger(const std::string& key, int value);
};
}

class DispatchCallback {
public:
    void Run(base::DictionaryValue* response) const;
};

class DevToolsUIBindings {
public:
    void LoadNetworkResource(const DispatchCallback& callback,
                           const std::string& url,
                           const std::string& headers,
                           int stream_id);
private:
    std::map<net::URLFetcher*, DispatchCallback> pending_requests_;
    struct Profile {
        void* GetRequestContext();
    }* profile_;
    struct WeakPtr {
        void* get() const;
    };
    struct WeakPtrFactory {
        WeakPtr GetWeakPtr();
    } weak_factory_;
    class ResponseWriter : public net::URLFetcherResponseWriter {
    public:
        ResponseWriter(WeakPtr weak_ptr, int stream_id);
    };
};

template<typename T>
using scoped_ptr = std::unique_ptr<T>;