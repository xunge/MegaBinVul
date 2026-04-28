#include <stddef.h>
#include <sys/types.h>
#include <stdint.h>

typedef uint64_t u64;
typedef long loff_t;

struct ctl_table {
    int dummy;
};

#define __user
#define KERN_WARNING ""
#define WRITE_ONCE(x, val) (x = val)

extern int sysctl_perf_cpu_time_max_percent;
extern u64 perf_sample_allowed_ns;
extern void update_perf_cpu_limits(void);
extern int proc_dointvec(struct ctl_table *table, int write, void *buffer, size_t *lenp, loff_t *ppos);