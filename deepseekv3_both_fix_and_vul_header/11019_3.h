#include <stdexcept>

typedef unsigned char U8;

#define Z_OK 0
#define Z_SYNC_FLUSH 2

struct Exception : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

struct z_stream {
    U8* next_out;
    unsigned avail_out;
    U8* next_in;
    unsigned avail_in;
};

struct UnderlyingStream {
    virtual int check(int, int, bool) = 0;
    virtual U8* getptr() = 0;
    virtual U8* getend() = 0;
    virtual void setptr(U8*) = 0;
};

struct ZlibInStream {
    z_stream* zs;
    U8* end;
    U8* start;
    int bufSize;
    int bytesIn;
    UnderlyingStream* underlying;
    bool decompress(bool wait);
};

int inflate(z_stream*, int);