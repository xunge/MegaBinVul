#include <stddef.h>

struct hb_set_t {
    void intersect(const hb_set_t& other);
};

#define unlikely(x) (x)

int hb_object_is_immutable(const hb_set_t *set);