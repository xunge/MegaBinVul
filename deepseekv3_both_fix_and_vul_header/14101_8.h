#include <cstring>

typedef unsigned char uchar;
typedef unsigned short ushort;

struct channel_layout {
    int bchan;
    int gchan;
    int rchan;
    int graychan;
};

struct pam_format {
    struct channel_layout layout;
    bool (*cvt_func)(const uchar*, uchar*, int, int, int);
};

struct PaletteEntry {
    uchar b, g, r, a;
};

template<typename _Tp> class AutoBuffer {
public:
    explicit AutoBuffer(size_t _size = 0) : ptr_(_size ? new _Tp[_size] : nullptr), size_(_size) {}
    ~AutoBuffer() { delete[] ptr_; }
    void allocate(size_t _size) {
        delete[] ptr_;
        ptr_ = new _Tp[_size];
        size_ = _size;
    }
    _Tp* data() { return ptr_; }
    operator _Tp*() { return ptr_; }
private:
    _Tp* ptr_;
    size_t size_;
};

class DataStream {
public:
    bool isOpened() { return false; }
    void setPos(int pos) {}
    void getBytes(uchar* buf, int count) {}
};

class Mat {
public:
    uchar* ptr() { return nullptr; }
    int channels() { return 0; }
    int step;
    int depth() { return 0; }
};

enum {
    CV_8U = 0,
    CV_16U = 2,
    CV_IMWRITE_PAM_FORMAT_NULL = 0
};

#define CV_ELEM_SIZE1(type) ((0x3a50 >> ((type) << 1)) & 3)

class PAMDecoder {
    int m_offset;
    int m_width;
    int m_height;
    int m_channels;
    int m_type;
    int m_sampledepth;
    bool bit_mode;
    int selected_fmt;
    DataStream m_strm;
    static const pam_format formats[];
    
    bool isBigEndian() { return false; }
    static void FillGrayRow1(uchar* dst, const uchar* src, int len, const uchar* palette) {}
    static void FillColorRow1(uchar* dst, const uchar* src, int len, const PaletteEntry* palette) {}
    static void FillGrayPalette(PaletteEntry* palette, int bpp, bool negative) {}
    static bool basic_conversion(const uchar* src, const channel_layout* layout, int src_channels,
                                int width, uchar* dst, int dst_channels, int dst_depth) { return false; }
public:
    bool readData(Mat& img);
};