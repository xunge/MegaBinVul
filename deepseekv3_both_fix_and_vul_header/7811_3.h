#include <stddef.h>
#include <stdint.h>

typedef struct RAMBlock RAMBlock;
typedef struct uc_struct uc_struct;
typedef struct MemoryRegion MemoryRegion;
typedef struct RAMList RAMList;

enum {
    UC_ERR_NOMEM,
    DIRTY_CLIENTS_ALL
};

struct MemoryRegion {
    size_t align;
};

struct RAMBlock {
    uintptr_t offset;
    size_t max_length;
    size_t used_length;
    void *host;
    MemoryRegion *mr;
    struct {
        RAMBlock *le_next;
        RAMBlock **le_prev;
    } next;
};

struct RAMList {
    struct {
        RAMBlock *lh_first;
    } blocks;
    RAMBlock *mru_block;
};

struct uc_struct {
    RAMList ram_list;
    int invalid_error;
};

#define QLIST_INSERT_BEFORE_RCU(listelm, elm, field) do { \
    (elm)->field.le_prev = (listelm)->field.le_prev;      \
    (elm)->field.le_next = (listelm);                     \
    *(listelm)->field.le_prev = (elm);                    \
    (listelm)->field.le_prev = &(elm)->field.le_next;     \
} while (0)

#define QLIST_INSERT_AFTER_RCU(listelm, elm, field) do {  \
    (elm)->field.le_next = (listelm)->field.le_next;      \
    (elm)->field.le_prev = &(listelm)->field.le_next;     \
    (listelm)->field.le_next = (elm);                     \
    if ((elm)->field.le_next != NULL) {                   \
        (elm)->field.le_next->field.le_prev =             \
            &(elm)->field.le_next;                        \
    }                                                     \
} while (0)

#define QLIST_INSERT_HEAD_RCU(head, elm, field) do {      \
    (elm)->field.le_next = (head)->lh_first;              \
    (elm)->field.le_prev = &(head)->lh_first;             \
    if ((head)->lh_first != NULL) {                       \
        (head)->lh_first->field.le_prev =                 \
            &(elm)->field.le_next;                        \
    }                                                     \
    (head)->lh_first = (elm);                             \
} while (0)

#define QLIST_INSERT_BEFORE(listelm, elm, field) do {     \
    (elm)->field.le_prev = (listelm)->field.le_prev;      \
    (elm)->field.le_next = (listelm);                     \
    *(listelm)->field.le_prev = (elm);                    \
    (listelm)->field.le_prev = &(elm)->field.le_next;     \
} while (0)

#define QLIST_INSERT_AFTER(listelm, elm, field) do {      \
    (elm)->field.le_next = (listelm)->field.le_next;      \
    (elm)->field.le_prev = &(listelm)->field.le_next;     \
    (listelm)->field.le_next = (elm);                     \
    if ((elm)->field.le_next != NULL) {                   \
        (elm)->field.le_next->field.le_prev =             \
            &(elm)->field.le_next;                        \
    }                                                     \
} while (0)

#define QLIST_INSERT_HEAD(head, elm, field) do {          \
    (elm)->field.le_next = (head)->lh_first;              \
    (elm)->field.le_prev = &(head)->lh_first;             \
    if ((head)->lh_first != NULL) {                       \
        (head)->lh_first->field.le_prev =                 \
            &(elm)->field.le_next;                        \
    }                                                     \
    (head)->lh_first = (elm);                             \
} while (0)

#define RAMBLOCK_FOREACH(block) \
    for (block = uc->ram_list.blocks.lh_first; block; block = block->next.le_next)

void *phys_mem_alloc(uc_struct *uc, size_t size, size_t *align);
uintptr_t find_ram_offset(uc_struct *uc, size_t size);
void cpu_physical_memory_set_dirty_range(uintptr_t start, size_t length, int clients);