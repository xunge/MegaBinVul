#include <cstddef>
#include <cstring>
#include <cassert>

typedef unsigned char uchar;

struct Size {
    int width;
    int height;
    Size(int w, int h) : width(w), height(h) {}
};

inline Size cvSize(int width, int height) {
    return Size(width, height);
}

struct Mat {
    int channels() const;
    uchar* ptr();
    size_t step;
    int width;
    int height;
};

template<typename T>
class AutoBuffer {
public:
    AutoBuffer(size_t size);
    ~AutoBuffer();
    operator T*();
};

class SunRasterDecoder {
    int m_width;
    int m_height;
    int m_bpp;
    int m_offset;
    int m_maptype;
    int m_type;
    uchar* m_palette;
    class Stream {
    public:
        bool isOpened();
        void setPos(int pos);
        void getBytes(uchar* buf, int count);
        uchar getByte();
    } m_strm;
    
    bool readData(Mat& img);
};

enum {
    RMT_EQUAL_RGB,
    RAS_BYTE_ENCODED,
    RAS_FORMAT_RGB
};

void CvtPaletteToGray(const uchar* palette, uchar* gray_palette, int entries);
void FillColorRow1(uchar* data, const uchar* src, int width, const uchar* palette);
void FillGrayRow1(uchar* data, const uchar* src, int width, const uchar* gray_palette);
void FillColorRow8(uchar* data, const uchar* src, int width, const uchar* palette);
void FillGrayRow8(uchar* data, const uchar* src, int width, const uchar* gray_palette);
uchar* FillUniColor(uchar* data, uchar* line_end, int step, int width3, int y, int height, int len, uchar color);
uchar* FillUniGray(uchar* data, uchar* line_end, int step, int width3, int y, int height, int len, uchar gray);
void icvCvt_RGB2BGR_8u_C3R(uchar* src, int src_step, uchar* dst, int dst_step, Size size);
void icvCvt_BGR2Gray_8u_C3C1R(uchar* src, int src_step, uchar* dst, int dst_step, Size size, int swap_rb);
void icvCvt_BGRA2BGR_8u_C4C3R(uchar* src, int src_step, uchar* dst, int dst_step, Size size, int swap_rb);
void icvCvt_BGRA2Gray_8u_C4C1R(uchar* src, int src_step, uchar* dst, int dst_step, Size size, int swap_rb);
int validateToInt(size_t val);