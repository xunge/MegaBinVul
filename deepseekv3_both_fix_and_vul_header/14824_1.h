#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define EINVAL 22
#define ENOMEM 12
#define PAGE_SIZE 4096
#define MAX_OPROF_SHARED_PAGES 1024
#define CONFIG_COMPAT 1
#define XENOPROF_DOMAIN_IGNORED 0

struct domain {
    struct xenoprof *xenoprof;
    int max_vcpus;
};

struct vcpu {
    int vcpu_id;
};

struct xenoprof {
    struct xenoprof_vcpu *vcpu;
    void *rawbuf;
    int npages;
    int nbuf;
    int bufsize;
    int domain_ready;
    int domain_type;
    int is_compat;
};

struct xenoprof_vcpu {
    int event_size;
    void *buffer;
};

struct xenoprof_buf {
    int event_size;
    int vcpu_id;
};

struct event_log {
    char dummy;
};

struct compat_oprof_buf {
    char dummy;
};

struct compat_event_log {
    char dummy;
};

typedef struct xenoprof_buf xenoprof_buf_t;

#define for_each_vcpu(d, v) for (v = NULL; v == NULL; v = (void*)1)
#define xzalloc(type) ((type *)calloc(1, sizeof(type)))
#define xzalloc_array(type, num) ((type *)calloc(num, sizeof(type)))
#define xfree(ptr) free(ptr)
#define printk printf
#define XENOPROF_COMPAT(x) ((x)->is_compat)
#define xenoprof_buf(d, buf, field) ((buf)->field)
#define get_order_from_pages(pages) (pages)
#define alloc_xenheap_pages(order, flags) malloc((1 << (order)) * PAGE_SIZE)
#define is_pv_32bit_domain(d) 0
#define hardware_domain NULL