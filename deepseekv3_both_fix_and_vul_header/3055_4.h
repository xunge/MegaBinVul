#include <stdint.h>
#include <stddef.h>

typedef int sctp_disposition_t;
typedef int sctp_subtype_t;
typedef int sctp_cmd_seq_t;

struct net;
struct sctp_endpoint;
struct sctp_association;
struct sctp_signed_cookie;

typedef struct sctp_chunkhdr {
    uint16_t length;
} sctp_chunkhdr_t;

struct sk_buff {
    void *data;
};

struct sctp_chunk {
    struct {
        struct sctp_signed_cookie *cookie_hdr;
    } subh;
    struct sk_buff *skb;
    sctp_chunkhdr_t *chunk_hdr;
};

#define GFP_ATOMIC 0
#define SCTP_IERROR_NOMEM 1
#define SCTP_IERROR_STALE_COOKIE 2
#define SCTP_IERROR_BAD_SIG 3
#define SCTP_DISPOSITION_NOMEM 4

#define SCTP_CMD_NEW_ASOC 0
#define SCTP_CMD_DELETE_TCB 1
#define SCTP_CMD_SET_ASOC 2
#define SCTP_ASOC(x) (x)
#define SCTP_NULL() NULL

static inline uint16_t ntohs(uint16_t x) { return x; }
static inline int sctp_chunk_length_valid(struct sctp_chunk *chunk, size_t len) { return 1; }
static inline sctp_disposition_t sctp_sf_violation_chunklen(struct net *net, const struct sctp_endpoint *ep,
    const struct sctp_association *asoc, const sctp_subtype_t type, void *arg, sctp_cmd_seq_t *commands) { return 0; }
static inline int pskb_pull(struct sk_buff *skb, int len) { return 1; }
static inline struct sctp_association *sctp_unpack_cookie(const struct sctp_endpoint *ep,
    const struct sctp_association *asoc, struct sctp_chunk *chunk, int gfp, int *error, struct sctp_chunk **err_chk_p) { return NULL; }
static inline void sctp_send_stale_cookie_err(struct net *net, const struct sctp_endpoint *ep,
    const struct sctp_association *asoc, struct sctp_chunk *chunk, sctp_cmd_seq_t *commands, struct sctp_chunk *err_chk_p) {}
static inline sctp_disposition_t sctp_sf_pdiscard(struct net *net, const struct sctp_endpoint *ep,
    const struct sctp_association *asoc, const sctp_subtype_t type, void *arg, sctp_cmd_seq_t *commands) { return 0; }
static inline char sctp_tietags_compare(struct sctp_association *new_asoc, const struct sctp_association *asoc) { return 0; }
static inline sctp_disposition_t sctp_sf_do_dupcook_a(struct net *net, const struct sctp_endpoint *ep,
    const struct sctp_association *asoc, struct sctp_chunk *chunk, sctp_cmd_seq_t *commands, struct sctp_association *new_asoc) { return 0; }
static inline sctp_disposition_t sctp_sf_do_dupcook_b(struct net *net, const struct sctp_endpoint *ep,
    const struct sctp_association *asoc, struct sctp_chunk *chunk, sctp_cmd_seq_t *commands, struct sctp_association *new_asoc) { return 0; }
static inline sctp_disposition_t sctp_sf_do_dupcook_c(struct net *net, const struct sctp_endpoint *ep,
    const struct sctp_association *asoc, struct sctp_chunk *chunk, sctp_cmd_seq_t *commands, struct sctp_association *new_asoc) { return 0; }
static inline sctp_disposition_t sctp_sf_do_dupcook_d(struct net *net, const struct sctp_endpoint *ep,
    const struct sctp_association *asoc, struct sctp_chunk *chunk, sctp_cmd_seq_t *commands, struct sctp_association *new_asoc) { return 0; }
static inline void sctp_add_cmd_sf(sctp_cmd_seq_t *commands, int cmd, void *arg) {}