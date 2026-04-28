#include <stdlib.h>
#include <stdint.h>

#define MAX_BEARERS 32

typedef uint32_t u32;

struct tipc_bearer {
    int active;
    struct {
        char *name;
        int blocked;
    } publ;
};

static struct tipc_bearer *tipc_bearers;
static void *media_list;
static int media_count;

void bearer_disable(char *name);
void kfree(void *ptr);