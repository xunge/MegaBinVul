#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>

typedef uint32_t __u32;
typedef struct sctp_association sctp_association_t;
typedef struct sctp_chunk sctp_chunk_t;
typedef struct sctp_cmd_seq sctp_cmd_seq_t;
typedef int sctp_verb_t;

struct sctp_datahdr {
    __u32 tsn;
    uint16_t stream;
    uint16_t ssn;
    uint32_t ppid;
    uint8_t payload[0];
};
typedef struct sctp_datahdr sctp_datahdr_t;

struct sctp_chunkhdr {
    uint8_t type;
    uint8_t flags;
    uint16_t length;
};

struct sctp_data_chunk {
    struct sctp_chunkhdr chunk_hdr;
    struct sctp_datahdr data_hdr;
};
typedef struct sctp_data_chunk sctp_data_chunk_t;

struct sk_buff {
    unsigned char *data;
    struct {
        struct iphdr *iph;
    } nh;
};

struct iphdr {
    uint8_t version;
};

struct sctp_chunk {
    struct sk_buff *skb;
    union {
        struct sctp_datahdr *data_hdr;
    } subh;
    struct sctp_chunkhdr *chunk_hdr;
    int ecn_ce_done;
    int data_accepted;
};

struct sctp_ep {
    int rcvbuf_policy;
};

struct sctp_tsnmap {
    __u32 base_tsn;
    __u32 cumulative_tsn;
    __u32 max_tsn_seen;
    uint8_t *tsn_map;
    size_t len;
};

struct sctp_association {
    struct {
        struct sock *sk;
    } base;
    int state;
    struct sctp_ep *ep;
    struct {
        int ecn_capable;
        struct sctp_tsnmap tsn_map;
    } peer;
    struct {
        int pd_mode;
    } ulpq;
    struct {
        int sinit_max_instreams;
    } c;
    int rmem_alloc;
    size_t rwnd;
    int rwnd_over;
    size_t frag_point;
};

struct sock {
    int sk_rcvbuf;
    int sk_rmem_alloc;
};

struct sctp_af {
    int (*is_ce)(struct sk_buff *skb);
};

enum sctp_commands {
    SCTP_CMD_ECN_CE,
    SCTP_CMD_REPORT_DUP,
    SCTP_CMD_PART_DELIVER,
    SCTP_CMD_RENEGE,
    SCTP_CMD_REPLY,
    SCTP_CMD_DISCARD_PACKET,
    SCTP_CMD_ASSOC_FAILED,
    SCTP_CMD_REPORT_TSN,
    SCTP_CMD_CHUNK_ULP
};

enum sctp_errors {
    SCTP_ERROR_NO_DATA,
    SCTP_ERROR_INV_STRM
};

enum sctp_states {
    SCTP_STATE_ESTABLISHED = 1
};

enum sctp_ierrors {
    SCTP_IERROR_IGNORE_TSN,
    SCTP_IERROR_HIGH_TSN,
    SCTP_IERROR_DUP_TSN,
    SCTP_IERROR_NO_DATA,
    SCTP_IERROR_BAD_STREAM,
    SCTP_IERROR_NO_ERROR
};

enum sctp_mibs {
    SCTP_MIB_ABORTEDS,
    SCTP_MIB_CURRESTAB,
    SCTP_MIB_INUNORDERCHUNKS,
    SCTP_MIB_INORDERCHUNKS
};

#define SCTP_DATA_UNORDERED 0x01
#define SCTP_DEBUG_PRINTK(fmt, ...)
#define SCTP_INC_STATS(x)
#define SCTP_DEC_STATS(x)
#define unlikely(x) (x)
#define SCTP_U32(x) ((void*)(uintptr_t)(x))
#define SCTP_NULL() NULL
#define SCTP_CHUNK(x) ((void*)(x))

static inline void skb_pull(struct sk_buff *skb, unsigned int len) {
    skb->data += len;
}

static inline int atomic_read(const int *v) { return *v; }
static inline int sctp_tsnmap_check(struct sctp_tsnmap *map, __u32 tsn) { return 0; }
static inline int sctp_tsnmap_has_gap(struct sctp_tsnmap *map) { return 0; }
static inline __u32 sctp_tsnmap_get_ctsn(const struct sctp_tsnmap *map) { return map->cumulative_tsn; }
static inline void sctp_add_cmd_sf(sctp_cmd_seq_t *commands, sctp_verb_t verb, void *obj) {}
static inline struct sctp_chunk *sctp_make_abort_no_data(const struct sctp_association *asoc, struct sctp_chunk *chunk, __u32 tsn) { return NULL; }
static inline struct sctp_chunk *sctp_make_op_error(const struct sctp_association *asoc, struct sctp_chunk *chunk, int error, void *data, size_t len) { return NULL; }
static inline struct sctp_af *sctp_get_af_specific(int family) { return NULL; }
static inline int ipver2af(int version) { return 0; }