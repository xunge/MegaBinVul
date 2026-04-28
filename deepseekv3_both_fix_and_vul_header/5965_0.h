#include <stdint.h>
#include <stddef.h>

typedef enum {
    AVIF_FALSE,
    AVIF_TRUE
} avifBool;

typedef struct {
    uint8_t rows;
    uint8_t columns;
    uint32_t outputWidth;
    uint32_t outputHeight;
} avifImageGrid;

#define AVIF_MAX_IMAGE_SIZE (16384 * 16384)

typedef struct {
    const uint8_t * data;
    size_t offset;
    size_t size;
} avifROStream;

#define BEGIN_STREAM(s, raw, rawLen) avifROStream s = { raw, 0, rawLen }

static avifBool avifROStreamRead(avifROStream * s, uint8_t * out, size_t size);
static avifBool avifROStreamReadU16(avifROStream * s, uint16_t * out);
static avifBool avifROStreamReadU32(avifROStream * s, uint32_t * out);

#define CHECK(x) if (!(x)) { return AVIF_FALSE; }