#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct ok_png ok_png;
typedef struct ok_png_decoder ok_png_decoder;

struct ok_png {
    bool has_alpha;
};

struct ok_png_decoder {
    ok_png *png;
    unsigned int decode_flags;
    bool is_ios_format;
    bool decoding_completed;
};

#define OK_PNG_ERROR_INVALID 1
#define OK_PNG_INFO_ONLY 1
#define OK_PNG_CHUNK_CGBI 0x43474249
#define OK_PNG_CHUNK_IHDR 0x49484452
#define OK_PNG_CHUNK_PLTE 0x504C5445
#define OK_PNG_CHUNK_TRNS 0x74524E53
#define OK_PNG_CHUNK_IDAT 0x49444154
#define OK_PNG_CHUNK_IEND 0x49454E44

static uint32_t readBE32(const uint8_t *data);
static bool ok_read(ok_png_decoder *decoder, uint8_t *buffer, size_t length);
static bool ok_seek(ok_png_decoder *decoder, long length);
static void ok_png_error(ok_png *png, int error, const char *message);
static bool ok_png_read_header(ok_png_decoder *decoder, uint32_t chunk_length);
static bool ok_png_read_palette(ok_png_decoder *decoder, uint32_t chunk_length);
static bool ok_png_read_transparency(ok_png_decoder *decoder, uint32_t chunk_length);
static bool ok_png_read_data(ok_png_decoder *decoder, uint32_t chunk_length);