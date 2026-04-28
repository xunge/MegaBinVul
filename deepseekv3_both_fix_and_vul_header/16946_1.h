#include <pthread.h>
#include <sched.h>
#include <errno.h>
#include <assert.h>

typedef struct hwloc_topology {
    int pid;
    struct hwloc_obj ***levels;
} *hwloc_topology_t;

typedef struct hwloc_bitmap {
    // Implementation dependent fields
} *hwloc_bitmap_t;

typedef struct hwloc_obj {
    hwloc_bitmap_t complete_cpuset;
} hwloc_obj_t;

#define __hwloc_attribute_unused

extern int pthread_getaffinity_np(pthread_t thread, size_t cpusetsize, cpu_set_t *cpuset);
extern pthread_t pthread_self(void);
extern int hwloc_linux_get_tid_cpubind(hwloc_topology_t topology, int tid, hwloc_bitmap_t hwloc_set);
extern void hwloc_bitmap_zero(hwloc_bitmap_t set);
extern void hwloc_bitmap_set(hwloc_bitmap_t set, unsigned cpu);
extern int hwloc_bitmap_last(hwloc_bitmap_t set);
extern void hwloc_bitmap_from_ulong(hwloc_bitmap_t set, unsigned long mask);