#include <stdint.h>
#include <netinet/in.h>

typedef uint32_t __u32;
typedef uint16_t __u16;

typedef enum {
    SCTP_DISPOSITION_DISCARD,
    SCTP_DISPOSITION_CONSUME
} sctp_disposition_t;

struct sctp_endpoint;

struct sctp_chunkhdr {
    __u16 length;
};

struct sctp_fwdtsn_chunk {
    struct sctp_chunkhdr chunk_hdr;
};

struct sctp_fwdtsn_hdr {
    __u32 new_cum_tsn;
};

struct sctp_fwdtsn_skip {
    __u16 stream;
};

struct sk_buff {
    void *data;
};

struct sctp_chunk_subh {
    struct sctp_fwdtsn_hdr *fwdtsn_hdr;
};

struct sctp_chunk {
    struct sk_buff *skb;
    struct sctp_chunk_subh subh;
    struct sctp_chunkhdr *chunk_hdr;
};

struct sctp_tsnmap {
    int dummy;
};

struct sctp_association_peer {
    struct sctp_tsnmap tsn_map;
};

struct sctp_association_c {
    int sinit_max_instreams;
};

struct sctp_association {
    struct sctp_association_peer peer;
    int autoclose;
    struct sctp_association_c c;
};

typedef struct {
    int dummy;
} sctp_subtype_t;

typedef struct {
    int dummy;
} sctp_cmd_seq_t;

#define SCTP_CMD_REPORT_BAD_TAG 0
#define SCTP_CMD_REPORT_FWDTSN 1
#define SCTP_CMD_PROCESS_FWDTSN 2
#define SCTP_CMD_TIMER_RESTART 3
#define SCTP_CMD_GEN_SACK 4

#define SCTP_NULL() 0
#define SCTP_U32(x) (x)
#define SCTP_CHUNK(x) ((int)(long)(x))
#define SCTP_TO(x) (x)
#define SCTP_NOFORCE() 0
#define SCTP_EVENT_TIMEOUT_AUTOCLOSE 0

#define SCTP_DEBUG_PRINTK(fmt, ...)

int sctp_vtag_verify(struct sctp_chunk *chunk, const struct sctp_association *asoc);
int sctp_chunk_length_valid(struct sctp_chunk *chunk, size_t size);
sctp_disposition_t sctp_sf_pdiscard(const struct sctp_endpoint *ep,
                                   const struct sctp_association *asoc,
                                   const sctp_subtype_t type,
                                   void *arg,
                                   sctp_cmd_seq_t *commands);
sctp_disposition_t sctp_sf_violation_chunklen(const struct sctp_endpoint *ep,
                                             const struct sctp_association *asoc,
                                             const sctp_subtype_t type,
                                             void *arg,
                                             sctp_cmd_seq_t *commands);
int sctp_tsnmap_check(const struct sctp_tsnmap *map, __u32 tsn);
#define sctp_walk_fwdtsn(skip, chunk) for((skip) = (struct sctp_fwdtsn_skip *)(chunk)->skb->data; \
                                         (char *)(skip) < (char *)(chunk)->skb->data + ntohs((chunk)->chunk_hdr->length) - sizeof(struct sctp_chunkhdr); \
                                         (skip)++)
void sctp_add_cmd_sf(sctp_cmd_seq_t *commands, int cmd, int param);
void skb_pull(struct sk_buff *skb, unsigned int len);