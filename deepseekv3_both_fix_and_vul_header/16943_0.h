#include <sched.h>
#include <unistd.h>
#include <errno.h>

typedef struct hwloc_topology *hwloc_topology_t;
typedef struct hwloc_bitmap *hwloc_bitmap_t;
typedef int pid_t;

#define __hwloc_attribute_unused
#define HWLOC_HAVE_CPU_SET_S
#define HWLOC_HAVE_CPU_SET
#define HWLOC_HAVE_SYSCALL

struct hwloc_topology {
    struct hwloc_obj ***levels;
};

struct hwloc_obj {
    struct hwloc_bitmap *complete_cpuset;
};

int hwloc_linux_find_kernel_nr_cpus(hwloc_topology_t topology);
int hwloc_bitmap_last(struct hwloc_bitmap *set);
void hwloc_bitmap_zero(struct hwloc_bitmap *set);
void hwloc_bitmap_set(struct hwloc_bitmap *set, unsigned cpu);
void hwloc_bitmap_from_ulong(struct hwloc_bitmap *set, unsigned long mask);