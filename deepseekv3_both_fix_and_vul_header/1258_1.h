#include <vector>
#include <iostream>

#define CROW_LOG_INFO std::cout

namespace crow {
    namespace websocket {
        struct connection {
            void close(const char*);
        };
    }
}

struct Server {
    void stop();
};

struct SSLServer {
    void stop();
};

extern bool ssl_used_;
extern bool CROW_ENABLE_SSL;
extern std::vector<crow::websocket::connection*> websockets_;
extern SSLServer* ssl_server_;
extern Server* server_;