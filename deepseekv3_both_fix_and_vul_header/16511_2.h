#include <stdint.h>
#include <stddef.h>

enum tga_type_e {
    TGA_TYPE_NO_DATA = 0,
    TGA_TYPE_INDEXED = 1,
    TGA_TYPE_RGB = 2,
    TGA_TYPE_MONOCHROME = 3,
    TGA_TYPE_RLE_INDEXED = 9,
    TGA_TYPE_RLE_RGB = 10,
    TGA_TYPE_RLE_MONOCHROME = 11
};

typedef struct {
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
} tga_header_s;

enum Error {
    OK,
    FAILED,
    ERR_FILE_CORRUPT
};

template<typename T>
class Ref {
    T* ptr;
};

class Image {};

class FileAccess {
public:
    int get_len();
    uint8_t get_8();
    uint16_t get_16();
    size_t get_position();
    void seek(size_t pos);
    void get_buffer(uint8_t* buf, size_t len);
    void close();
};

template<typename T>
class PoolVector {
public:
    Error resize(size_t size);
    class Write {
    public:
        T* ptr();
        T& operator[](int index);
    };
    class Read {
    public:
        const T* ptr();
    };
    Write write();
    Read read();
};

class ImageLoaderTGA {
public:
    Error load_image(Ref<Image> p_image, FileAccess* f, bool p_force_linear, float p_scale);
    Error decode_tga_rle(const uint8_t* src, size_t pixel_size, uint8_t* dst, size_t buffer_size);
    Error convert_to_image(Ref<Image> p_image, const uint8_t* buffer, const tga_header_s& header, const uint8_t* palette, bool is_monochrome, size_t buffer_size);
    Error convert_to_image(Ref<Image> p_image, const uint8_t* buffer, const tga_header_s& header, const uint8_t* palette, bool is_monochrome);
};

#define ERR_FAIL_COND_V(cond, ret) if (cond) return ret