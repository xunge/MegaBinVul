#include <string>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <cassert>

#define ROS_ASSERT(x) assert(x)

class TransportUDP {
public:
    std::string getClientURI();
    bool is_server_;
    int sock_;
};