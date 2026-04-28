#include <cstdint>
#include <memory>

enum SkAlphaType {
    kOpaque_SkAlphaType,
    kPremul_SkAlphaType
};

enum SkPixelGeometry {
    kUnknown_SkPixelGeometry
};

class SkImageInfo {
public:
    static SkImageInfo MakeN32(int width, int height, SkAlphaType alphaType);
};

class SkSurfaceProps {
public:
    SkSurfaceProps(unsigned flags, SkPixelGeometry geometry);
};

class SkSurface {
public:
    static SkSurface* NewRaster(const SkImageInfo& info, const SkSurfaceProps* props);
};

class IntSize {
public:
    IntSize(int width, int height);
    int width() const;
    int height() const;
};

enum OpacityMode {
    Opaque,
    NonOpaque
};

enum ImageInitializationMode {
    InitializeImagePixels,
    DoNotInitializeImagePixels
};

class ImageBufferSurface {
public:
    ImageBufferSurface(const IntSize& size, OpacityMode opacityMode);
    virtual ~ImageBufferSurface();
    virtual void clear();
};

template<typename T> class RefPtr {
public:
    RefPtr() : m_ptr(nullptr) {}
    RefPtr(T* ptr) : m_ptr(ptr) {}
    T* get() const { return m_ptr; }
    operator bool() const { return m_ptr; }
private:
    T* m_ptr;
};

template<typename T> RefPtr<T> adoptRef(T* ptr) {
    return RefPtr<T>(ptr);
}

class UnacceleratedImageBufferSurface : public ImageBufferSurface {
private:
    RefPtr<SkSurface> m_surface;
public:
    UnacceleratedImageBufferSurface(const IntSize& size, OpacityMode opacityMode, ImageInitializationMode initializationMode);
};