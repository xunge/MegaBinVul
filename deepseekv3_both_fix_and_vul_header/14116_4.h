#include <string>

class Method {
public:
    const std::string& backend_jwt_audience() const;
};

class ServiceContext {
public:
    class GlobalContext {
    public:
        class InstanceIdentityToken {
        public:
            const std::string& GetAuthToken() const;
        };
        InstanceIdentityToken* GetInstanceIdentityToken(const std::string& audience);
    };
    GlobalContext* global_context();
    class Env {
    public:
        void LogError(const std::string& message);
    };
    Env* env();
};

class Status {
public:
    bool ok() const;
};

class Request {
public:
    bool FindHeader(const std::string& name, std::string* value);
    Status AddHeaderToBackend(const std::string& name, const std::string& value, bool overwrite);
    Status AddHeaderToBackend(const std::string& name, const std::string& value);
};

class RequestContext {
public:
    void AddInstanceIdentityToken();
    Method* method();
    ServiceContext* service_context();
    Request* request();
};

constexpr char kAuthorizationHeader[] = "Authorization";
constexpr char kXForwardedAuthorizationHeader[] = "X-Forwarded-Authorization";
constexpr char kBearerPrefix[] = "Bearer ";