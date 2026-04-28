#include <string.h>
#include <stdint.h>

typedef uint8_t U8;

struct Point {
    int x;
    int y;
};

struct Rect {
    Point tl;
    int width() const;
    int height() const;
    bool enclosed_by(const Rect&) const;
    Rect intersect(const Rect&) const;
    bool is_empty() const;
};

class VLog {
public:
    void error(const char* fmt, ...);
};

extern VLog vlog;

class ModifiablePixelBuffer {
public:
    void fillRect(const Rect& r, const void* pix);
    Rect getRect() const;
    U8* getBufferRW(const Rect& r, int* stride);
    void commitBufferRW(const Rect& r);
    int width_;
    int height_;
    struct {
        int bpp;
    } format;
};