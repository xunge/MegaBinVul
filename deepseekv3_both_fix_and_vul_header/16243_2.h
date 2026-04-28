#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct irq_info {
    struct list_head list;
    unsigned int refcnt;
};

extern struct irq_info *info_for_irq(unsigned int irq);
extern void set_info_for_irq(unsigned int irq, struct irq_info *info);
extern unsigned int nr_legacy_irqs(void);
extern void irq_free_desc(unsigned int irq);
extern void kfree(void *ptr);

static struct {
    int dummy;
} evtchn_rwlock;

#define WARN_ON(condition) (condition)

static inline void list_del(struct list_head *entry) {
    entry->next->prev = entry->prev;
    entry->prev->next = entry->next;
}

static inline void write_lock_irqsave(void *lock, unsigned long flags) {}
static inline void write_unlock_irqrestore(void *lock, unsigned long flags) {}