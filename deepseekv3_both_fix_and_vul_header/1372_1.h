#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <inttypes.h>

struct slice {
    size_t len;
};

struct command {
    uint64_t offset;
    struct slice slice;
};

typedef struct nbd_completion_callback {
    void (*callback)(void *, int *);
    void *user_data;
} nbd_completion_callback;

struct dst_ops {
    void (*asynch_write)(void *, struct command *, nbd_completion_callback);
};

struct dst {
    struct dst_ops *ops;
};

extern bool allocated;
extern uint64_t sparse_size;
extern struct dst *dst;

void free_command(void *, int *);
void fill_dst_range_with_zeroes(struct command *);
struct command *copy_subcommand(struct command *, uint64_t, uint64_t, bool);
bool is_zero(const void *, size_t);
const void *slice_ptr(struct slice);

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ROUND_UP(a, b) (((a) + (b) - 1) / (b) * (b))