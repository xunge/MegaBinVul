#include <stdlib.h>

struct domain {
    struct {
        struct {
            void *io_handler;
            void *params;
        } hvm_domain;
    } arch;
};

extern void xfree(void *ptr);
extern void hvm_destroy_cacheattr_region_list(struct domain *d);
extern int is_pvh_domain(struct domain *d);
extern struct {
    void (*domain_destroy)(struct domain *d);
} hvm_funcs;
extern void rtc_deinit(struct domain *d);
extern void stdvga_deinit(struct domain *d);
extern void vioapic_deinit(struct domain *d);