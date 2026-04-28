#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>

typedef enum {
    GIF_OK,
    GIF_INSUFFICIENT_DATA,
    GIF_INSUFFICIENT_FRAME_DATA,
    GIF_DATA_ERROR,
    GIF_INSUFFICIENT_MEMORY
} gif_result;

typedef enum {
    LZW_OK,
    LZW_OK_EOD,
    LZW_ERROR
} lzw_result;

typedef enum {
    GIF_FRAME_CLEAR,
    GIF_FRAME_RESTORE
} gif_frame_disposal_method;

#define GIF_IMAGE_SEPARATOR 0x2C
#define GIF_TRAILER 0x3B
#define GIF_COLOUR_TABLE_SIZE_MASK 0x07
#define GIF_INTERLACE_MASK 0x40
#define GIF_COLOUR_TABLE_MASK 0x80
#define GIF_TRANSPARENT_COLOUR 0x00000000
#define GIF_INVALID_FRAME -1

typedef struct {
    bool display;
    unsigned int frame_pointer;
    bool transparency;
    unsigned int transparency_index;
    gif_frame_disposal_method disposal_method;
    bool virgin;
    bool opaque;
} gif_frame;

typedef struct {
    void *(*bitmap_get_buffer)(void *);
    bool (*bitmap_test_opaque)(void *);
    void (*bitmap_set_opaque)(void *, bool);
    void (*bitmap_modified)(void *);
} gif_bitmap_callback_vt;

typedef struct {
    const unsigned char *gif_data;
    size_t buffer_size;
    ssize_t buffer_position;
    unsigned int width;
    unsigned int height;
    unsigned int frame_count_partial;
    int decoded_frame;
    unsigned int *global_colour_table;
    unsigned int *local_colour_table;
    unsigned int background_index;
    void *frame_image;
    gif_frame *frames;
    void *lzw_ctx;
    gif_bitmap_callback_vt bitmap_callbacks;
} gif_animation;

static unsigned int gif_interlaced_line(unsigned int height, unsigned int y);
static gif_result gif_skip_frame_extensions(gif_animation *gif);
static gif_result gif_error_from_lzw(lzw_result res);
static lzw_result lzw_decode_init(void *ctx, const unsigned char *data, size_t size, ssize_t pos, unsigned char code_size, const uint8_t **stack_base, const uint8_t **stack_pos);
static lzw_result lzw_decode(void *ctx, const uint8_t **stack_pos);