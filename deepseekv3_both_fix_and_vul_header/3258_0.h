#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVCodecContext {
    int width;
    int height;
    void (*log)(void*, int, const char*, ...);
    void *priv_data;
} AVCodecContext;

typedef struct PGSSubPicture {
    uint8_t *rle;
    unsigned int rle_buffer_size;
    unsigned int rle_data_len;
    unsigned int rle_remaining_len;
    uint16_t w;
    uint16_t h;
} PGSSubPicture;

typedef struct PGSSubContext {
    PGSSubPicture *pictures;
} PGSSubContext;

#define AV_LOG_ERROR 0
#define AVERROR_INVALIDDATA (-1)

static inline uint16_t bytestream_get_be16(const uint8_t **b) {
    uint16_t v = (*b)[0] << 8 | (*b)[1];
    *b += 2;
    return v;
}

static inline uint32_t bytestream_get_be24(const uint8_t **b) {
    uint32_t v = (*b)[0] << 16 | (*b)[1] << 8 | (*b)[2];
    *b += 3;
    return v;
}

static inline uint8_t bytestream_get_byte(const uint8_t **b) {
    return *(*b)++;
}

static inline void av_fast_malloc(void *ptr, unsigned int *size, size_t min_size) {
    if (min_size > *size) {
        free(*(void**)ptr);
        *(void**)ptr = malloc(min_size);
        *size = min_size;
    }
}