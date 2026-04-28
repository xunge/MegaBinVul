#include <stddef.h>
#include <stdlib.h>

struct static_key {
    int enabled;
};

struct work_struct {
    // minimal definition
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

static inline int static_key_enabled(struct static_key *key) {
    return key->enabled;
}

static inline void static_key_slow_inc(struct static_key *key) {
    key->enabled++;
}

static inline void kfree(void *p) {
    free(p);
}

struct __net_random_once_work {
    struct work_struct work;
    struct static_key *key;
};