#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

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
    int dummy;
};

struct compat_oprof_buf {
    int dummy;
};

struct compat_event_log {
    int dummy;
};

#define for_each_vcpu(d, v) for (v = NULL; v == NULL; v = (void*)1)
#define xzalloc(type) ((type *)calloc(1, sizeof(type)))
#define xzalloc_array(type, count) ((type *)calloc(count, sizeof(type)))
#define xfree(ptr) free(ptr)
#define printk printf
#define MAX_OPROF_SHARED_PAGES 1024
#define PAGE_SIZE 4096
#define CONFIG_COMPAT 1
#define XENOPROF_COMPAT(x) (x)->is_compat
#define XENOPROF_DOMAIN_IGNORED 0
#define xenoprof_buf(d, buf, field) (buf)->field

static struct domain *hardware_domain;

static void *alloc_xenheap_pages(unsigned int order, int flags) {
    return malloc(1 << (order + 12));
}

static int get_order_from_pages(int pages) {
    return 0;
}

static int is_pv_32bit_domain(struct domain *d) {
    return 0;
}

typedef struct xenoprof_buf xenoprof_buf_t;