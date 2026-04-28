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

struct tga_header_s {
    uint16_t image_width;
    uint16_t image_height;
    uint8_t pixel_depth;
    uint8_t color_map_depth;
    uint8_t image_descriptor;
};

#define TGA_ORIGIN_MASK 0x30
#define TGA_ORIGIN_SHIFT 4

template <typename T>
class Vector {
public:
    void resize(size_t size);
    T* ptrw();
};

class Image {
public:
    enum Format {
        FORMAT_RGBA8
    };
    void create(uint32_t width, uint32_t height, bool mipmaps, Format format, const Vector<uint8_t>& data);
};

template <typename T>
class Ref {
public:
    T* operator->();
};

class ImageLoaderTGA {
public:
    Error convert_to_image(Ref<Image> p_image, const uint8_t* p_buffer, const tga_header_s& p_header, const uint8_t* p_palette, bool p_is_monochrome, size_t p_output_size);
    Error convert_to_image(Ref<Image> p_image, const uint8_t* p_buffer, const tga_header_s& p_header, const uint8_t* p_palette, bool p_is_monochrome);
};