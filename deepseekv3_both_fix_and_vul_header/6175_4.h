#include <string>
#include <sstream>
#include <map>
#include <cstddef>

namespace Exiv2 {
    typedef std::map<std::string, std::string> Dictionary;
    
    struct Uri {
        std::string Host;
        std::string Port;
        std::string Path;
        static Uri Parse(const std::string&);
    };
    
    namespace Internal {
        std::string stringFormat(const char*, ...);
    }
}

typedef unsigned char byte;

class HttpIo {
public:
    class HttpImpl {
    public:
        void writeRemote(const byte* data, size_t size, long from, long to);
    };
};

struct HostInfo {
    std::string Host;
    std::string Path;
};

struct Error {
    Error(int, const char*);
    Error(int, const char*, const std::string&, const std::string&);
};

std::string getEnv(const char*);
void base64encode(const byte*, size_t, char*, size_t);
std::string urlencode(const char*);
int http(const Exiv2::Dictionary&, Exiv2::Dictionary&, std::string&);

extern const char* envHTTPPOST;
extern HostInfo hostInfo_;
extern int kerErrorMessage;
extern int kerFileOpenFailed;

using Exiv2::Uri;