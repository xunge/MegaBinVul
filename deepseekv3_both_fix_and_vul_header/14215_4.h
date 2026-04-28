#include <string>
#include <memory>
#include <functional>

namespace rest {
    enum class RequestType {
        POST
    };
    enum class ResponseCode {
        METHOD_NOT_ALLOWED,
        UNAUTHORIZED
    };
}

const int TRI_ERROR_HTTP_METHOD_NOT_ALLOWED = 405;
const int TRI_ERROR_HTTP_UNAUTHORIZED = 401;

namespace events {
    template<typename T>
    void LoggedIn(T&&, const std::string&);
    template<typename T>
    void CredentialsBad(T&&, const std::string&);
}

namespace auth {
    class UserManager {
    public:
        bool checkPassword(const std::string&, const std::string&);
    };
}

class AuthenticationFeature {
public:
    static AuthenticationFeature* instance();
    auth::UserManager* userManager();
};

class VPackSlice {
public:
    bool isObject() const;
    bool isString() const;
    std::string copyString() const;
    VPackSlice get(const std::string&) const;
};

class VPackValue {
public:
    VPackValue(const std::string&);
};

class VPackBuilder {
public:
    void add(const std::string&, const VPackValue&);
    VPackSlice slice() const;
};

class VPackObjectBuilder {
public:
    VPackObjectBuilder(VPackBuilder*);
};

class VPackOptions {
public:
    static VPackOptions Defaults;
};

class Logger {
public:
    static const char* AUTHENTICATION;
};

enum LogLevel { ERR };

class LOG_TOPIC {
public:
    LOG_TOPIC(const char*, LogLevel, const char*);
    LOG_TOPIC& operator<<(const std::string&);
};

class RestStatus {
public:
    static RestStatus DONE;
};

class Request {
public:
    rest::RequestType requestType() const;
};

class RestAuthHandler {
protected:
    std::string _username;
    bool _isValid;
    std::shared_ptr<Request> _request;

    RestStatus execute();
    RestStatus badRequest();
    void generateError(rest::ResponseCode, int, const std::string& = "");
    void generateDocument(VPackSlice, bool, const VPackOptions*);
    VPackSlice parseVPackBody(bool&);
    std::string generateJwt(const std::string&, const std::string& = "");
    template<typename F>
    auto scopeGuard(F&& f) { return std::unique_ptr<std::decay_t<F>>(new std::decay_t<F>(std::forward<F>(f))); }
};