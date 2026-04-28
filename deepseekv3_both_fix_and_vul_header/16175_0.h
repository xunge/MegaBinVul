#include <string>

class XmlRpcClient {
public:
    bool readResponse();
private:
    std::string _response;
    int _contentLength;
    bool _eof;
    enum { IDLE } _connectionState;
    int getfd();
    void close();
};

class XmlRpcSocket {
public:
    static bool nbRead(int fd, std::string& buff, bool* eof);
    static std::string getErrorMsg();
};

class XmlRpcUtil {
public:
    static void error(const char* format, ...);
    static void log(int level, const char* format, ...);
};