#include <stddef.h>
#include <stdint.h>

typedef struct {
    void *kernel;
    void *user;
} sockptr_t;

struct net;

struct xt_counters {
    uint64_t bcnt;
    uint64_t pcnt;
};

struct xt_counters_info {
    char name[32];
    unsigned int num_counters;
};

struct xt_table_info {
    unsigned int number;
    void *entries;
    unsigned int size;
};

struct xt_table {
    struct xt_table_info *private;
    struct module *me;
};

struct ipt_entry {
    struct xt_counters counters;
};

struct module;

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))
#define ADD_COUNTER(c, b, p) do { (c).bcnt += (b); (c).pcnt += (p); } while (0)
#define AF_INET 2
#define EINVAL 22

static inline void local_bh_disable(void) {}
static inline void local_bh_enable(void) {}
static inline void vfree(void *ptr) {}
static inline void module_put(struct module *mod) {}

static void *xt_copy_counters(sockptr_t arg, unsigned int len, struct xt_counters_info *tmp) { return NULL; }
static struct xt_table *xt_find_table_lock(struct net *net, int af, const char *name) { return NULL; }
static void xt_table_unlock(struct xt_table *t) {}
static unsigned int xt_write_recseq_begin(void) { return 0; }
static void xt_write_recseq_end(unsigned int addend) {}
static struct xt_counters *xt_get_this_cpu_counter(struct xt_counters *counters) { return counters; }
#define xt_entry_foreach(iter, entries, size) for (iter = NULL; iter != (void*)(entries) + (size); iter = (void*)(entries) + (size))