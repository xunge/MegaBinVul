#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define RTC_IRQ 8
#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })

enum pt_source {
    PTSRC_lapic,
    PTSRC_isa,
    PTSRC_ioapic
};

struct list_head {
    struct list_head *next, *prev;
};

struct periodic_time {
    struct list_head list;
    int pending_intr_nr;
    int irq;
    void *priv;
    int on_list;
    uint64_t last_plt_gtime;
    uint64_t period;
    int irq_issued;
    enum pt_source source;
};

struct vpic {
    int int_output;
};

struct hvm_domain {
    struct vpic vpic[16];
};

struct arch_domain {
    struct hvm_domain hvm_domain;
};

struct domain {
    struct arch_domain arch;
};

struct hvm_vcpu {
    struct list_head tm_list;
    int tm_lock;
};

struct arch_vcpu {
    struct hvm_vcpu hvm_vcpu;
};

struct vcpu {
    struct arch_vcpu arch;
    struct domain *domain;
};

struct vlapic;

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member), \
         n = container_of(pos->member.next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = n, n = container_of(n->member.next, typeof(*n), member))

#define list_del(entry) do { \
    (entry)->next->prev = (entry)->prev; \
    (entry)->prev->next = (entry)->next; \
} while (0)

#define spin_lock(lock) (*(lock) = 1)
#define spin_unlock(lock) (*(lock) = 0)

int pt_irq_masked(struct periodic_time *pt);
struct vlapic *vcpu_vlapic(struct vcpu *v);
void vlapic_set_irq(struct vlapic *v, int irq, int level);
int vlapic_accept_pic_intr(struct vcpu *v);
int vlapic_test_irq(struct vlapic *v, int vector);
int hvm_isa_irq_deassert(struct domain *d, int irq);
int hvm_isa_irq_assert(struct domain *d, int irq, void *(*get_vector)(void));
int hvm_ioapic_assert(struct domain *d, int irq, bool level);
int platform_legacy_irq(int irq);
void *vioapic_get_vector(void);