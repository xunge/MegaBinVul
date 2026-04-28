#include <stddef.h>
#include <stdint.h>

typedef struct hb_set_t hb_set_t;
typedef struct hb_object_t hb_object_t;

#define unlikely(x) (x)

struct hb_object_t {
    int immutable;
};

struct hb_set_t {
    hb_object_t header;
    void (*invert)(void);
};

static inline int hb_object_is_immutable(const hb_set_t *set) {
    return set->header.immutable;
}