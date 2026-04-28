#include <stddef.h>
#include <stdbool.h>

struct list_head {
    struct list_head *next, *prev;
};

struct irq_info {
    struct list_head list;
    struct list_head eoi_list;
    int refcnt;
};

extern struct irq_info *info_for_irq(unsigned int irq);
extern void set_info_for_irq(unsigned int irq, struct irq_info *info);
extern void lateeoi_list_del(struct irq_info *info);
extern int nr_legacy_irqs(void);
extern void irq_free_desc(unsigned int irq);
extern void kfree(void *ptr);

static struct {
    int lock;
} evtchn_rwlock;

static inline bool WARN_ON(bool condition) { return condition; }
static inline void write_lock_irqsave(void *lock, unsigned long flags) {}
static inline void write_unlock_irqrestore(void *lock, unsigned long flags) {}
static inline bool list_empty(struct list_head *list) { return false; }
static inline void list_del(struct list_head *list) {}