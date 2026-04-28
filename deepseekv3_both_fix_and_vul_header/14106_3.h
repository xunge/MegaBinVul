#include <cstddef>
#include <cstring>
#include <vector>

typedef unsigned char uchar;

struct Slice {
    int type;
    char* base;
    int xStride;
    int yStride;
    int xSampling;
    int ySampling;
    double fillValue;

    Slice(int t, char* b, int xs, int ys, int xsm, int ysm, double fv)
        : type(t), base(b), xStride(xs), yStride(ys), xSampling(xsm), ySampling(ysm), fillValue(fv) {}
};

struct FrameBuffer {
    void insert(const char* name, const Slice& slice) {}
    void setFrameBuffer(const FrameBuffer&) {}
    void readPixels(int, int) {}
};

struct Mat {
    uchar* ptr() { return nullptr; }
    int step;
    int channels() { return 0; }
    int depth() { return 0; }
};

template<typename T>
struct AutoBuffer {
    void allocate(size_t size) {}
    operator T*() { return nullptr; }
};

struct Box2i {
    struct V2i {
        int x;
        int y;
    } min, max;
};

class ExrDecoder {
public:
    int m_width;
    int m_height;
    bool m_iscolor;
    bool m_ischroma;
    bool m_native_depth;
    int m_type;
    Box2i m_datawindow;
    struct Channel {
        int xSampling;
        int ySampling;
    } *m_red, *m_green, *m_blue;
    FrameBuffer* m_file;

    int type() { return 0; }
    void close() {}
    void UpSample(uchar*, int, int, int, int) {}
    void UpSampleX(float*, int, int) {}
    void UpSampleY(uchar*, int, int, int) {}
    void RGBToGray(float*, float*) {}
    void ChromaToBGR(float*, int, int) {}
    bool readData(Mat& img);
};

namespace cv {
    template<typename T>
    T saturate_cast(uchar value) { return T(); }
}

#define FLOAT 1
#define CV_MAT_DEPTH(x) (x)