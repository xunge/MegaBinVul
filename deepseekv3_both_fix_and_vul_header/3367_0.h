#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct xc_interface xc_interface;
typedef struct xc_cpupoolinfo {
    uint32_t cpupool_id;
    uint32_t sched_id;
    uint32_t n_dom;
    uint8_t *cpumap;
} xc_cpupoolinfo_t;

#define DECLARE_SYSCTL struct xen_sysctl sysctl
#define DECLARE_HYPERCALL_BUFFER(type, name) type *name
#define PERROR(msg) 
#define XEN_SYSCTL_cpupool_op 0
#define XEN_SYSCTL_CPUPOOL_OP_INFO 0

struct xen_sysctl {
    int cmd;
    union {
        struct {
            int op;
            uint32_t cpupool_id;
            uint32_t sched_id;
            uint32_t n_dom;
            struct {
                void *bitmap;
                unsigned int nr_bits;
            } cpumap;
        } cpupool_op;
    } u;
};

int xc_get_cpumap_size(xc_interface *xch);
void *xc_hypercall_buffer_alloc(xc_interface *xch, void *ptr, size_t size);
void xc_hypercall_buffer_free(xc_interface *xch, void *ptr);
int do_sysctl_save(xc_interface *xch, struct xen_sysctl *sysctl);
uint8_t *xc_cpumap_alloc(xc_interface *xch);
void set_xen_guest_handle(void *handle, void *ptr);