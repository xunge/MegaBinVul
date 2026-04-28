#include <stddef.h>
#include <errno.h>

#define NR_CPUS 1
#define per_cpu(var, cpu) (var)

struct xen_flask_cache_stats {
    unsigned int cpu;
    unsigned int lookups;
    unsigned int hits;
    unsigned int misses;
    unsigned int allocations;
    unsigned int reclaims;
    unsigned int frees;
};

struct avc_cache_stats {
    unsigned int lookups;
    unsigned int hits;
    unsigned int misses;
    unsigned int allocations;
    unsigned int reclaims;
    unsigned int frees;
};

extern unsigned int nr_cpu_ids;
extern int cpu_online(unsigned int cpu);
struct avc_cache_stats avc_cache_stats;