#include <string>
#include <cstdint>

class XmlRpcServerConnection {
public:
    bool readRequest();
private:
    std::string _request;
    int _contentLength;
    enum ConnectionState { WRITE_RESPONSE };
    ConnectionState _connectionState;
    int getfd();
};

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