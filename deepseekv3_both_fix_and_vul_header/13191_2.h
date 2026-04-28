#include <stdint.h>
#include <stdbool.h>

typedef struct stream_state stream_state;
typedef unsigned char byte;
typedef unsigned int uint;

typedef struct stream_cursor_read {
    const byte *ptr;
    const byte *limit;
} stream_cursor_read;

typedef struct stream_cursor_write {
    byte *ptr;
    byte *limit;
} stream_cursor_write;

#define CtrlA 0x01

static inline uint min(uint a, uint b) {
    return (a < b) ? a : b;
}