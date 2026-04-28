#include <linux/types.h>
#include <linux/errno.h>

struct sata_device {
    int class;
};

struct sas_rphy;
struct sas_port;

struct domain_device {
    int dev_type;
    struct sata_device sata_dev;
    struct sas_rphy *rphy;
    struct sas_port *port;
};

#define SAS_SATA_PM 1
#define ENODEV 19
#define DISCE_PROBE 0

int sas_get_ata_command_set(struct domain_device *dev);
void sas_fill_in_rphy(struct domain_device *dev, struct sas_rphy *rphy);
int sas_notify_lldd_dev_found(struct domain_device *dev);
void sas_discover_event(struct sas_port *port, int event);