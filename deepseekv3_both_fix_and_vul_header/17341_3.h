#include <stdint.h>
#include <arpa/inet.h>
#include <stddef.h>

typedef uint8_t __u8;

struct sctp_chunkhdr {
    __u8 type;
    __u8 flags;
    uint16_t length;
};

struct sctp_association_base {
    struct sock *sk;
};

struct sctp_association {
    struct sctp_association_base base;
};

struct sctp_chunk {
    struct sctp_chunkhdr *chunk_hdr;
    __u8 *chunk_end;
    int auth;
};

struct sock;
struct sk_buff;

typedef unsigned int gfp_t;

#define SCTP_PAD4(x) (((x) + 3) & ~3)
#define SCTP_MAX_CHUNK_LEN 65535

void *alloc_skb(int size, gfp_t flags);
void kfree_skb(void *skb);
void *skb_put(void *skb, unsigned int len);
struct sctp_chunk *sctp_chunkify(void *skb, const struct sctp_association *asoc, struct sock *sk, gfp_t gfp);
int sctp_auth_send_cid(__u8 type, const struct sctp_association *asoc);