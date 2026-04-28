#include <string.h>
#include <stdlib.h>

struct config_item;
struct gadget_info {
    struct {
        struct {
            char *udc_name;
        } gadget_driver;
    } composite;
    int lock;
};

#define GFP_KERNEL 0
#define EOVERFLOW 1
#define ENOMEM 2
#define EBUSY 3

static inline struct gadget_info *to_gadget_info(struct config_item *item)
{
    return (struct gadget_info *)item;
}

static int unregister_gadget(struct gadget_info *gi)
{
    return 0;
}

static int usb_gadget_probe_driver(void *driver)
{
    return 0;
}

static void mutex_lock(int *lock) {}
static void mutex_unlock(int *lock) {}

static char *kstrdup(const char *s, int gfp)
{
    char *p = malloc(strlen(s) + 1);
    if (p) strcpy(p, s);
    return p;
}

static void kfree(void *p) { free(p); }