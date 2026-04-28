#include <stdint.h>
#include <pthread.h>
#include <unistd.h>

struct work_struct {
    // minimal definition
};

struct sas_discovery_event {
    struct work_struct work;
    struct asd_sas_port *port;
};

struct sas_discovery {
    unsigned long pending;
};

struct asd_sas_port {
    int id;
    struct sas_ha_struct *ha;
    struct domain_device *port_dev;
    struct sas_discovery disc;
};

struct sas_ha_struct {
    pthread_mutex_t disco_mutex;
    unsigned long state;
};

struct domain_device {
    int dev_type;
};

#define SAS_HA_ATA_EH_ACTIVE 0
#define DISCE_REVALIDATE_DOMAIN 0

#define SAS_DPRINTK(fmt, ...)

#define to_sas_discovery_event(work) ((struct sas_discovery_event *)(work))

enum {
    SAS_FANOUT_EXPANDER_DEVICE,
    SAS_EDGE_EXPANDER_DEVICE
};

static inline void mutex_lock(pthread_mutex_t *mutex) {
    pthread_mutex_lock(mutex);
}

static inline void mutex_unlock(pthread_mutex_t *mutex) {
    pthread_mutex_unlock(mutex);
}

static inline int test_bit(int nr, unsigned long *addr) {
    return (*addr & (1UL << nr)) != 0;
}

static inline void clear_bit(int nr, unsigned long *addr) {
    *addr &= ~(1UL << nr);
}

extern int sas_ex_revalidate_domain(struct domain_device *ddev);
extern pid_t task_pid_nr(void *task);
extern void *current;