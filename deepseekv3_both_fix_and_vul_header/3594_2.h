#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <memory>

#define DCHECK_EQ(a, b) assert((a) == (b))
#define DCHECK_LE(a, b) assert((a) <= (b))

class SocketStream;
class WebSocketJob {
public:
    enum State {
        CONNECTING
    };
    State state_;
    size_t handshake_request_sent_;
    class HandshakeRequest {
    public:
        size_t raw_length() const;
        size_t original_length() const;
    };
    std::unique_ptr<HandshakeRequest> handshake_request_;
    class Delegate {
    public:
        virtual void OnSentData(SocketStream* socket, size_t length) = 0;
    };
    Delegate* delegate_;
    void OnSentHandshakeRequest(SocketStream* socket, int amount_sent);
};