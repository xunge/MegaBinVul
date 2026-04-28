#include <string.h>
#include <stdint.h>

typedef uint32_t guint;
typedef uint8_t guchar;

typedef struct {
    uint8_t *pptr;
    struct {
        size_t n_channels;
    } *pbuf;
    size_t pbuf_bytes_done;
    size_t pbuf_bytes;
} TGAContext;

typedef struct TGAColor TGAColor;

#define g_memmove memmove