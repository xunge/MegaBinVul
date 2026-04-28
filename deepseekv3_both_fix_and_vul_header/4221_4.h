#include <cstring>
#include <string>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define ERROR_MASK 0x10000
#define DNS_QUERY_A 1
#define DNS_QUERY_AAAA 2
#define DNS_QUERY_CNAME 3
#define DNS_QUERY_PTR 4
#define DEBUG 0

struct DNSHeader {
    unsigned char id[2];
};

struct DNSInfo {
    unsigned char* first;
    std::string second;
};

class DNS;

class ServerInstance {
public:
    struct {
        struct {
            int RecvFrom(DNS*, char*, size_t, int, struct sockaddr*, socklen_t*);
        }* SE;
        struct {
            void Log(const char*, int, const char*, ...);
        }* Logs;
    };
};

class DNSRequest {
public:
    std::string orig;
    unsigned long ttl;
    int type;
    DNSInfo ResultIsReady(DNSHeader, int);
};

class DNSResult {
public:
    DNSResult(long, std::string, unsigned long, std::string);
    DNSResult(long, std::string, unsigned long, std::string, int);
};

class DNS {
public:
    static void FillHeader(DNSHeader*, unsigned char*, int);
    DNSResult GetResult();
};

namespace irc {
namespace sockets {
    struct sockaddrs {
        struct sockaddr sa;
        std::string str() const;
        bool operator!=(const sockaddrs&) const;
    };
}
}

extern DNSRequest* requests[];
extern irc::sockets::sockaddrs myserver;
extern ServerInstance* ServerInstance;