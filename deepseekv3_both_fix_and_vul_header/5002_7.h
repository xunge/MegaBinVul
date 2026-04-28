#include <memory>
#include <cstdint>
#include <iostream>

#define VLOG(level) std::cout

struct IOBuf {};
class AsyncFizzBase {};

enum class TransportDirection {
    UPSTREAM,
    DOWNSTREAM
};

class SecondAuthManager {
public:
    bool validateAuthenticator(AsyncFizzBase&, TransportDirection, uint16_t, std::unique_ptr<IOBuf>);
};

class Transport {
public:
    template<typename T>
    T* getUnderlyingTransport() { return nullptr; }
};

class HTTPSession;

class DestructorGuard {
public:
    explicit DestructorGuard(HTTPSession* session) {}
};

class HTTPSession {
public:
    void onCertificate(uint16_t certId, std::unique_ptr<IOBuf> authenticator);
    Transport* getTransport() { return nullptr; }
    bool isUpstream() { return false; }
    SecondAuthManager* secondAuthManager_ = nullptr;
    
    friend std::ostream& operator<<(std::ostream& os, const HTTPSession&) {
        return os << "HTTPSession";
    }
};