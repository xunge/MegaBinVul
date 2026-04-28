#include <stddef.h>
#include <stdlib.h>

struct rcu_head {
    struct rcu_head *next;
    void (*func)(struct rcu_head *head);
};

struct domain {
    struct rcu_head rcu;
    int max_vcpus;
    struct vcpu **vcpu;
    void *target;
    void *vm_event;
    void *pbuf;
    void *domain_dirty_cpumask;
    void *pirq_tree;
};

struct vcpu {
    void *cpu_hard_affinity;
    void *cpu_hard_affinity_tmp;
    void *cpu_hard_affinity_saved;
    void *cpu_soft_affinity;
    void *vcpu_dirty_cpumask;
    void *continue_hypercall_tasklet;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define CONFIG_XENOPROF

void tasklet_kill(void *);
void vcpu_destroy(struct vcpu *);
void sched_destroy_vcpu(struct vcpu *);
void destroy_waitqueue_vcpu(struct vcpu *);
void grant_table_destroy(struct domain *);
void arch_domain_destroy(struct domain *);
void watchdog_domain_destroy(struct domain *);
void rangeset_domain_destroy(struct domain *);
void sched_destroy_domain(struct domain *);
void free_xenoprof_pages(struct domain *);
void xfree(void *);
void free_cpumask_var(void *);
void free_vcpu_struct(struct vcpu *);
void put_domain(void *);
void evtchn_destroy_final(struct domain *);
void radix_tree_destroy(void *, void (*)(void *));
void free_pirq_struct(void *);
void xsm_free_security_domain(struct domain *);
void free_domain_struct(struct domain *);
void send_global_virq(int);

#define VIRQ_DOM_EXC 0