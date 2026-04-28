#include <memory>

enum RespectImageOrientationEnum {
    DoNotRespectImageOrientation,
    RespectImageOrientation
};

enum DefaultImageOrientationEnum {
    DefaultImageOrientation
};

struct IntSize {
    int width() const { return 0; }
    int height() const { return 0; }
};

struct FloatPoint {
    FloatPoint() {}
};

struct FloatRect {
    FloatRect(FloatPoint, IntSize) {}
    FloatRect transposedRect() const { return *this; }
};

struct SkBitmap {
    bool tryAllocN32Pixels(int width, int height) { return true; }
    bool copyTo(SkBitmap* dst, int colorType) const { return true; }
    void eraseColor(int color) {}
};

struct SkCanvas {
    SkCanvas(SkBitmap&) {}
    void concat(const float[9]) {}
    void drawBitmapRect(const SkBitmap&, int, const FloatRect&) {}
};

struct ImageOrientation {
    ImageOrientation() {}
    ImageOrientation(DefaultImageOrientationEnum) {}
    bool operator!=(DefaultImageOrientationEnum) const { return false; }
    bool usesWidthAsHeight() const { return false; }
    float* transformFromDefault(const IntSize&) const { return nullptr; }
};

class NativeImageSkia {
public:
    const SkBitmap& bitmap() const { static SkBitmap b; return b; }
};

class Image {
public:
    virtual ~Image() {}
    virtual bool isBitmapImage() const { return false; }
    virtual NativeImageSkia* nativeImageForCurrentFrame() { return nullptr; }
};

class BitmapImage : public Image {
public:
    IntSize sizeRespectingOrientation() const { return IntSize(); }
    ImageOrientation currentFrameOrientation() const { return ImageOrientation(); }
};

BitmapImage* toBitmapImage(Image* image) { return nullptr; }

template<typename T> class PassOwnPtr {
public:
    PassOwnPtr(T* = nullptr) {}
    T* operator->() const { return nullptr; }
};

template<typename T> class RefPtr {
public:
    RefPtr(T* = nullptr) {}
    T* operator->() const { return nullptr; }
    operator bool() const { return false; }
};

class DragImage {
public:
    DragImage(const SkBitmap&, float) {}
    static PassOwnPtr<DragImage> create(Image*, RespectImageOrientationEnum, float);
};

float* affineTransformToSkMatrix(const float*) { return nullptr; }

const int kN32_SkColorType = 0;
const int SK_ColorTRANSPARENT = 0;

template<typename T>
PassOwnPtr<T> adoptPtr(T* ptr) {
    return PassOwnPtr<T>(ptr);
}