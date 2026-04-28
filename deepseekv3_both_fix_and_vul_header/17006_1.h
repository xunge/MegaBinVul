#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct list_head {
    struct list_head *next, *prev;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
    struct list_head *prev = head->prev;
    new->next = head;
    new->prev = prev;
    prev->next = new;
    head->prev = new;
}

struct crat_subtype_iolink {
    uint32_t proximity_domain_from;
    uint32_t proximity_domain_to;
    uint8_t version_major;
    uint8_t version_minor;
    uint8_t io_interface_type;
    uint8_t num_hops_xgmi;
    uint32_t minimum_latency;
    uint32_t maximum_latency;
    uint32_t minimum_bandwidth_mbs;
    uint32_t maximum_bandwidth_mbs;
    uint32_t recommended_transfer_size;
    uint32_t flags;
};

struct kfd_iolink_properties {
    uint32_t node_from;
    uint32_t node_to;
    uint8_t ver_maj;
    uint8_t ver_min;
    uint8_t iolink_type;
    uint32_t weight;
    uint32_t min_latency;
    uint32_t max_latency;
    uint32_t min_bandwidth;
    uint32_t max_bandwidth;
    uint32_t rec_transfer_size;
    struct list_head list;
    void *kobj;
};

struct kfd_topology_device {
    uint32_t proximity_domain;
    uint32_t io_link_count;
    struct {
        uint32_t io_links_count;
    } node_props;
    struct list_head io_link_props;
    struct list_head list;
};

#define CRAT_IOLINK_TYPE_PCIEXPRESS 0
#define CRAT_IOLINK_TYPE_XGMI 1
#define CRAT_IOLINK_FLAGS_BI_DIRECTIONAL (1 << 0)

#define ENOMEM 12
#define ENODEV 19

#define GFP_KERNEL 0

#define pr_debug(fmt, ...) 

static inline struct kfd_iolink_properties *kfd_alloc_struct(struct kfd_iolink_properties *p)
{
    return malloc(sizeof(*p));
}

static inline struct kfd_topology_device *kfd_topology_device_by_proximity_domain(uint32_t domain)
{
    return NULL;
}

static inline void *kmemdup(const void *src, size_t len, int flags)
{
    void *dst = malloc(len);
    if (dst)
        memcpy(dst, src, len);
    return dst;
}

static inline int node_distance(uint32_t from, uint32_t to)
{
    return 0;
}