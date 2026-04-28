#include <stddef.h>

#define __ref
#define MEM_GOING_ONLINE 0
#define MEM_CANCEL_ONLINE 1
#define MEM_ONLINE 2
#define N_HIGH_MEMORY 0
#define PAGE_SHIFT 12
#define KERN_DEBUG ""

struct zone {
    unsigned long present_pages;
    struct pglist_data *zone_pgdat;
};

struct pglist_data {
    unsigned long node_present_pages;
};

struct memory_notify {
    unsigned long start_pfn;
    unsigned long nr_pages;
    int status_change_nid;
};

extern struct mutex zonelists_mutex;
extern int memory_notify(int val, void *v);
extern int notifier_to_errno(int err);
extern void lock_memory_hotplug(void);
extern void unlock_memory_hotplug(void);
extern int walk_system_ram_range(unsigned long start_pfn, unsigned long nr_pages, void *arg, int (*func)(unsigned long, unsigned long, void *));
extern int online_pages_range(unsigned long start_pfn, unsigned long nr_pages, void *arg);
extern void build_all_zonelists(void *zonelist, struct zone *zone);
extern void zone_pcp_update(struct zone *zone);
extern void init_per_zone_wmark_min(void);
extern void kswapd_run(int nid);
extern void node_set_state(int nid, int state);
extern unsigned long nr_free_pagecache_pages(void);
extern void writeback_set_ratelimit(void);
extern int page_to_nid(void *page);
extern void *pfn_to_page(unsigned long pfn);
extern struct zone *page_zone(void *page);
extern unsigned long node_present_pages(int nid);
extern int populated_zone(struct zone *zone);
extern int zone_to_nid(struct zone *zone);

unsigned long vm_total_pages;