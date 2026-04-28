#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <climits>

class XmlRpcSocket {
public:
    static bool nbRead(int fd, std::string& s, bool* eof);
};

class XmlRpcUtil {
public:
    static void log(int level, const char* format, ...);
    static void error(const char* format, ...);
};

bool nonFatalError();