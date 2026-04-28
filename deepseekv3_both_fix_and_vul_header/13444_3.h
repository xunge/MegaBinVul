#include <stdlib.h>
#include <errno.h>

struct net;
typedef void *sockptr_t;

struct xt_counters {
    unsigned long long bcnt;
    unsigned long long pcnt;
};

struct xt_counters_info {
    char name[32];
    unsigned int num_counters;
    struct xt_counters counters[];
};

struct xt_table_info {
    unsigned int number;
    void *entries;
    unsigned int size;
};

struct xt_table {
    struct xt_table_info *private;
    void *me;
};

struct arpt_entry {
    struct xt_counters counters;
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))
#define EINVAL 22
#define NFPROTO_ARP 3

#define local_bh_disable()
#define local_bh_enable()
#define module_put(x)
#define ADD_COUNTER(c, b, p) do { (c).bcnt += (b); (c).pcnt += (p); } while (0)

static void *xt_copy_counters(sockptr_t arg, unsigned int len, struct xt_counters_info *tmp) { return NULL; }
static void *xt_find_table_lock(struct net *net, int family, const char *name) { return NULL; }
static unsigned int xt_write_recseq_begin(void) { return 0; }
static void xt_write_recseq_end(unsigned int addend) {}
static void xt_table_unlock(struct xt_table *t) {}
#define xt_entry_foreach(iter, entries, size) for (iter = NULL; iter != (void*)((char*)entries + size); iter = (void*)((char*)iter + 1))
static struct xt_counters *xt_get_this_cpu_counter(struct xt_counters *counters) { return counters; }