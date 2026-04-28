#include <stdbool.h>
#include <stddef.h>

struct expander_device {
    int num_phys;
};

struct domain_device {
    struct expander_device ex_dev;
};

int sas_find_bcast_dev(struct domain_device *port_dev, struct domain_device **dev);
int sas_find_bcast_phy(struct domain_device *dev, int *phy_id, int i, bool flag);
int sas_rediscover(struct domain_device *dev, int phy_id);