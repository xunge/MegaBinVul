#include <stdint.h>

typedef uint32_t freelist_idx_t;

union freelist_init_state {
    struct {
        freelist_idx_t *list;
        freelist_idx_t pos;
        freelist_idx_t rand;
        freelist_idx_t count;
    };
};