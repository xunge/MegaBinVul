#include <cstddef>
#include <stdexcept>

namespace rdr {
    typedef int S32;
    typedef unsigned int U32;
    typedef unsigned char U8;
    
    class InStream {
    public:
        void skip(int len);
        U32 readU32();
        void readBytes(U8* buf, size_t len);
    };
    
    class ZlibInStream : public InStream {
    public:
        void setUnderlying(InStream* is, int len);
        void removeUnderlying();
        void flushUnderlying();
    };
}

class Exception : public std::exception {
public:
    Exception(const char* msg);
};

class Log {
public:
    void error(const char* format, ...);
};

class ClipboardHandler {
public:
    void handleClipboardCaps(rdr::U32 flags, rdr::U32 lengths[16]);
    void handleClipboardProvide(rdr::U32 flags, size_t lengths[16], rdr::U8* buffers[16]);
    void handleClipboardRequest(rdr::U32 flags);
    void handleClipboardPeek(rdr::U32 flags);
    void handleClipboardNotify(rdr::U32 flags);
};

class SMsgReader {
public:
    void readExtendedClipboard(rdr::S32 len);

protected:
    rdr::InStream* is;
    ClipboardHandler* handler;
    Log vlog;
    static const int maxCutText = 256 * 1024;
    static const rdr::U32 clipboardActionMask = 0x7;
    static const rdr::U32 clipboardCaps = 0x8;
    static const rdr::U32 clipboardProvide = 0x1;
    static const rdr::U32 clipboardRequest = 0x2;
    static const rdr::U32 clipboardPeek = 0x3;
    static const rdr::U32 clipboardNotify = 0x4;
};