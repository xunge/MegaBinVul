#include <memory>
#include <utility>
#include <cstdint>
#include <iostream>
#include <string>

#define VLOG(level) if (level <= 4) std::cout

namespace folly {
class IOBuf {
public:
    ~IOBuf();
};
}

class AsyncFizzBase {
public:
    template<typename T>
    T* getUnderlyingTransport();
};

class HTTPSession;

class DestructorGuard {
public:
    explicit DestructorGuard(HTTPSession* session);
};

enum class TransportDirection {
    UPSTREAM,
    DOWNSTREAM
};

class SecondAuthManager {
public:
    std::pair<uint16_t, std::unique_ptr<folly::IOBuf>> 
    getAuthenticator(AsyncFizzBase& base, TransportDirection direction,
                    uint16_t requestId, std::unique_ptr<folly::IOBuf> authRequest);
};

class HTTPCodec {
public:
    int generateCertificate(std::unique_ptr<folly::IOBuf>& writeBuf,
                           uint16_t id, 
                           std::unique_ptr<folly::IOBuf> authenticator);
};

class HTTPSession {
public:
    void onCertificateRequest(uint16_t requestId, std::unique_ptr<folly::IOBuf> authRequest);
    AsyncFizzBase* getTransport();
    bool isUpstream();
    void scheduleWrite();
    std::string toString() const;
    
    std::unique_ptr<folly::IOBuf> writeBuf_;
    SecondAuthManager* secondAuthManager_;
    HTTPCodec* codec_;
};

using IOBuf = folly::IOBuf;

inline std::ostream& operator<<(std::ostream& os, const HTTPSession& session) {
    return os << session.toString();
}