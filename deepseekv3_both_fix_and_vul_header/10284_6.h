#include <utility>
#include <cstring>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>

#define DNS_QUERY_NONE 0
#define DNS_QUERY_CNAME 5
#define DNS_QUERY_PTR 12
#define DNS_QUERY_A 1
#define DNS_QUERY_AAAA 28
#define FLAGS_MASK_QR 0x80
#define FLAGS_MASK_OPCODE 0x78
#define FLAGS_MASK_RCODE 0x0F
#define DN_COMP_BITMASK 0xC000
#define DEBUG 0

typedef std::pair<unsigned char*, std::string> DNSInfo;

struct DNSHeader {
    unsigned short id;
    unsigned char flags1;
    unsigned char flags2;
    unsigned short qdcount;
    unsigned short ancount;
    unsigned short nscount;
    unsigned short arcount;
    unsigned char payload[];
};

struct ResourceRecord {
    unsigned short type;
    unsigned short rr_class;
    unsigned int ttl;
    unsigned short rdlength;
};

class Logger {
public:
    void Log(const char*, int, const char*, ...);
};

class Server {
public:
    Logger* Logs;
};

class DNSRequest {
public:
    unsigned char res[1024];
    unsigned short type;
    unsigned short rr_class;
    unsigned int ttl;
    static Server* ServerInstance;
    DNSInfo ResultIsReady(DNSHeader &header, unsigned length);
};

namespace DNS {
    void FillResourceRecord(ResourceRecord* rr, unsigned char* payload);
}

std::string ConvToStr(unsigned int value);