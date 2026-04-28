#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <vector>

#define BITMAP_SIZE 0
#define USHORT_RANGE 0
#define MINIZ_LITTLE_ENDIAN 1
#define TINYEXR_PIXELTYPE_HALF 1

struct EXRChannelInfo {
    int pixel_type;
};

struct PIZChannelData {
    unsigned short* start;
    unsigned short* end;
    int nx;
    int ny;
    int size;
};

namespace tinyexr {
    void cpy2(unsigned short* dst, const unsigned short* src);
    void cpy4(int* dst, const int* src);
}

unsigned short reverseLutFromBitmap(const unsigned char* bitmap, unsigned short* lut);
void hufUncompress(const char* src, int srcSize, unsigned short* dst, int dstSize);
void hufUncompress(const char* src, int srcSize, std::vector<unsigned short>* dst);
void wav2Decode(unsigned short* data, int nx, int size, int ny, int stride, unsigned short maxValue);
void applyLut(unsigned short* lut, unsigned short* data, int dataSize);