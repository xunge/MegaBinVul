#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define MAX_BUSID 256

typedef int spinlock_t;
#define spin_lock(lock) (void)0
#define spin_unlock(lock) (void)0

struct device_driver;
struct busid_entry {
    char name[32];
    spinlock_t busid_lock;
};

static spinlock_t busid_table_lock;
static struct busid_entry busid_table[MAX_BUSID];