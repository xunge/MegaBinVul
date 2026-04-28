#include <stddef.h>

typedef struct hb_map_t hb_map_t;
typedef int hb_bool_t;

#define unlikely(expr) (expr)

hb_bool_t hb_object_is_immutable(const hb_map_t *map);

struct hb_map_t {
    void (*clear)(void);
};