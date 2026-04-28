#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

struct rw {
    char *name;
};

struct command {
    struct slice {
        void *ptr;
        size_t len;
    } slice;
    size_t offset;
};

typedef struct nbd_completion_callback {
    int (*callback)(void *, int *);
    void *user_data;
} nbd_completion_callback;

void *slice_ptr(struct slice slice);
void file_synch_read(struct rw *rw, void *buf, size_t len, size_t offset);