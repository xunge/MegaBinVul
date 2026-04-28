#include <stddef.h>
#include <stdint.h>

struct list_head {
    struct list_head *next, *prev;
};

struct asd_sas_port {
    struct list_head destroy_list;
};

struct domain_device {
    unsigned long state;
    struct list_head disco_list_node;
    void *rphy;
    void *port;
};

enum {
    SAS_DEV_DESTROY,
    DISCE_DESTRUCT
};

#define test_bit(nr, addr) ((*(addr) & (1UL << (nr))) != 0)
#define test_and_set_bit(nr, addr) (__sync_fetch_and_or(addr, (1UL << (nr))) & (1UL << (nr)))

static inline int list_empty(const struct list_head *head) {
    return head->next == head;
}

static inline void list_del_init(struct list_head *entry) {
    entry->next = entry;
    entry->prev = entry;
}

static inline void list_move_tail(struct list_head *list, struct list_head *head) {
    list->next->prev = list->prev;
    list->prev->next = list->next;
    list->next = head;
    list->prev = head->prev;
    head->prev->next = list;
    head->prev = list;
}

void sas_rphy_free(void *rphy);
void sas_unregister_common_dev(struct asd_sas_port *port, struct domain_device *dev);
void sas_rphy_unlink(void *rphy);
void sas_discover_event(void *port, int event);