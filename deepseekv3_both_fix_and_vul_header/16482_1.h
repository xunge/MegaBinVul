#include <stddef.h>

#define ERESTART 512

struct domain {
    void *event_lock;
};

struct hvm_irq_dpci {
    void *pending_pirq_dpci;
};

struct hvm_domain_irq {
    void *dpci;
};

int is_iommu_enabled(struct domain *d);
int is_hvm_domain(struct domain *d);
void spin_lock(void *lock);
void spin_unlock(void *lock);
struct hvm_irq_dpci *domain_get_irq_dpci(struct domain *d);
int pt_pirq_softirq_active(void *pirq);
int pt_pirq_iterate(struct domain *d, void (*fn)(void), void *data);
void pci_clean_dpci_irq(void);
struct hvm_domain_irq *hvm_domain_irq(struct domain *d);
void free_hvm_irq_dpci(struct hvm_irq_dpci *dpci);