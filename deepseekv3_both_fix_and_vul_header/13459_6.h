#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

#define AF_INET6 10
#define EINVAL 22
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

struct net;
struct sock;
typedef struct sock *sockptr_t;

struct xt_counters {
    uint64_t bcnt;
    uint64_t pcnt;
};

struct xt_counters_info {
    char name[32];
    unsigned int num_counters;
    struct xt_counters *counters;
};

struct xt_table {
    void *private;
    void *me;
};

struct xt_table_info {
    unsigned int number;
    void *entries;
    unsigned int size;
};

struct ip6t_entry {
    struct xt_counters counters;
};

#define ADD_COUNTER(counter, bcnt_val, pcnt_val) do { \
    (counter).bcnt += (bcnt_val); \
    (counter).pcnt += (pcnt_val); \
} while (0)

#define xt_entry_foreach(iter, entries, size) \
    for ((iter) = (struct ip6t_entry *)(entries); \
         (char *)(iter) < (char *)(entries) + (size); \
         (iter) = (struct ip6t_entry *)((char *)(iter) + sizeof(struct ip6t_entry)))

static void *xt_copy_counters(sockptr_t arg, unsigned int len, struct xt_counters_info *tmp) { return tmp->counters; }
static void *xt_find_table_lock(struct net *net, int af, const char *name) { return NULL; }
static void local_bh_disable(void) {}
static void local_bh_enable(void) {}
static unsigned int xt_write_recseq_begin(void) { return 0; }
static void xt_write_recseq_end(unsigned int addend) {}
static void xt_table_unlock(struct xt_table *t) {}
static void module_put(void *me) {}
static struct xt_counters *xt_get_this_cpu_counter(struct xt_counters *counters) { return counters; }
#define vfree(x) free(x)