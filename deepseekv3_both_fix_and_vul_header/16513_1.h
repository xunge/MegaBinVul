#include <stddef.h>
#include <stdint.h>

typedef enum {
    OK,
    ERR_PARSE_ERROR
} Error;

template <typename T>
class PoolVector {
public:
    Error resize(size_t p_size);
    class Write {
    public:
        T* ptr();
    };
    Write write();
};

class ImageLoaderTGA {
public:
    Error decode_tga_rle(const uint8_t *p_compressed_buffer, size_t p_pixel_size, uint8_t *p_uncompressed_buffer, size_t p_output_size);
};