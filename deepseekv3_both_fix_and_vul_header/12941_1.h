#include <memory>
#include <utility>

struct StreamResetReason {};

class ActiveRequest {
public:
    class ResponseEncoder {
    public:
        void runResetCallbacks(StreamResetReason reason);
    } response_encoder_;
};

class Dispatcher {
public:
    void deferredDelete(std::unique_ptr<ActiveRequest> request);
};

class Connection {
public:
    Dispatcher& dispatcher();
};

class ServerConnectionImpl {
private:
    std::unique_ptr<ActiveRequest> active_request_;
    Connection connection_;
public:
    void onResetStream(StreamResetReason reason);
};