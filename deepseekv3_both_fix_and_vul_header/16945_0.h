#include <sched.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>

typedef struct hwloc_topology* hwloc_topology_t;
typedef const struct hwloc_bitmap_s* hwloc_const_bitmap_t;
#define __hwloc_attribute_unused

struct hwloc_bitmap_s;
int hwloc_bitmap_last(hwloc_const_bitmap_t set);
#define hwloc_bitmap_foreach_begin(id, bitmap)
#define hwloc_bitmap_foreach_end()
unsigned long hwloc_bitmap_to_ulong(hwloc_const_bitmap_t set);