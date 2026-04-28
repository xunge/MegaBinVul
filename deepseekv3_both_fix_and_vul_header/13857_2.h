#include <string>
#include <vector>
#include <cstring>

namespace Symbols {
    const char EQUALS[1] = {'='};
    const char SPACE[1] = {' '};
    const char SLASH[1] = {'/'};
    const char CR[1] = {'\r'};
    const char LF[1] = {'\n'};
    const char CRLF[2] = {'\r', '\n'};
}

class Data {
public:
    Data();
    Data(const char* data, size_t size);
    Data(const char* data);
    Data(int value);
    const char* data() const;
    size_t size() const;
    char operator[](size_t pos) const;
    Data operator+(const Data& other) const;
};

class ParseBuffer {
public:
    ParseBuffer(const char* data, size_t size);
    const char* skipChar(char c);
    void skipChar();
    void skipToChar(char c);
    void data(std::string& out, const char* anchor);
    void data(Data& out, const char* anchor);
    int integer();
    const char* position() const;
    bool eof() const;
    void skipToOneOf(const char* symbols, const char* symbols2);
    void skipToOneOf(const char* symbols);
    void fail(const char* file, int line, const char* message);
};

namespace Helper {
    int hex2integer(const char* hex);
    void integer2hex(char* out, int value, bool suppressLeadingZeros);
};

class Connection {
public:
    void parse(ParseBuffer& pb);
    const Data& getAddress() const;
    Data mAddress;
};

class Bandwidth {
public:
    void parse(ParseBuffer& pb);
};

class Encryption {
public:
    void parse(ParseBuffer& pb);
};

class AttributeHelper {
public:
    void parse(ParseBuffer& pb);
};

class SdpContents {
public:
    class Session {
    public:
        class Medium {
        public:
            void parse(ParseBuffer& pb);
            std::string mName;
            int mPort;
            int mMulticast;
            std::string mProtocol;
            std::string mInformation;
            std::vector<Connection> mConnections;
            std::vector<Bandwidth> mBandwidths;
            Encryption mEncryption;
            AttributeHelper mAttributeHelper;
            void addFormat(const Data& format);
            void addConnection(const Connection& conn);
            void addBandwidth(const Bandwidth& bw);
        };
    };
};

void skipEol(ParseBuffer& pb);