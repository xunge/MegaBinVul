#include <algorithm>
#include <stdexcept>

#define __rfbmin(a,b) std::min(a,b)

struct Point {
    int x;
    int y;
};

struct Rect {
    Point tl;
    Point br;
    
    int width() const { return br.x - tl.x; }
    int height() const { return br.y - tl.y; }
    int area() const { return width() * height(); }
};

namespace rdr {
    class InStream {
    public:
        unsigned int readU32();
        unsigned char readU8();
    };
    
    typedef unsigned char U8;
    
    class ZlibInStream {
    public:
        void setUnderlying(InStream* is, int length);
        void removeUnderlying();
        void flushUnderlying();
        unsigned char readU8();
        void readBytes(void* buf, int length);
    };
}

class PixelFormat {};
class ModifiablePixelBuffer {
public:
    void fillRect(const PixelFormat& pf, const Rect& r, const void* pixel);
    void imageRect(const PixelFormat& pf, const Rect& r, const void* pixels);
};

class Exception : public std::runtime_error {
public:
    Exception(const char* msg) : std::runtime_error(msg) {}
};

#define PIXEL_T unsigned int
#define BPP 32
#define READ_PIXEL(zis) (zis->readU8())