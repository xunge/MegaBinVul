#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <memory>
#include <ctime>
#include <map>
#include <stdexcept>

using std::vector;
using std::string;

struct ComboAddress {
    union {
        struct sockaddr_in sin4;
        struct sockaddr_in6 sin6;
    };
    ComboAddress();
    ComboAddress(const string&);
    string toStringWithPort() const;
};

struct DNSName {
    DNSName();
    DNSName(const string&);
    bool empty() const;
    DNSName operator+(const DNSName&) const;
    bool operator==(const DNSName&) const;
};

struct TSIGTriplet {
    DNSName name;
    DNSName algo;
    string secret;
};

struct TSIGRecordContents {
    DNSName d_algoName;
    time_t d_time;
    uint16_t d_fudge;
    uint16_t d_origID;
    uint16_t d_eRcode;
};

struct Utility {
    struct iovec {
        void* iov_base;
        size_t iov_len;
    };
    static int writev(int fd, const iovec* iov, int count);
};

class DNSPacketWriter {
public:
    DNSPacketWriter(vector<uint8_t>&, const DNSName&, int);
    struct dnsheader* getHeader();
    void addTSIG(TSIGRecordContents*, const DNSName&, const string&, const string&, bool);
};

void addTSIG(DNSPacketWriter&, TSIGRecordContents*, const DNSName&, const string&, const string&, bool);

struct dnsheader {
    uint16_t id;
};

class ResolverException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

template<typename T>
class shared_array {
public:
    explicit shared_array(T*);
    shared_array();
    T& operator[](size_t);
};

class AXFRRetriever {
public:
    AXFRRetriever(const ComboAddress&, const DNSName&, const TSIGTriplet&, const ComboAddress*, size_t);
    AXFRRetriever(const ComboAddress&, const DNSName&, const TSIGTriplet&, const ComboAddress*);
private:
    void connect();
    TSIGTriplet d_tt;
    TSIGRecordContents d_trc;
    int d_sock;
    ComboAddress d_remote;
    shared_array<char> d_buf;
    size_t d_receivedBytes;
    size_t d_maxReceivedBytes;
    size_t d_tsigPos;
    size_t d_nonSignedMessages;
    unsigned int d_soacount;
};

namespace {
    std::map<string, string> arg();
    int makeQuerySocket(const ComboAddress&, bool);
    int waitForData(int, int, int);
    string stringerror();
    int dns_random(int);
    using ::ntohs;
    using ::htons;
}

enum QType { AXFR };