#include <string.h>
#include <stdatomic.h>

#define MAX_BUSID 256

struct bus_id {
    int status;
    atomic_flag busid_lock;
};

static struct bus_id busid_table[MAX_BUSID];
static atomic_flag busid_table_lock;

#define STUB_BUSID_OTHER 0