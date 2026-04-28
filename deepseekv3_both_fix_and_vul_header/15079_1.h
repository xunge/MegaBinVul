#include <stdint.h>
#include <netinet/in.h>
#include <stddef.h>

typedef uint32_t __u32;
typedef uint16_t __u16;

typedef enum {
    SCTP_DISPOSITION_CONSUME
} sctp_disposition_t;

struct sctp_endpoint;
struct sctp_association;
struct sctp_chunk;
struct sctp_cmd_seq;
struct sctp_subtype;

typedef struct {
    int dummy;
} sctp_subtype_t;

typedef struct {
    int dummy;
} sctp_cmd_seq_t;

struct sctp_fwdtsn_hdr {
    __u32 new_cum_tsn;
};

struct sctp_fwdtsn_skip {
    __u16 stream;
};

struct sctp_chunkhdr {
    __u16 length;
};

struct sctp_fwdtsn_chunk {
    int dummy;
};

struct sctp_chunk {
    struct sctp_chunkhdr *chunk_hdr;
    struct {
        struct sctp_fwdtsn_hdr *fwdtsn_hdr;
    } subh;
    struct sk_buff *skb;
};

struct sk_buff {
    void *data;
};

struct sctp_tsn_map {
    int dummy;
};

struct sctp_association {
    struct {
        __u16 sinit_max_instreams;
    } c;
    struct {
        struct sctp_tsn_map tsn_map;
    } peer;
};

#define SCTP_CMD_REPORT_BAD_TAG 0
#define SCTP_CMD_REPORT_FWDTSN 1
#define SCTP_CMD_PROCESS_FWDTSN 2
#define SCTP_CMD_GEN_SHUTDOWN 3
#define SCTP_CMD_GEN_SACK 4
#define SCTP_CMD_TIMER_RESTART 5

#define SCTP_NULL() NULL
#define SCTP_U32(x) (x)
#define SCTP_CHUNK(x) (x)
#define SCTP_FORCE() (void*)1
#define SCTP_TO(x) (x)
#define SCTP_EVENT_TIMEOUT_T2_SHUTDOWN 0

static inline int sctp_vtag_verify(struct sctp_chunk *chunk, const struct sctp_association *asoc) { return 1; }
static inline int sctp_chunk_length_valid(struct sctp_chunk *chunk, size_t size) { return 1; }
static inline sctp_disposition_t sctp_sf_pdiscard(const struct sctp_endpoint *ep, const struct sctp_association *asoc, const sctp_subtype_t type, void *arg, sctp_cmd_seq_t *commands) { return SCTP_DISPOSITION_CONSUME; }
static inline sctp_disposition_t sctp_sf_violation_chunklen(const struct sctp_endpoint *ep, const struct sctp_association *asoc, const sctp_subtype_t type, void *arg, sctp_cmd_seq_t *commands) { return SCTP_DISPOSITION_CONSUME; }
static inline int sctp_tsnmap_check(const struct sctp_tsn_map *map, __u32 tsn) { return 0; }
static inline void sctp_add_cmd_sf(sctp_cmd_seq_t *commands, int cmd, void *arg) {}
#define sctp_walk_fwdtsn(skip, chunk) for (skip = NULL; skip == NULL; skip = (void*)1)
static inline void skb_pull(struct sk_buff *skb, __u16 len) {}
#define SCTP_DEBUG_PRINTK(fmt, ...)