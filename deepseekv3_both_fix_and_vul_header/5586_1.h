#include <stdint.h>
#include <errno.h>
#include <string.h>

#define DECLARE_DOMCTL struct xen_domctl domctl
#define PERROR(msg) perror(msg)
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef struct xc_interface xc_interface;

typedef struct xc_dominfo {
    uint32_t domid;
} xc_dominfo_t;

struct xen_domctl {
    uint32_t cmd;
    uint32_t domain;
    union {
        struct {
            uint32_t add_mapping;
            unsigned long nr_mfns;
            unsigned long first_gfn;
            unsigned long first_mfn;
        } memory_mapping;
    } u;
};

#define DPCI_REMOVE_MAPPING 0
#define XEN_DOMCTL_memory_mapping 0
#define E2BIG 7
#define EINVAL 22

int xc_domain_getinfo(xc_interface *xch, uint32_t domid, int max, xc_dominfo_t *info);
int xc_core_arch_auto_translated_physmap(xc_dominfo_t *info);
int do_domctl(xc_interface *xch, struct xen_domctl *domctl);