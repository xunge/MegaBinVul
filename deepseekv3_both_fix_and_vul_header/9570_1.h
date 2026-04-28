#include <stdlib.h>

struct domain {
    struct {
        struct {
            void *io_handler;
            void *params;
        } hvm_domain;
    } arch;
    void **vcpu;
};

struct hvm_function_table {
    void (*nhvm_domain_relinquish_resources)(struct domain *d);
};

extern struct hvm_function_table hvm_funcs;
extern int is_pvh_domain(struct domain *d);
extern void xfree(void *ptr);
extern void hvm_destroy_all_ioreq_servers(struct domain *d);
extern void msixtbl_pt_cleanup(struct domain *d);
extern void rtc_deinit(struct domain *d);
extern void pmtimer_deinit(struct domain *d);
extern void hpet_deinit(struct domain *d);