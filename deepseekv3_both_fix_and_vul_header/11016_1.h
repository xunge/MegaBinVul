#include <cassert>
#include <cstring>

namespace rdr {
    typedef unsigned char U8;
    typedef unsigned short U16;
    typedef unsigned int U32;

    class U8Array {
    public:
        U8* buf;
        explicit U8Array(size_t len) { buf = new U8[len]; }
        ~U8Array() { delete[] buf; }
    };

    class MemInStream {
    public:
        MemInStream(const U8* data, size_t len) {}
        ~MemInStream() {}
    };
}

class Rect {
public:
    int width() const;
    int height() const;
    int area() const;
};

class PixelFormat {
public:
    bool is888() const;
    int bpp;
    void bufferFromRGB(rdr::U8* dst, const rdr::U8* src, int pixels) const;
    bool equal(const PixelFormat& other) const;
};

class ServerParams {
public:
    const PixelFormat& pf() const;
};

class ModifiablePixelBuffer {
public:
    void fillRect(const PixelFormat& pf, const Rect& r, const rdr::U8* data);
    rdr::U8* getBufferRW(const Rect& r, int* stride);
    void commitBufferRW(const Rect& r);
    const PixelFormat& getPF() const;
    void imageRect(const PixelFormat& pf, const Rect& r, const rdr::U8* data);
};

class JpegDecompressor {
public:
    void decompress(const rdr::U8* src, rdr::U32 len, rdr::U8* dst, int stride, const Rect& r, const PixelFormat& pf);
};

class ZlibInStream {
public:
    void reset();
    void setUnderlying(rdr::MemInStream* ms, size_t len);
    void readBytes(rdr::U8* buf, size_t len);
    void flushUnderlying();
    void removeUnderlying();
};

enum {
    tightFill,
    tightJpeg,
    tightMaxSubencoding,
    tightExplicitFilter,
    tightFilterPalette,
    tightFilterGradient,
    tightFilterCopy,
    TIGHT_MIN_TO_COMPRESS = 12
};

void FilterGradient24(const rdr::U8* src, const PixelFormat& pf, rdr::U32* dst, int stride, const Rect& r);
void FilterGradient(const rdr::U8* src, const PixelFormat& pf, rdr::U16* dst, int stride, const Rect& r);
void FilterGradient(const rdr::U8* src, const PixelFormat& pf, rdr::U32* dst, int stride, const Rect& r);
void FilterPalette(const rdr::U8* palette, int palSize, const rdr::U8* src, rdr::U8* dst, int stride, const Rect& r);
void FilterPalette(const rdr::U16* palette, int palSize, const rdr::U8* src, rdr::U16* dst, int stride, const Rect& r);
void FilterPalette(const rdr::U32* palette, int palSize, const rdr::U8* src, rdr::U32* dst, int stride, const Rect& r);

class TightDecoder {
    ZlibInStream zis[4];
public:
    void decodeRect(const Rect& r, const void* buffer, size_t buflen, const ServerParams& server, ModifiablePixelBuffer* pb);
};