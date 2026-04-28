#include <stdlib.h>
#include <string.h>

typedef int Status;
typedef unsigned short CARD16;

typedef struct _Client {
    int swapped;
    unsigned int req_len;
    void *requestBuffer;
} ClientRec, *ClientPtr;

#define BadValue 1
#define BadAlloc 2
#define Success 0

static inline void swaps(CARD16 *val) {
    *val = ((*val << 8) & 0xff00) | ((*val >> 8) & 0x00ff);
}

#define XkbPaddedSize(len) (((len) + 3) & ~3)
#define bytes_to_int32(bytes) ((bytes + 3) / 4)