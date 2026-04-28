#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <stdexcept>
#include <iterator>

using namespace std;

class DNSName {
public:
    string toString() const;
    bool empty() const;
};

class DNSRecord {
public:
    int d_type;
};

class RCode {
public:
    static string to_s(int);
};

class TSIGRecordContent {
public:
    string d_mac;
    DNSName d_algoName;
    uint64_t d_time;
};

class GssContext {
public:
    GssContext(const DNSName&);
};

class ResolverException : public runtime_error {
public:
    using runtime_error::runtime_error;
};

namespace Resolver {
    struct res_t {};
}

enum TSIGHashEnum {
    TSIG_GSS
};

class MOADNSParser {
public:
    struct answers_t {
        typedef pair<DNSRecord, DNSName> value_type;
        vector<value_type> d_answers;
        
        vector<value_type>::iterator begin() { return d_answers.begin(); }
        vector<value_type>::iterator end() { return d_answers.end(); }
        vector<value_type>::const_iterator begin() const { return d_answers.begin(); }
        vector<value_type>::const_iterator end() const { return d_answers.end(); }
    };
    struct header_t {
        int rcode;
    };
    
    answers_t d_answers;
    header_t d_header;
    
    MOADNSParser(const char*, int);
    size_t getTSIGPos();
};

class QType {
public:
    static const int SOA;
    static const int TSIG;
};

const int QType::SOA = 6;
const int QType::TSIG = 250;

class AXFRRetriever {
public:
    int getChunk(Resolver::res_t &res, vector<DNSRecord>* records);
private:
    int d_soacount;
    size_t d_maxReceivedBytes;
    size_t d_receivedBytes;
    int d_nonSignedMessages;
    size_t d_tsigPos;
    string d_prevMac;
    string d_signData;
    struct {
        DNSName name;
        string secret;
    } d_tt;
    TSIGRecordContent d_trc;
    struct {
        string toStringWithPort();
    } d_remote;
    unique_ptr<char[]> d_buf;
    
    int getLength();
    void timeoutReadn(int);
    int parseResult(MOADNSParser&, const DNSName&, int, int, Resolver::res_t*);
    string makeTSIGMessageFromTSIGPacket(const string&, size_t, const DNSName&, const TSIGRecordContent&, const string&, bool, size_t);
    string makeTSIGMessageFromTSIGPacket(const string&, size_t, const DNSName&, const TSIGRecordContent&, const string&, bool);
    bool gss_verify_signature(const DNSName&, const string&, const string&);
    string calculateHMAC(const string&, const string&, TSIGHashEnum);
    bool getTSIGHashEnum(const DNSName&, TSIGHashEnum&);
};

template<typename T>
shared_ptr<T> getRR(const DNSRecord&) {
    return shared_ptr<T>();
}