#include <stdlib.h>
#include <stdio.h>

struct rw {
    char *name;
};

struct slice {
    void *ptr;
    size_t len;
};

struct command {
    struct slice slice;
    size_t offset;
};

typedef struct {
    int (*callback)(void *, int *);
    void *user_data;
} nbd_completion_callback;

void *slice_ptr(struct slice s);
void file_synch_write(struct rw *rw, void *ptr, size_t len, size_t offset);