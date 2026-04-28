#include <stdlib.h>
#include <string.h>

typedef struct caf_reader_t {
    struct {
        int (*read)(void *, char *, int64_t);
    } io;
    void *tag_ctx;
    void (*tag_callback)(void *, char *, char *, size_t);
} caf_reader_t;

static int pcm_read(void *io, char *buf, int64_t size);