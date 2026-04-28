#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct gpio_desc;

struct regulator_dev {
    struct {
        struct gpio_desc *gpiod;
    } *ena_pin;
};

struct regulator_enable_gpio {
    struct gpio_desc *gpiod;
    int request_count;
    struct list_head list;
};

extern struct list_head regulator_ena_gpio_list;

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = (typeof(*pos)*)((char*)(head)->next - offsetof(typeof(*pos), member)), \
         n = (typeof(*pos)*)((char*)pos->member.next - offsetof(typeof(*pos), member)); \
         &pos->member != (head); \
         pos = n, n = (typeof(*pos)*)((char*)n->member.next - offsetof(typeof(*pos), member)))

void gpiod_put(struct gpio_desc *desc);
void list_del(struct list_head *entry);
void kfree(const void *objp);