#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <vector>
#include <memory>
#include <ctime>
#include <string>
#include <stdexcept>
#include <map>
#include <cstdint>

using namespace std;

struct ComboAddress {
    union {
        struct sockaddr_in sin4;
        struct sockaddr_in6 sin6;
    };
    ComboAddress() = default;
    ComboAddress(const string& addr);
    string toStringWithPort() const;
};

struct TSIGRecord {
    string d_algoName;
    time_t d_time;
    unsigned int d_fudge;
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

class ResolverException : public runtime_error {
public:
    ResolverException(const string& msg) : runtime_error(msg) {}
};

struct dnsheader {
    uint16_t id;
};

namespace QType {
    const uint16_t AXFR = 252;
};

class DNSPacketWriter {
public:
    DNSPacketWriter(vector<uint8_t>& packet, const string& domain, uint16_t type);
    dnsheader* getHeader();
    void addTSIG(TSIGRecord* trc, const string& keyname, const string& secret, const string& prev, bool timersonly);
};

template<typename T>
class shared_array {
public:
    shared_array() : ptr_(nullptr) {}
    explicit shared_array(T* ptr) : ptr_(ptr) {}
    ~shared_array() { delete[] ptr_; }
    T* get() const { return ptr_; }
private:
    T* ptr_;
};

class AXFRRetriever {
public:
    AXFRRetriever(const ComboAddress& remote,
                 const string& domain,
                 const string& tsigkeyname,
                 const string& tsigalgorithm,
                 const string& tsigsecret,
                 const ComboAddress* laddr,
                 size_t maxReceivedBytes);
    AXFRRetriever(const ComboAddress& remote,
                 const string& domain,
                 const string& tsigkeyname,
                 const string& tsigalgorithm,
                 const string& tsigsecret,
                 const ComboAddress* laddr);
private:
    string d_tsigkeyname;
    string d_tsigsecret;
    size_t d_receivedBytes;
    size_t d_maxReceivedBytes;
    int d_tsigPos;
    int d_nonSignedMessages;
    int d_sock;
    shared_array<char> d_buf;
    ComboAddress d_remote;
    int d_soacount;
    TSIGRecord d_trc;
    void connect();
};

namespace {
    map<string, string> arg();
    uint16_t dns_random(uint16_t max);
    int makeQuerySocket(const ComboAddress& local, bool udp);
    int waitForData(int fd, int seconds, int useconds);
    string stringerror();
    void addTSIG(DNSPacketWriter& pw, TSIGRecord* trc, const string& keyname, 
                const string& secret, const string& prev, bool timersonly);
}