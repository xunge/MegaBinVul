#include <string>

struct AuthChallengeInfo {
    bool is_proxy;
    std::string challenger;
    std::string scheme;
    std::string realm;
};

namespace url {
class Origin {
public:
    Origin(const std::string& origin);
    operator std::string() const;
};
}  // namespace url

class HostPortPair {
public:
    static HostPortPair FromURL(const std::string& url);
    operator std::string() const;
};

namespace HttpAuth {
    enum AuthTarget { AUTH_PROXY };
    std::string SchemeToString(int scheme);
}  // namespace HttpAuth

class AuthHandler {
public:
    int auth_scheme();
    std::string realm();
};

class HttpAuthController {
public:
    void PopulateAuthChallenge();
    bool CalledOnValidThread();
    AuthChallengeInfo* auth_info_;
    HttpAuth::AuthTarget target_;
    std::string auth_origin_;
    AuthHandler* handler_;
};

#define DCHECK(condition) (void)(condition)