#include <stdbool.h>

struct static_key {
    bool enabled;
};

extern struct static_key sched_feat_keys[];

static inline void static_key_disable(struct static_key *key) {
    key->enabled = false;
}