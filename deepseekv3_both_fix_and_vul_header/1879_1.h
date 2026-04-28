#include <stdbool.h>
#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct domain {
    struct list_head list;
    bool introduced;
    int port;
    void *interface;
    int domid;
};

extern void *xce_handle;
extern int xenevtchn_unbind(void *handle, int port);
extern void eprintf(const char *format, ...);
extern void unmap_xenbus(void *interface);
extern void unmap_interface(void *interface);
extern void fire_watches(void *ctx, struct domain *domain, const char *path, const char *token, bool is_create, void *watch);
extern void wrl_domain_destroy(struct domain *domain);

static inline void list_del(struct list_head *entry)
{
    entry->next->prev = entry->prev;
    entry->prev->next = entry->next;
}