#include <sys/un.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <unistd.h>
#include <string.h>
#include <mutex>
#include <string>
#include <errno.h>
#include <iostream>

class SocketEndpoint {
public:
    std::string name() const;
    friend std::ostream& operator<<(std::ostream& os, const SocketEndpoint& ep);
};

class PipeSocketHandler {
public:
    int connect(const SocketEndpoint& endpoint);
    void initSocket(int sockFd);
    void addToActiveSockets(int sockFd);
};

extern std::recursive_mutex globalMutex;

#define FATAL_FAIL(x) if ((x) < 0) { return -1; }
#define VLOG(x) std::cout
#define LOG(x) std::cout
#define GetErrno() errno
#define SetErrno(x) errno = (x)

std::ostream& operator<<(std::ostream& os, const SocketEndpoint& ep) {
    return os << ep.name();
}

using std::string;
using std::lock_guard;