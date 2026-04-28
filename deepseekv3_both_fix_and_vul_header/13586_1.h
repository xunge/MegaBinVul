#include <stdint.h>
#include <stdio.h>

typedef struct pcm_io_vtbl pcm_io_vtbl_t;
typedef struct pcm_io_context pcm_io_context_t;

struct pcm_io_vtbl {
    int (*read)(void *, char *, int64_t);
};

struct pcm_io_context {
    pcm_io_vtbl_t *vtbl;
    void *cookie;
};

extern int pcm_seek(pcm_io_context_t *io, int64_t count, int whence);