#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <stddef.h>

#define MAX_SAMPLING_FACTOR 4
#define OK_JPG_BLOCK_EXTRA_SPACE 64

typedef enum {
    OK_JPG_ERROR_INVALID,
    OK_JPG_ERROR_UNSUPPORTED,
    OK_JPG_ERROR_ALLOCATION,
    OK_JPG_ERROR_API
} ok_jpg_error_type;

typedef struct {
    void *(*alloc)(void *user_data, size_t size);
    void (*image_alloc)(void *user_data, int width, int height, int bpp, uint8_t **data, uint32_t *stride);
} ok_jpg_allocator;

typedef struct {
    int id;
    int H;
    int V;
    int Tq;
    int blocks_h;
    int blocks_v;
    void (*idct)(void);
    int16_t *blocks;
} ok_jpg_component;

typedef struct {
    int width;
    int height;
    int bpp;
    uint32_t stride;
    uint8_t *data;
} ok_jpg;

typedef struct {
    ok_jpg *jpg;
    bool rotate;
    bool progressive;
    bool info_only;
    bool sof_found;
    int in_width;
    int in_height;
    int num_components;
    int data_units_x;
    int data_units_y;
    ok_jpg_component components[4];
    ok_jpg_allocator allocator;
    void *allocator_user_data;
} ok_jpg_decoder;

static inline int readBE16(const uint8_t *buffer) {
    return (buffer[0] << 8) | buffer[1];
}

static inline int max(int a, int b) {
    return a > b ? a : b;
}

static inline int min(int a, int b) {
    return a < b ? a : b;
}

static inline int intDivCeil(int a, int b) {
    return (a + b - 1) / b;
}

static void ok_jpg_error(ok_jpg *jpg, ok_jpg_error_type error, const char *message) {
    // Empty implementation
}

static bool ok_read(ok_jpg_decoder *decoder, uint8_t *buffer, size_t length) {
    // Empty implementation
    return false;
}

static bool ok_seek(ok_jpg_decoder *decoder, int length) {
    // Empty implementation
    return false;
}

static void ok_jpg_idct_8x8(void) {}
static void ok_jpg_idct_16x16(void) {}
static void ok_jpg_idct_8x16(void) {}
static void ok_jpg_idct_16x8(void) {}