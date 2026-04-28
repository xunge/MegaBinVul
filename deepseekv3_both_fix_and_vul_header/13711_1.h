#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <sstream>
#include <string>

#define ROS_INVALID_SOCKET (-1)
#define ROS_SOCKETS_ASYNCHRONOUS_CONNECT_RETURN (EINPROGRESS)
#define SYNCHRONOUS (1)

static bool s_use_ipv6_;
static int sock_;
static std::string connected_host_;
static int connected_port_;
static int la_len_;
static int flags_;
static std::string cached_remote_host_;

class TransportTCP {
public:
    bool connect(const std::string& host, int port);
    bool isHostAllowed(const std::string& host);
    void setNonBlocking();
    void close();
    bool initializeSocket();
    int last_socket_error();
    const char* last_socket_error_string();
};

#define ROS_ERROR(...)
#define ROSCPP_LOG_DEBUG(...)
#define ROSCPP_CONN_LOG_DEBUG(...)