#include <vector>
#include <memory>
#include <string>
#include <ostream>
#include <cstdint>
#include <netinet/in.h>

using namespace std;

struct sockaddr_in;

class DNSName {
public:
    bool isPartOf(const DNSName& other) const;
    friend ostream& operator<<(ostream& os, const DNSName& name);
};

class DNSResourceRecord {
public:
    class QType {
    public:
        int getCode() const;
        string getName() const;
        static const int OPT;
        static const int TSIG;
        static const int SOA;
    } qtype;
    DNSName qname;
    string content;
};

class ComboAddress {
public:
    struct sockaddr_in sin4;
    string toStringWithPort() const;
};

class TSIGTriplet {};
class AuthLua {
public:
    bool axfrfilter(const ComboAddress&, const DNSName&, const DNSResourceRecord&, vector<DNSResourceRecord>&);
};

class Logger {
public:
    enum LogLevel { Error };
    Logger& operator<<(LogLevel);
    Logger& operator<<(const string&);
    Logger& operator<<(ostream& (*)(ostream&));
    Logger& operator<<(const DNSName&);
};
extern Logger L;

class AXFRRetriever {
public:
    AXFRRetriever(const ComboAddress&, const DNSName&, const TSIGTriplet&, const ComboAddress*, size_t = 0);
    bool getChunk(vector<DNSResourceRecord>&);
};

class Resolver {
public:
    typedef vector<DNSResourceRecord> res_t;
};

class QType {
public:
    static const int OPT;
    static const int TSIG;
    static const int SOA;
};

struct SOAData {
    uint32_t serial;
};

struct ZoneStatus {
    uint32_t soa_serial;
};

class Arg {
public:
    static Arg& getInstance() {
        static Arg instance;
        return instance;
    }
    int asNum(const string&) const;
};
inline Arg& arg() { return Arg::getInstance(); }

template<typename T>
class scoped_ptr {
public:
    explicit scoped_ptr(T* ptr = nullptr);
    ~scoped_ptr();
    T* operator->() const;
    T& operator*() const;
    explicit operator bool() const;
};

bool processRecordForZS(const DNSName&, bool&, DNSResourceRecord&, ZoneStatus&);
void fillSOAData(const string&, SOAData&);

ostream& operator<<(ostream& os, const DNSName& name);