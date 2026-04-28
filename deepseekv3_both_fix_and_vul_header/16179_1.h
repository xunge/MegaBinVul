#include <string>
#include <climits>

class XmlRpcServerConnection {
public:
    std::string _response;
    std::string generateHeader(const std::string& body);
    void generateResponse(std::string const& resultXml);
};

class XmlRpcUtil {
public:
    static void error(const char* format, ...);
    static void log(int level, const char* format, ...);
};