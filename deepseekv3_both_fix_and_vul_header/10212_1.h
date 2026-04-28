#include <stdexcept>

class rdr {
public:
    typedef unsigned int U32;
};

class Exception : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

struct SMsgWriter {
    struct {
        bool supportsFence;
    } *cp;
    
    struct {
        void pad(int);
        void writeU32(rdr::U32);
        void writeU8(unsigned char);
        void writeBytes(const char*, unsigned);
    } *os;
    
    void startMsg(int);
    void endMsg();
    void writeFence(rdr::U32, unsigned, const char[]);
    
    static const rdr::U32 fenceFlagsSupported;
    static const int msgTypeServerFence;
};

const rdr::U32 SMsgWriter::fenceFlagsSupported = 0;
const int SMsgWriter::msgTypeServerFence = 0;