#include <string.h>

#define TIGHT_MAX_WIDTH 2048

typedef int PIXEL_T;

namespace rdr {
    typedef unsigned char U8;
}

class PixelFormat {
public:
    void bufferFromRGB(rdr::U8* out, const rdr::U8* in, int pixels) const;
};

class Rect {
public:
    int width() const;
    int height() const;
};

class TightDecoder {
public:
    void FilterGradient24(const rdr::U8* inbuf, const PixelFormat& pf, PIXEL_T* outbuf, int stride, const Rect& r);
};