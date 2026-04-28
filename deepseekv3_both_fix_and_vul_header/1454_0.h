#include <stdint.h>
#include <stdexcept>

#define LIBRAW_EXCEPTION_IO_CORRUPT std::runtime_error("IO corrupt")

typedef struct x3f_info_s x3f_info_t;
typedef struct x3f_directory_entry_s x3f_directory_entry_t;
typedef struct x3f_directory_entry_header_s x3f_directory_entry_header_t;
typedef struct x3f_image_data_s x3f_image_data_t;
typedef struct x3f_huffman_s x3f_huffman_t;

enum {
    X3F_IMAGE_RAW_HUFFMAN_X530,
    X3F_IMAGE_RAW_HUFFMAN_10BIT,
    X3F_IMAGE_THUMB_HUFFMAN
};

struct x3f_huffman_s {
    struct {
        uint16_t *data;
    } x3rgb16;
    struct {
        uint8_t *data;
    } rgb8;
};

struct x3f_image_data_s {
    x3f_huffman_t *huffman;
    size_t data_size;
    int columns;
    int type_format;
    void *data;
};

struct x3f_directory_entry_header_s {
    struct {
        x3f_image_data_t image_data;
    } data_subsection;
};

struct x3f_directory_entry_s {
    x3f_directory_entry_header_t header;
};

static uint16_t get_simple_diff(x3f_huffman_t *HUF, uint32_t val);