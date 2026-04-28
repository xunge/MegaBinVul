#include <string.h>

#define MAX_BUSID 256
#define BUSID_SIZE 32

enum {
    STUB_BUSID_ALLOC,
    STUB_BUSID_REMOV,
    STUB_BUSID_ADDED
};

struct busid_table_entry {
    char name[BUSID_SIZE];
    int status;
    int busid_lock;
};

extern int busid_table_lock;
extern struct busid_table_entry busid_table[MAX_BUSID];

extern int get_busid_idx(char *busid);
extern void spin_lock(int *lock);
extern void spin_unlock(int *lock);