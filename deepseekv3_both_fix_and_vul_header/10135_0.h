#include <stdio.h>
#include <assert.h>

#define RAS_MT_NONE 0
#define RAS_MT_EQUALRGB 1
#define RAS_CMAP_MAXSIZ 256
#define RAS_RED(c) ((c) << 16)
#define RAS_GREEN(c) ((c) << 8)
#define RAS_BLUE(c) (c)

typedef struct {
    int maptype;
    int depth;
    int maplength;
} ras_hdr_t;

typedef struct {
    unsigned int data[RAS_CMAP_MAXSIZ];
} ras_cmap_t;

typedef struct {
    int (*getc)(void *);
    void *data;
} jas_stream_t;