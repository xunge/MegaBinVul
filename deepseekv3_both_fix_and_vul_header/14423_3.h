#include <stddef.h>

typedef struct hb_set_t {
    void (*union_)(const struct hb_set_t);
} hb_set_t;

typedef struct hb_object_t hb_object_t;

#define unlikely(x) (x)

int hb_object_is_immutable(const hb_set_t *set);