#include <stddef.h>

typedef struct RAMBlock RAMBlock;
typedef struct RAMList RAMList;
typedef struct uc_struct uc_struct;

struct RAMBlock {
    RAMBlock *next;
    RAMBlock *prev;
    void *host;
    size_t max_length;
};

struct RAMList {
    RAMBlock *mru_block;
};

struct uc_struct {
    RAMList ram_list;
};

#define QLIST_SAFE_REMOVE(block, field) do { \
    if ((block)->next) { \
        (block)->next->prev = (block)->prev; \
    } \
    if ((block)->prev) { \
        (block)->prev->next = (block)->next; \
    } \
    (block)->next = (block)->prev = NULL; \
} while (0)

#define QLIST_REMOVE(block, field) do { \
    if ((block)->next) { \
        (block)->next->prev = (block)->prev; \
    } \
    if ((block)->prev) { \
        (block)->prev->next = (block)->next; \
    } \
} while (0)

void reclaim_ramblock(uc_struct *uc, RAMBlock *block);