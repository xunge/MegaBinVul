#include <memory>
#include <algorithm>

struct IntPoint {
    int x;
    int y;
    
    IntPoint() : x(0), y(0) {}
    IntPoint(int x, int y) : x(x), y(y) {}
};

struct IntRect {
    IntPoint location;
    IntPoint dimensions;
    
    IntRect() = default;
    IntRect(const IntPoint& loc, const IntPoint& dim) : location(loc), dimensions(dim) {}
    
    int width() const { return dimensions.x; }
    int height() const { return dimensions.y; }
    int x() const { return location.x; }
    int y() const { return location.y; }
    
    IntPoint size() const { return dimensions; }
};

struct ImageData {
    struct Data {
        const unsigned char* data() const { return nullptr; }
    };
    
    Data* data() const { return nullptr; }
    IntPoint size() const { return IntPoint(); }
};

class Image {};

enum AlphaOption {
    Opaque,
    NonOpaque
};

enum InitializePixels {
    DoNotInitializeImagePixels,
    InitializeImagePixels
};

enum PixelFormat {
    Premultiplied,
    Unpremultiplied
};

class ImageBuffer {
public:
    static std::unique_ptr<ImageBuffer> create(const IntPoint&, AlphaOption, InitializePixels) { return nullptr; }
    void putByteArray(PixelFormat, const unsigned char*, const IntPoint&, const IntRect&, const IntPoint&) {}
    std::unique_ptr<Image> newImageSnapshot() { return nullptr; }
};

template<typename T>
using OwnPtr = std::unique_ptr<T>;

class ImageBitmap {
private:
    Image* m_imageElement;
    IntRect m_cropRect;
    IntPoint m_bitmapOffset;
    std::unique_ptr<Image> m_bitmap;
    IntRect m_bitmapRect;
    
public:
    ImageBitmap(ImageData*, const IntRect&);
};

IntRect intersection(const IntRect& a, const IntRect& b) {
    return IntRect();
}