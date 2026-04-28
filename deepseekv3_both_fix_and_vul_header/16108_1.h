#include <errno.h>

struct vcpu;
struct cpupool;

enum {
    DOMDYING_alive,
    DOMDYING_dying,
    DOMDYING_dead
};

struct domain {
    int is_dying;
    void *vnuma;
    struct domain *domain;
};

extern struct domain *current;
extern struct cpupool *cpupool0;
extern int VIRQ_DOM_EXC;

#define for_each_vcpu(d, v) /* implementation-defined */

int domain_unlock(struct domain *d);
int domain_pause(struct domain *d);
int domain_lock(struct domain *d);
void argo_destroy(struct domain *d);
int evtchn_destroy(struct domain *d);
void gnttab_release_mappings(struct domain *d);
void vnuma_destroy(void *vnuma);
void domain_set_outstanding_pages(struct domain *d, int count);
int domain_relinquish_resources(struct domain *d);
int cpupool_move_domain(struct domain *d, struct cpupool *pool);
void unmap_vcpu_info(struct vcpu *v);
void vm_event_cleanup(struct domain *d);
void put_domain(struct domain *d);
void send_global_virq(int virq);