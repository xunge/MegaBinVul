#include <cstring>
#include <memory>

namespace auth {
    char* WriteUserInfoToJson(void* user_info);
    char* esp_base64_encode(const char* input, size_t length, bool pad, bool url_safe, bool null_terminate);
    void esp_grpc_free(void* ptr);
    extern const char* kEndpointApiUserInfo;
}

class Status {
public:
    static Status OK;
};

class Request {
public:
    void AddHeaderToBackend(const char* header, const char* value, bool flag = false);
};

class Context {
public:
    Request* request() { return &request_; }
private:
    Request request_;
};

class TRACE {
public:
    TRACE(std::shared_ptr<void> trace_span) {}
    template<typename T>
    TRACE& operator<<(const T&) { return *this; }
};

class AuthChecker {
public:
    void PassUserInfoOnSuccess();
protected:
    void* user_info_;
    std::shared_ptr<void> trace_span_;
    Context* context_;
    void (*on_done_)(Status);
};