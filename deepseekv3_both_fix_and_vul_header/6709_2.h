#include <stdint.h>
#include <limits.h>

typedef struct {
    uint32_t window;
    uint8_t swapAction;
    uint8_t pad[3];
} xDbeSwapInfo;

typedef struct {
    uint8_t reqType;
    uint8_t dbeReqType;
    uint16_t length;
    uint32_t n;
} xDbeSwapBuffersReq;

typedef struct {
    unsigned char *requestBuffer;
    unsigned int req_len;
} ClientRec;

typedef ClientRec *ClientPtr;

#define REQUEST(x) x *stuff = (x *)client->requestBuffer
#define REQUEST_AT_LEAST_SIZE(x) \
    if (client->req_len < sizeof(x)) return BadLength
#define REQUEST_FIXED_SIZE(x, y) \
    if (client->req_len < (sizeof(x) + (y))) return BadLength

static inline uint16_t swaps(uint16_t x) {
    return (x << 8) | (x >> 8);
}

static inline uint32_t swapl(uint32_t x) {
    return (x << 24) | ((x << 8) & 0x00FF0000) | 
           ((x >> 8) & 0x0000FF00) | (x >> 24);
}

#define _X_COLD
#define BadLength 1
#define BadAlloc 2
typedef int DbeSwapInfoRec;