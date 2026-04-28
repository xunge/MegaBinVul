#include <stddef.h>

typedef struct RAMBlock RAMBlock;
typedef struct RAMList RAMList;
typedef struct uc_struct uc_struct;

struct RAMBlock {
    RAMBlock *next;
    void *host;
    size_t max_length;
};

struct RAMList {
    RAMBlock *mru_block;
};

struct uc_struct {
    RAMList ram_list;
};

#define QLIST_REMOVE_RCU(block, next) 
#define QLIST_REMOVE(block, next) 

void reclaim_ramblock(uc_struct *uc, RAMBlock *block);