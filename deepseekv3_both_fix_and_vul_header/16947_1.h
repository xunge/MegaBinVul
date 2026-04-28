#include <pthread.h>
#include <sched.h>
#include <errno.h>

typedef struct hwloc_topology {
    int pid;
} *hwloc_topology_t;

typedef const struct hwloc_bitmap_s *hwloc_const_bitmap_t;
struct hwloc_bitmap_s;
#define __hwloc_attribute_unused

extern int hwloc_linux_set_tid_cpubind(hwloc_topology_t topology, int tid, hwloc_const_bitmap_t hwloc_set);
extern int hwloc_bitmap_last(hwloc_const_bitmap_t set);
extern void hwloc_bitmap_foreach_begin(unsigned cpu, hwloc_const_bitmap_t set);
extern void hwloc_bitmap_foreach_end(void);
extern unsigned long hwloc_bitmap_to_ulong(hwloc_const_bitmap_t set);

extern int (*pthread_setaffinity_np)(pthread_t, size_t, const void *);