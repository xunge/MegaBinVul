#include <stddef.h>

typedef struct hb_set_t hb_set_t;
struct hb_set_t {
    void (*clear)(void);
};

#define unlikely(x) (x)
int hb_object_is_immutable(const hb_set_t *set);