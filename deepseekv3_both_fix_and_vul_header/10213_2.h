#include <stdexcept>
#include <cstdint>

namespace rdr {
    class InStream {
    public:
        bool checkNoWait(size_t len);
        uint32_t readU32();
        void readBytes(char* buf, size_t len);
    };
}

class SConnection {
public:
    rdr::InStream* getInStream();
};

class CharArray {
public:
    void replaceBuf(char* buf);
};

class AuthFailureException : public std::runtime_error {
public:
    explicit AuthFailureException(const char* msg) : std::runtime_error(msg) {}
};

class Validator {
public:
    bool validate(SConnection* sc, const char* uname, const char* pw);
};

struct SSecurityPlain {
    Validator* valid;
    int state;
    uint32_t ulen;
    uint32_t plen;
    CharArray username;
    bool processMsg(SConnection* sc);
};