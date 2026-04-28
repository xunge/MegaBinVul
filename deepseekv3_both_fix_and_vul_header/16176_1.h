#include <string>
#include <cstring>
#include <cstdlib>
#include <unistd.h>

class XmlRpcClient {
public:
    bool readHeader();
    int getfd() const;
    bool getKeepOpen() const;
    bool setupConnection();
    void close();
};

class XmlRpcSocket {
public:
    static bool nbRead(int fd, std::string& s, bool* eof);
    static std::string getErrorMsg();
};

class XmlRpcUtil {
public:
    static void log(int level, const char* fmt, ...);
    static void error(const char* fmt, ...);
};

class XmlRpcSource {
public:
    static void close();
};

enum ConnectionState { NO_CONNECTION, READ_RESPONSE };

bool _eof;
std::string _header;
int _contentLength;
std::string _response;
int _sendAttempts;
ConnectionState _connectionState;