#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef uint64_t ut64;
typedef uint8_t ut8;

struct r_bin_dyldcache_obj_t {
    void *b;
    ut64 size;
};

#define R_NEW0(x) calloc(1, sizeof(x))

void* r_buf_new();
bool r_buf_set_bytes(void *b, const ut8* buf, ut64 size);
struct r_bin_dyldcache_obj_t* r_bin_dyldcache_free(struct r_bin_dyldcache_obj_t *bin);
bool r_bin_dyldcache_init(struct r_bin_dyldcache_obj_t *bin);