#include <stddef.h>
#include <errno.h>
#include <stdbool.h>

typedef unsigned int evtchn_port_t;

#define GFP_KERNEL 0
#define __GFP_ZERO 0
#define __init

#define CPUHP_XEN_EVTCHN_PREPARE 0
#define CONFIG_X86 1
#define XENFEAT_hvm_callback_vector 0
#define PHYSDEVOP_pirq_eoi_gmfn_v2 0
#define EVTCHN_ROW(x) (x)

struct physdev_pirq_eoi_gmfn {
    unsigned long gmfn;
};

extern bool fifo_events;
extern int xen_evtchn_fifo_init(void);
extern void xen_evtchn_2l_init(void);
extern int xen_evtchn_cpu_prepare(unsigned int cpu);
extern int xen_evtchn_cpu_dead(unsigned int cpu);
extern unsigned int xen_evtchn_max_channels(void);
extern unsigned int xen_evtchn_nr_channels(void);
extern void mask_evtchn(evtchn_port_t port);
extern bool (*pirq_needs_eoi)(int irq);
extern bool (*pirq_check_eoi_map)(int irq);
extern bool (*pirq_needs_eoi_flag)(int irq);
extern void *evtchn_to_irq;
extern void *pirq_eoi_map;

extern void cpuhp_setup_state_nocalls(int state, const char *name,
                    int (*prepare)(unsigned int cpu),
                    int (*dead)(unsigned int cpu));
extern void *kcalloc(size_t n, size_t size, int flags);
extern void BUG_ON(int condition);
extern void *__get_free_page(int flags);
extern void free_page(unsigned long addr);
extern int HYPERVISOR_physdev_op(int cmd, void *data);
extern unsigned long virt_to_gfn(void *virt);
extern bool xen_pv_domain(void);
extern bool xen_initial_domain(void);
extern void pci_xen_initial_domain(void);
extern bool xen_feature(int feature);
extern void xen_setup_callback_vector(void);
extern void xen_alloc_callback_vector(void);
extern bool xen_hvm_domain(void);
extern void native_init_IRQ(void);
extern void pci_xen_hvm_init(void);