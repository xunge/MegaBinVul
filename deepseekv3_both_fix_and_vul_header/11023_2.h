#include <cstring>

#define TIGHT_MAX_WIDTH 2048

namespace rdr {
    typedef unsigned char U8;
}

typedef int PIXEL_T;

class PixelFormat {
public:
    void rgbFromBuffer(rdr::U8* pix, const rdr::U8* buf, int count) const;
    void bufferFromRGB(rdr::U8* buf, const rdr::U8* pix, int count) const;
};

class Rect {
public:
    int width() const;
    int height() const;
};

class TightDecoder {
public:
    void FilterGradient(const rdr::U8* inbuf, const PixelFormat& pf, PIXEL_T* outbuf, int stride, const Rect& r);
};