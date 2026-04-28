#include <stddef.h>

struct domain_device;
struct domain_device {
    int port;
};

int sas_notify_lldd_dev_found(struct domain_device *dev);
void sas_discover_event(int port, int event);

#define DISCE_PROBE 0