#include <stdint.h>
#include <stdatomic.h>
#include <string.h>
#include <stdbool.h>

struct smc_link;
struct smc_ib_device;
struct smc_link_group;
struct ib_device;

enum {
    SMC_LNK_UNUSED,
};

struct smc_link {
    struct smc_link_group *lgr;
    int state;
    uint32_t peer_qpn;
    struct smc_ib_device *smcibdev;
};

struct smc_ib_device {
    struct ib_device *ibdev;
    atomic_int lnk_cnt;
    int lnks_deleted; // Simplified placeholder for wait queue
};

struct ib_device {
    int dev; // Simplified placeholder for device structure
};