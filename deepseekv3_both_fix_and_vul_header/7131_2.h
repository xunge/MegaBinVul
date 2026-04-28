#include <stdint.h>

typedef struct GF_Box GF_Box;
typedef struct GF_List GF_List;

struct GF_Box {
    GF_List *child_boxes;
    uint32_t internal_flags;
};

#define GF_ISOM_ORDER_FREEZE (1 << 0)

typedef uint32_t u32;
typedef int32_t s32;

int32_t gf_list_find(GF_List *list, GF_Box *item);
void gf_list_del_item(GF_List *list, GF_Box *item);
void gf_list_insert(GF_List *list, GF_Box *item, uint32_t position);