#include <algorithm>
#include <cmath>

template <typename T>
class Array2D {
public:
    Array2D(int height, int width);
    void resizeErase(int height, int width);
    T* operator[](int index);
};

struct Rgba {
    float r, g, b, a;
};

struct PreviewRgba {
    unsigned char r, g, b, a;
};

struct Box2i {
    struct V2i {
        int x, y;
    };
    V2i min, max;
};

class RgbaInputFile {
public:
    RgbaInputFile(const char[]);
    Box2i dataWindow();
    float pixelAspectRatio();
    void setFrameBuffer(Rgba*, int, int);
    void readPixels(int, int);
};

namespace IMATH_NAMESPACE {
    template <typename T> T clamp(T val, T min, T max);
}

template <typename T> class Math {
public:
    static T pow(T base, T exp);
};

template <typename T>
T* ComputeBasePointer(T* ptr, Box2i dw);

float gamma(float val, float m);

using std::max;