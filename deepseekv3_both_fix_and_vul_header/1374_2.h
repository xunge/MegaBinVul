#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

struct rw {
    const char *name;
};

struct slice {
    size_t len;
};

struct command {
    size_t offset;
    struct slice slice;
};

typedef struct {
    int (*callback)(void *, int *);
    void *user_data;
} nbd_completion_callback;

bool file_synch_zero(struct rw *rw, size_t offset, size_t len, bool allocate);