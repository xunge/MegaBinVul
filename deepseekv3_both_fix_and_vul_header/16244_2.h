struct vcpu_info {
    int evtchn_upcall_pending;
};

struct rwlock {
    int lock;
};

extern struct vcpu_info *xen_vcpu;
extern struct rwlock evtchn_rwlock;
extern int smp_processor_id(void);
extern void xen_evtchn_handle_events(int cpu);
extern void read_lock(struct rwlock *lock);
extern void read_unlock(struct rwlock *lock);
extern int irqs_disabled(void);
#define BUG_ON(condition) ((void)0)
#define virt_rmb() __asm__ __volatile__("" ::: "memory")
#define __this_cpu_read(var) (var)