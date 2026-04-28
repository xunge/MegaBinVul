#include <stdlib.h>
#include <stdint.h>

typedef uint32_t u32;

struct tipc_net {
    void **zones;
};

extern struct tipc_net tipc_net;
extern u32 tipc_max_zones;

void tipc_zone_delete(void *zone);
void kfree(void *ptr);