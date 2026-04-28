#include <vector>
#include <cstring>
#include <cstddef>

typedef unsigned char uchar;

#define BMP_RGB 0
#define alignSize(size, align) (((size) + (align) - 1) & ~((align) - 1))

struct PaletteEntry {
    uchar b;
    uchar g;
    uchar r;
    uchar a;
};

class Mat {
public:
    int cols;
    int rows;
    int channels() const { return 0; }
    const uchar* ptr(int y) const { return nullptr; }
};

class WLByteStream {
public:
    bool open(const std::vector<uchar>& buf) { return false; }
    bool open(const char* filename) { return false; }
    void putBytes(const void* data, int len) {}
    void putDWord(int val) {}
    void putWord(int val) {}
    void close() {}
};

static const char fmtSignBmp[] = "BM";

static inline int validateToInt(size_t val) { return (int)val; }

static void FillGrayPalette(PaletteEntry* palette, int bpp) {}

class BmpEncoder {
public:
    std::vector<uchar>* m_buf;
    const char* m_filename;

    bool write(const Mat& img, const std::vector<int>&);
};