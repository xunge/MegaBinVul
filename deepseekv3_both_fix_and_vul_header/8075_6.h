#include <memory>
#include <string>
#include <utility>

#define DCHECK(expr) ((void)0)

namespace url {
class Origin {
public:
    Origin(const std::string&);
    Origin(const Origin&) = default;
    Origin& operator=(const Origin&) = default;
};
}  // namespace url

class HostPortPair {
public:
    HostPortPair() = default;
    HostPortPair(const HostPortPair&) = default;
    static HostPortPair FromURL(const std::string&);
    HostPortPair& operator=(const HostPortPair&) = default;
};

struct AuthChallengeInfo {
    bool is_proxy = false;
    std::string scheme;
    std::string realm;
    union Challenger {
        url::Origin origin;
        HostPortPair host_port;
        
        Challenger() : origin("") {}
        ~Challenger() { origin.~Origin(); }
        
        Challenger& operator=(const url::Origin& o) {
            origin = o;
            return *this;
        }
        Challenger& operator=(const HostPortPair& h) {
            host_port = h;
            return *this;
        }
    } challenger;

    AuthChallengeInfo() = default;
};

template<typename T>
class scoped_refptr {
public:
    scoped_refptr(T* ptr) : ptr_(ptr) {}
    void swap(scoped_refptr<T>& other) { std::swap(ptr_, other.ptr_); }
    T* operator->() { return ptr_; }
    T* get() { return ptr_; }
private:
    T* ptr_;
};

class URLRequest {
public:
    std::string url();
};

class HttpResponseInfo {
public:
    scoped_refptr<AuthChallengeInfo> auth_challenge;
};

class URLRequestFtpJob {
public:
    bool NeedsAuth();
    HttpResponseInfo* http_response_info_;
    URLRequest* request_;
    void GetAuthChallengeInfo(scoped_refptr<AuthChallengeInfo>* result);
};