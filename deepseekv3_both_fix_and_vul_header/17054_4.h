#include <stdint.h>

#define DISC_NUM_EVENTS 6

enum discovery_event {
    DISCE_DISCOVER_DOMAIN,
    DISCE_REVALIDATE_DOMAIN,
    DISCE_PROBE,
    DISCE_SUSPEND,
    DISCE_RESUME,
    DISCE_DESTRUCT
};

struct work_struct {
    void (*execute)(struct work_struct *);
};

struct sas_discovery {
    unsigned int pending;
    struct {
        struct work_struct work;
        struct asd_sas_port *port;
    } disc_work[DISC_NUM_EVENTS];
};

struct asd_sas_port;

typedef void (*work_func_t)(struct work_struct *);

void sas_discover_domain(struct work_struct *work);
void sas_revalidate_domain(struct work_struct *work);
void sas_probe_devices(struct work_struct *work);
void sas_suspend_devices(struct work_struct *work);
void sas_resume_devices(struct work_struct *work);
void sas_destruct_devices(struct work_struct *work);

#define INIT_SAS_WORK(work, func) ((work)->execute = func)