#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

typedef bool BOOL;
#define FALSE false
#define TRUE true

typedef struct rdpNego rdpNego;
struct rdpNego {
    uint32_t RequestedProtocols;
    int state;
};

#define NEGO_STATE_FINAL 0
#define TAG "nego"

typedef uint8_t BYTE;
typedef uint16_t UINT16;
typedef uint32_t UINT32;

typedef struct wStream wStream;
struct wStream {
    size_t position;
    size_t length;
    uint8_t* buffer;
};

static inline size_t Stream_GetRemainingLength(wStream* s) {
    return s->length - s->position;
}

static inline void Stream_Read_UINT8(wStream* s, BYTE* val) {
    *val = s->buffer[s->position++];
}

static inline void Stream_Read_UINT16(wStream* s, UINT16* val) {
    *val = (s->buffer[s->position] << 8) | s->buffer[s->position + 1];
    s->position += 2;
}

static inline void Stream_Read_UINT32(wStream* s, uint32_t* val) {
    *val = (s->buffer[s->position] << 24) | (s->buffer[s->position + 1] << 16) |
           (s->buffer[s->position + 2] << 8) | s->buffer[s->position + 3];
    s->position += 4;
}

#define WLog_DBG(tag, fmt, ...) printf(fmt "\n", ##__VA_ARGS__)