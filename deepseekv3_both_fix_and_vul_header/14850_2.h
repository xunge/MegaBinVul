#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>

typedef uint8_t __u8;

struct sk_buff {
    unsigned char *data;
    unsigned char *tail;
};

struct list_head {
    struct list_head *next, *prev;
};

struct sctp_chunkhdr {
    uint16_t type;
    uint16_t length;
};
typedef struct sctp_chunkhdr sctp_chunkhdr_t;

struct sctp_chunk {
    struct list_head list;
    struct sk_buff *skb;
    sctp_chunkhdr_t *chunk_hdr;
    unsigned char *chunk_end;
    int singleton;
    int end_of_packet;
    int pdiscard;
    int data_accepted;
    union {
        void *v;
    } subh;
};

struct sctp_inq {
    struct sctp_chunk *in_progress;
    struct list_head in_chunk_list;
};

#define WORD_ROUND(x) (((x) + 3) & ~3)
#define unlikely(x) __builtin_expect(!!(x), 0)
#define SCTP_DEBUG_PRINTK(fmt, ...)
#define SCTP_ST_CHUNK(x) (x)
#define sctp_cname(x) ""

static inline void skb_pull(struct sk_buff *skb, unsigned int len) {
    skb->data += len;
}

static inline int skb_is_nonlinear(const struct sk_buff *skb) {
    return 0;
}

static inline void sctp_chunk_free(struct sctp_chunk *chunk) {
}

static inline void list_del_init(struct list_head *entry) {
    entry->next = entry;
    entry->prev = entry;
}

static inline int list_empty(const struct list_head *head) {
    return head->next == head;
}

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))