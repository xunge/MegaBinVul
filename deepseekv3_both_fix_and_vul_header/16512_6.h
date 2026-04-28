#include <stdint.h>
#include <stddef.h>

enum Error {
    OK,
    ERR_PARSE_ERROR,
    ERR_INVALID_DATA
};

enum tga_origin_e {
    TGA_ORIGIN_TOP_LEFT,
    TGA_ORIGIN_TOP_RIGHT,
    TGA_ORIGIN_BOTTOM_LEFT,
    TGA_ORIGIN_BOTTOM_RIGHT
};

#define TGA_ORIGIN_MASK 0x30
#define TGA_ORIGIN_SHIFT 4

struct tga_header_s {
    uint32_t image_width;
    uint32_t image_height;
    uint8_t image_descriptor;
    uint8_t pixel_depth;
    uint8_t color_map_depth;
};

template <typename T>
class Ref {
public:
    Ref(T* ptr) : ptr_(ptr) {}
    T* operator->() { return ptr_; }
private:
    T* ptr_;
};

class Image {
public:
    enum Format {
        FORMAT_RGBA8
    };
    void create(uint32_t width, uint32_t height, int mipmaps, Format format, const uint8_t* data) {}
};

template<typename T>
class PoolVectorWrite {
public:
    T* ptr() { return nullptr; }
    void release() {}
    T& operator[](size_t index) { static T t; return t; }
};

template<typename T>
class PoolVector {
public:
    using Write = PoolVectorWrite<T>;
    
    void resize(size_t size) {}
    Write write() { return Write(); }
    const T* ptr() const { return nullptr; }
    operator const T*() const { return ptr(); }
};

class ImageLoaderTGA {
public:
    static Error convert_to_image(Ref<Image> p_image, const uint8_t* p_buffer, const tga_header_s& p_header, const uint8_t* p_palette, bool p_is_monochrome, size_t p_output_size);
    static Error convert_to_image(Ref<Image> p_image, const uint8_t* p_buffer, const tga_header_s& p_header, const uint8_t* p_palette, bool p_is_monochrome);
};