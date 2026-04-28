#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct list_head {
    struct list_head *next, *prev;
};

struct sk_buff {
    unsigned char *data;
    unsigned char *tail;
    unsigned int len;
};

typedef uint16_t __be16;
typedef uint8_t __u8;

struct sctp_chunkhdr {
    __u8 type;
    __u8 flags;
    __be16 length;
};
typedef struct sctp_chunkhdr sctp_chunkhdr_t;

struct sctp_chunk {
    sctp_chunkhdr_t *chunk_hdr;
    __u8 *chunk_end;
    struct sk_buff *skb;
    int singleton;
    int end_of_packet;
    int pdiscard;
    int data_accepted;
    struct list_head list;
    union {
        void *v;
    } subh;
};

struct sctp_inq {
    struct sctp_chunk *in_progress;
    struct list_head in_chunk_list;
};

#define WORD_ROUND(x) (((x) + 3) & ~3)
#define ntohs(x) (x)
#define unlikely(x) (x)

static inline void skb_pull(struct sk_buff *skb, unsigned int len) {
    skb->data += len;
    skb->len -= len;
}

static inline unsigned int skb_headlen(const struct sk_buff *skb) {
    return skb->len;
}

static inline unsigned char *skb_tail_pointer(const struct sk_buff *skb) {
    return skb->tail;
}

static inline int skb_is_nonlinear(const struct sk_buff *skb) {
    return 0;
}

static inline void list_del_init(struct list_head *entry) {
    entry->next = entry;
    entry->prev = entry;
}

static inline int list_empty(const struct list_head *head) {
    return head->next == head;
}

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

void sctp_chunk_free(struct sctp_chunk *chunk);
const char *sctp_cname(int type);
#define SCTP_ST_CHUNK(x) (x)
#define pr_debug(fmt, ...)