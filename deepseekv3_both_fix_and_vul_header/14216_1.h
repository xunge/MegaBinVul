#include <string>
#include <chrono>

class AuthenticationFeature {
public:
    static AuthenticationFeature* instance();
    class TokenCache {
    public:
        std::string jwtSecret() const;
    };
    TokenCache& tokenCache();
    int sessionTimeout() const;
};

namespace fuerte {
namespace jwt {
    std::string generateUserToken(std::string const& secret, std::string const& username, std::chrono::seconds duration);
    std::string generateUserToken(std::string const& secret, std::string const& username, int validFor);
}
}

#define TRI_ASSERT(expr) ((void)0)

class RestAuthHandler {
public:
    std::string generateJwt(std::string const& username) const;
    std::string generateJwt(std::string const& username, std::string const& password);
protected:
    int _validFor;
};