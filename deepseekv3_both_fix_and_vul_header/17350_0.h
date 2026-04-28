#include <string.h>

#define MAX_BUSID 256
#define BUSID_SIZE 32

struct busid_entry {
    char name[BUSID_SIZE];
    void *busid_lock;
};

extern struct busid_entry busid_table[MAX_BUSID];

static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}