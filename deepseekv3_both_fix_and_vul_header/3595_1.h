#include <memory>

class WebSocketJob {
public:
    enum State {
        INITIALIZED,
        CONNECTING
    };

    void OnSentSpdyHeaders();

private:
    State state_;
    class Delegate* delegate_;
    std::unique_ptr<class Socket> socket_;
    std::unique_ptr<class HandshakeRequest> handshake_request_;
};

class Delegate {
public:
    void OnSentData(class Socket* socket, size_t length);
};

class Socket {
public:
    Socket* get();
};

class HandshakeRequest {
public:
    size_t original_length();
};

#define DCHECK_NE(a, b)