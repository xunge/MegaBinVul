#include <stddef.h>
#include <stdint.h>

typedef uint32_t __be32;

struct list_head {
    struct list_head *next, *prev;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

struct sctp_addip_hdr {
    __be32 serial;
};

struct sctp_chunk {
    struct list_head transmitted_list;
    struct {
        struct sctp_addip_hdr *addip_hdr;
    } subh;
};

struct sctp_association {
    struct list_head asconf_ack_list;
};

void sctp_chunk_hold(struct sctp_chunk *chunk);