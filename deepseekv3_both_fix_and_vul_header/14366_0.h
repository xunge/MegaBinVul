#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <stdio.h>

#define GFP_KERNEL 0
#define IP_IDENTS_SZ 256
#define SLAB_HWCACHE_ALIGN 0
#define SLAB_PANIC 0
#define CONFIG_IP_ROUTE_CLASSID 0
#define CONFIG_XFRM 0
#define CONFIG_SYSCTL 0
#define PF_INET 0
#define RTM_GETROUTE 0
#define RTNL_FLAG_DOIT_UNLOCKED 0
#define HASH_ZERO 0

typedef int ktime_t;
typedef int spinlock_t;

struct list_head {
    struct list_head *next, *prev;
};

struct uncached_list {
    struct list_head head;
    spinlock_t lock;
};

struct ip_rt_acct {
    int dummy;
};

struct dst_ops {
    void *kmem_cachep;
    int gc_thresh;
};

struct rtable {
    int dummy;
};

struct sysctl_route_ops {
    int dummy;
};

struct rt_genid_ops {
    int dummy;
};

struct ipv4_inetpeer_ops {
    int dummy;
};

int *ip_idents;
ktime_t *ip_tstamps;
struct dst_ops ipv4_dst_ops;
struct dst_ops ipv4_dst_blackhole_ops;
int ip_rt_max_size;
struct ip_rt_acct *ip_rt_acct;
struct uncached_list rt_uncached_list;
int ip_idents_mask;
struct sysctl_route_ops sysctl_route_ops;
struct rt_genid_ops rt_genid_ops;
struct ipv4_inetpeer_ops ipv4_inetpeer_ops;

#define for_each_possible_cpu(cpu) for (cpu = 0; cpu < 1; cpu++)
#define INIT_LIST_HEAD(ptr) do { (ptr)->next = (ptr); (ptr)->prev = (ptr); } while (0)
#define spin_lock_init(lock) do { } while (0)
#define panic(msg) exit(1)
#define prandom_bytes(buf, len) srand(time(NULL))
#define pr_err(msg) fprintf(stderr, "%s", msg)
#define per_cpu(var, cpu) (var)
#define __alloc_percpu(size, align) calloc(1, size)
#define kmalloc_array(n, size, flags) calloc(n, size)
#define kcalloc(n, size, flags) calloc(n, size)
#define kmem_cache_create(name, size, align, flags, ctor) malloc(1)
#define dst_entries_init(ops) 0
#define devinet_init() do { } while (0)
#define ip_fib_init() do { } while (0)
#define ip_rt_proc_init() 0
#define xfrm_init() do { } while (0)
#define xfrm4_init() do { } while (0)
#define rtnl_register(family, type, func, data, flags) 0
#define register_pernet_subsys(ops) 0
#define alloc_large_system_hash(name, size, flags, align, extra, nodes, mask, min, max) calloc(1, size)

#define __init

int inet_rtm_getroute(void);