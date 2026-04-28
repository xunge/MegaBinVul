#include <stddef.h>
#include <stdint.h>

typedef int Error;

#define OK 0
#define ERR_PARSE_ERROR -1

class ImageLoaderTGA {
public:
    Error decode_tga_rle(const uint8_t *p_compressed_buffer, size_t p_pixel_size, uint8_t *p_uncompressed_buffer, size_t p_output_size);
};

template <typename T>
class Vector {
public:
    T* ptrw();
    Error resize(size_t p_size);
};