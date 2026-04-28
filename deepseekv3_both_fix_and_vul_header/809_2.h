#include <stddef.h>
#include <stdint.h>
#include <limits.h>

#define RETRY_UNLIMITED 0
#define XEN_EXTRA_MEM_MAX_REGIONS 8
#define ENODEV 19
#define __init

struct balloon_stats {
    unsigned long current_pages;
    unsigned long target_pages;
    unsigned long balloon_low;
    unsigned long balloon_high;
    unsigned long total_pages;
    unsigned int schedule_delay;
    unsigned int max_schedule_delay;
    unsigned int retry_count;
    unsigned int max_retry_count;
};

struct xen_extra_mem_region {
    unsigned long start_pfn;
    unsigned long n_pfns;
};

extern struct balloon_stats balloon_stats;
extern struct xen_extra_mem_region xen_extra_mem[XEN_EXTRA_MEM_MAX_REGIONS];
extern int xen_domain(void);
extern int xen_pv_domain(void);
extern unsigned long min(unsigned long a, unsigned long b);
extern unsigned long get_num_physpages(void);
extern void balloon_add_region(unsigned long start_pfn, unsigned long n_pfns);
extern void xen_balloon_init(void);
extern void set_online_page_callback(void (*callback)(void *));
extern void register_memory_notifier(void *nb);
extern void register_sysctl_table(void *table);
extern void pr_info(const char *fmt, ...);