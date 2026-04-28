#include <stdint.h>
#include <stddef.h>

#define ERR_FAIL_COND_V(cond, ret) if (cond) return ret

enum Error {
    OK,
    FAILED,
    ERR_FILE_CORRUPT
};

enum tga_type_e {
    TGA_TYPE_NO_DATA,
    TGA_TYPE_INDEXED,
    TGA_TYPE_RGB,
    TGA_TYPE_MONOCHROME,
    TGA_TYPE_RLE_INDEXED,
    TGA_TYPE_RLE_RGB,
    TGA_TYPE_RLE_MONOCHROME
};

struct tga_header_s {
    uint8_t id_length;
    uint8_t color_map_type;
    tga_type_e image_type;
    uint16_t first_color_entry;
    uint16_t color_map_length;
    uint8_t color_map_depth;
    uint16_t x_origin;
    uint16_t y_origin;
    uint16_t image_width;
    uint16_t image_height;
    uint8_t pixel_depth;
    uint8_t image_descriptor;
};

template<typename T>
class Vector {
public:
    T* ptrw();
    const T* ptr() const;
    Error resize(size_t size);
};

class Image {};

template<typename T>
class Ref {
public:
    Ref(T* p);
};

class FileAccess {
public:
    size_t get_len();
    uint8_t get_8();
    uint16_t get_16();
    size_t get_position();
    void seek(size_t position);
    void get_buffer(uint8_t* buffer, size_t length);
    void close();
};

class ImageLoaderTGA {
public:
    Error load_image(Ref<Image> p_image, FileAccess* f, bool p_force_linear, float p_scale);
};

Error decode_tga_rle(const uint8_t* src, size_t pixel_size, uint8_t* dst, size_t buffer_size);
Error convert_to_image(Ref<Image> p_image, const uint8_t* buffer, const tga_header_s& tga_header, const uint8_t* palette, bool is_monochrome, size_t buffer_size);
Error convert_to_image(Ref<Image> p_image, const uint8_t* buffer, const tga_header_s& tga_header, const uint8_t* palette, bool is_monochrome);