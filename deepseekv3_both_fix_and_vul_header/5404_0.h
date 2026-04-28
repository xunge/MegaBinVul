#include <string>

class GURL {
public:
    bool SchemeIsHTTPOrHTTPS() const;
    bool SchemeIsSecure() const;
    std::string host() const;
};

namespace net {
    bool IsLocalhost(const std::string& host);
}