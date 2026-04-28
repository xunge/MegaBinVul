#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define NETVSC_GLOBAL_STATS_LEN 1
#define NETVSC_VF_STATS_LEN 1
#define GFP_KERNEL 0

typedef uint64_t u64;

struct net_device;
struct ethtool_stats;

struct u64_stats_sync {
    unsigned int sequence;
};

struct netvsc_stats {
    struct u64_stats_sync syncp;
    u64 packets;
    u64 bytes;
    u64 xdp_drop;
};

struct net_device_context {
    void *nvdev;
    u64 eth_stats;
};

struct netvsc_device {
    int num_chn;
    struct {
        struct netvsc_stats tx_stats;
        struct netvsc_stats rx_stats;
    } chan_table[1];
};

struct netvsc_vf_pcpu_stats {
    u64 dummy;
};

struct netvsc_ethtool_pcpu_stats {
    u64 dummy;
};

static inline unsigned int u64_stats_fetch_begin_irq(const struct u64_stats_sync *syncp) {
    return 0;
}

static inline bool u64_stats_fetch_retry_irq(const struct u64_stats_sync *syncp, unsigned int start) {
    return false;
}

static inline void *kvmalloc_array(size_t n, size_t size, int flags) {
    return NULL;
}

static inline void kvfree(const void *addr) {}

#define num_possible_cpus() 1
#define for_each_present_cpu(cpu) for (cpu = 0; cpu < 1; cpu++)
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

static inline struct net_device_context *netdev_priv(struct net_device *dev) {
    return NULL;
}

static inline struct netvsc_device *rtnl_dereference(void *ptr) {
    return NULL;
}

static void netvsc_get_vf_stats(struct net_device *dev, struct netvsc_vf_pcpu_stats *sum) {}
static void netvsc_get_pcpu_stats(struct net_device *dev, struct netvsc_ethtool_pcpu_stats *sum) {}

const struct {
    unsigned int offset;
} netvsc_stats[NETVSC_GLOBAL_STATS_LEN], vf_stats[NETVSC_VF_STATS_LEN], pcpu_stats[1];