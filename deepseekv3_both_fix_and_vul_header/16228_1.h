#include <stdlib.h>
#include <string.h>

struct list_head {
    struct list_head *next, *prev;
};

struct irq_info {
    int type;
    int refcnt;
    struct list_head list;
    struct list_head eoi_list;
};

#define GFP_KERNEL 0
#define IRQT_UNBOUND 0
#define CONFIG_SMP

static struct list_head xen_irq_list_head = { &xen_irq_list_head, &xen_irq_list_head };

static void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static void panic(const char *fmt, ...) { exit(1); }
static void set_info_for_irq(unsigned irq, struct irq_info *info) {}
static void cpumask_copy(void *dest, void *src) {}
static void *irq_get_affinity_mask(unsigned irq) { return NULL; }
static void *cpumask_of(int cpu) { return NULL; }

#define INIT_LIST_HEAD(ptr) do { \
    (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

static void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}