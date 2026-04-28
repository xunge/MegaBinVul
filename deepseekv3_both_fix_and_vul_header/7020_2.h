#include <stddef.h>

typedef struct ogg_sync_state {
    unsigned char *data;
    int storage;
    int fill;
    int returned;
} ogg_sync_state;

typedef struct OggOpusFile OggOpusFile;
typedef struct {
    size_t (*read)(void *, unsigned char *, int);
} OpusFileCallbacks;

struct OggOpusFile {
    ogg_sync_state oy;
    OpusFileCallbacks callbacks;
    void *stream;
};

#define OP_EFAULT (-1)
#define OP_LIKELY(x) (x)
#define OP_UNLIKELY(x) (x)
#define OP_ASSERT(x) ((void)0)

static void *ogg_sync_buffer(ogg_sync_state *oy, int size) {
    return oy->data;
}

static void ogg_sync_wrote(ogg_sync_state *oy, int bytes) {
    oy->fill += bytes;
}