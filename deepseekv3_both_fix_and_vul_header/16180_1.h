#include <string>
#include <cstring>
#include <cstdlib>

class XmlRpcSocket {
public:
    static bool nbRead(int fd, std::string& s, bool* eof);
    static std::string getErrorMsg();
};

class XmlRpcUtil {
public:
    static void error(const char* format, ...);
    static void log(int level, const char* format, ...);
};

class XmlRpcServerConnection {
public:
    bool readHeader();
    int getfd();
    std::string _header;
    std::string _request;
    int _contentLength;
    bool _keepAlive;
    enum ConnectionState { READ_HEADER, READ_REQUEST } _connectionState;
};