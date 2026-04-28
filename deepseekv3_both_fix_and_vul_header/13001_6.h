#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define __init
#define GFP_KERNEL 0
#define WARN_ON(cond) do { if (cond) fprintf(stderr, "Warning\n"); } while(0)
#define IS_ERR(ptr) (ptr == NULL)
#define MEMTIER_ADISTANCE_DRAM 0
#define MEMTIER_HOTPLUG_PRI 0
#define CONFIG_MIGRATION
#define nr_node_ids 1
#define N_MEMORY 0
#define for_each_node_state(node, state) for(node=0; node<1; node++)

struct memory_tier {
    int dummy;
};
struct demotion_nodes {
    int dummy;
};
struct memory_tier_subsys {
    int dummy;
};

static pthread_mutex_t memory_tier_lock = PTHREAD_MUTEX_INITIALIZER;
static struct memory_tier *default_dram_type;
static struct demotion_nodes *node_demotion;
static struct memory_tier_subsys memory_tier_subsys;

void panic(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(1);
}
int subsys_virtual_register(struct memory_tier_subsys *subsys, void *arg) {
    return 0;
}
struct memory_tier *alloc_memory_type(int type) {
    return malloc(sizeof(struct memory_tier));
}
struct memory_tier *set_node_memory_tier(int node) {
    return malloc(sizeof(struct memory_tier));
}
void establish_demotion_targets(void) {}
void hotplug_memory_notifier(void (*callback)(void), int pri) {}
void memtier_hotplug_callback(void) {}

#define mutex_lock(lock) pthread_mutex_lock(lock)
#define mutex_unlock(lock) pthread_mutex_unlock(lock)
#define kcalloc(n, size, flags) calloc(n, size)