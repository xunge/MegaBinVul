#include <stddef.h>

typedef struct hb_set_t hb_set_t;

struct hb_set_t {
    void (*symmetric_difference)(const hb_set_t other);
};

#define unlikely(x) (x)

static inline int hb_object_is_immutable(const hb_set_t *set) {
    return 0;
}