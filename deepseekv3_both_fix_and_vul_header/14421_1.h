#include <stddef.h>
#include <stdint.h>

typedef struct hb_set_t hb_set_t;

#define unlikely(x) (x)

struct hb_set_t {
    void (*set)(const hb_set_t other);
};

int hb_object_is_immutable(const hb_set_t *set);