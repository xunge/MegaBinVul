#include <string>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <cassert>

class TransportTCP {
public:
    std::string getClientURI();
    bool is_server_;
    int sock_;
};

#define ROS_ASSERT(x) assert(x)