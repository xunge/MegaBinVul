#include <sched.h>
#include <stddef.h>

typedef struct hwloc_topology *hwloc_topology_t;
typedef struct hwloc_bitmap_s *hwloc_bitmap_t;

struct hwloc_obj {
    hwloc_bitmap_t complete_cpuset;
};

struct hwloc_topology {
    struct hwloc_obj ***levels;
};

extern hwloc_bitmap_t hwloc__alloc_read_path_as_cpulist(const char *path, int root_fd);
extern int hwloc_bitmap_last(hwloc_bitmap_t bitmap);
extern void hwloc_bitmap_free(hwloc_bitmap_t bitmap);
extern void hwloc_debug_bitmap(const char *fmt, hwloc_bitmap_t bitmap);