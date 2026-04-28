#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define EF100_STAT_COUNT 64
#define GFP_ATOMIC 0
#define DECLARE_BITMAP(name, bits) unsigned long name[(bits + 8*sizeof(long) - 1)/(8*sizeof(long))]

typedef uint64_t u64;
typedef uint64_t __le64;

struct efx_nic {
    unsigned int num_mac_stats;
    struct ef100_nic_data *nic_data;
};

struct ef100_nic_data {
    u64 *stats;
};

struct rtnl_link_stats64 {
    // Add necessary fields here
};

extern const void *ef100_stat_desc;

void *kmalloc(size_t size, int flags);
void kfree(void *ptr);
size_t array_size(size_t n, size_t size);

void ef100_common_stat_mask(unsigned long *mask);
void ef100_ethtool_stat_mask(unsigned long *mask);
void efx_nic_copy_stats(struct efx_nic *efx, __le64 *mc_stats);
void efx_nic_update_stats(const void *stat_desc, unsigned int stat_count,
              const unsigned long *mask, u64 *stats,
              __le64 *mc_stats, bool accumulate);
size_t ef100_update_stats_common(struct efx_nic *efx, u64 *full_stats,
                 struct rtnl_link_stats64 *core_stats);