#include <stdexcept>
#include <cstdint>

class AuthFailureException : public std::runtime_error {
public:
    explicit AuthFailureException(const char* msg) : std::runtime_error(msg) {}
};

namespace rdr {
    class InStream {
    public:
        bool checkNoWait(size_t len);
        uint32_t readU32();
        void readBytes(char* buf, size_t len);
    };
}

class CharArray {
public:
    void replaceBuf(char* buf);
};

class SConnection {
public:
    rdr::InStream* getInStream();
};

class Validator {
public:
    bool validate(SConnection* sc, const char* uname, const char* pw);
};

class SSecurityPlain {
private:
    Validator* valid;
    int state;
    uint32_t ulen;
    uint32_t plen;
    CharArray username;
    static const uint32_t MaxSaneUsernameLength = 256;
    static const uint32_t MaxSanePasswordLength = 256;
public:
    bool processMsg(SConnection* sc);
};