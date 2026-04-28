#include <stdint.h>
#include <stdexcept>

typedef struct x3f_huffman_t x3f_huffman_t;

typedef struct {
    uint8_t *data;
    uint32_t data_size;
    uint32_t columns;
    int type_format;
    x3f_huffman_t *huffman;
} x3f_image_data_t;

typedef struct x3f_huffman_t {
    struct {
        uint32_t *element;
    } row_offsets;
    struct {
        uint16_t *data;
    } x3rgb16;
    struct {
        uint8_t *data;
    } rgb8;
    void *tree;
} x3f_huffman_t;

typedef struct {
    struct {
        x3f_image_data_t image_data;
    } data_subsection;
} x3f_directory_entry_header_t;

typedef struct {
    x3f_directory_entry_header_t header;
} x3f_directory_entry_t;

typedef struct {
} x3f_info_t;

typedef struct {
} bit_state_t;

#define LIBRAW_EXCEPTION_IO_CORRUPT 1

enum {
    X3F_IMAGE_RAW_HUFFMAN_X530,
    X3F_IMAGE_RAW_HUFFMAN_10BIT,
    X3F_IMAGE_THUMB_HUFFMAN
};

void set_bit_state(bit_state_t *BS, uint8_t *data);
int get_huffman_diff(bit_state_t *BS, void *tree);