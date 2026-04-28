#include <stddef.h>

#define MEMSLOT_GENERATION_BITS 0
#define MEMSLOT_SLOT_BITS 0
#define NUM_MEMSLOTS 0
#define NUM_MEMSLOTS_GROUPS 0

typedef struct QXLInstance QXLInstance;
typedef struct QXLDevInitInfo QXLDevInitInfo;
typedef struct SimpleSpiceDisplay SimpleSpiceDisplay;

struct QXLDevInitInfo {
    int memslot_gen_bits;
    int memslot_id_bits;
    int num_memslots;
    int num_memslots_groups;
    int internal_groupslot_id;
    size_t qxl_ram_size;
    int n_surfaces;
};

struct SimpleSpiceDisplay {
    QXLInstance *qxl;
    size_t bufsize;
    int num_surfaces;
};

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); \
})