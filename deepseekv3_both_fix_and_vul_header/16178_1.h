#include <string>
#include <climits>
#include <unistd.h>
#include <sys/socket.h>

class XmlRpcUtil {
public:
    static void error(const char* format, ...);
    static void log(int level, const char* format, ...);
};

class XmlRpcSocket {
public:
    static bool nonFatalError();
    static bool nbWrite(int fd, const std::string& s, int* bytesSoFar);
};