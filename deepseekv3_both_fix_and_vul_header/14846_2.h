#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>

typedef int sctp_disposition_t;
typedef int sctp_subtype_t;
typedef int sctp_cmd_seq_t;
typedef int sctp_init_chunk_t;
typedef struct sctp_ulpevent sctp_ulpevent_t;
typedef struct sctp_chunkhdr sctp_chunkhdr_t;
typedef struct sctp_signed_cookie sctp_signed_cookie_t;
typedef struct sctp_association sctp_association_t;
typedef struct sctp_endpoint sctp_endpoint_t;
typedef struct sctp_chunk sctp_chunk_t;
typedef int sctp_cmd_sf_t;
typedef int sctp_state_t;
typedef int sctp_event_timeout_t;
typedef int sctp_adaptation_ind_t;

struct sk_buff {
    void *data;
};

struct sock;
struct sctp_sock {
    struct sctp_endpoint *ep;
};

struct sctp_chunkhdr {
    uint16_t length;
    uint8_t type;
};

struct sctp_init_chunk {
    uint8_t unused;
};

struct sctp_signed_cookie {
    struct {
        struct sctp_init_chunk peer_init[1];
        int peer_addr;
    } c;
};

struct sctp_chunk {
    struct sk_buff *skb;
    union {
        struct sctp_signed_cookie *cookie_hdr;
    } subh;
    struct sctp_chunkhdr *chunk_hdr;
};

struct sctp_association {
    int autoclose;
    struct {
        int sinit_num_ostreams;
        int sinit_max_instreams;
    } c;
    struct {
        int adaption_ind;
    } peer;
};

struct sctp_ulpevent {
    int unused;
};

#define GFP_ATOMIC 0
#define SCTP_DISPOSITION_CONSUME 0
#define SCTP_DISPOSITION_NOMEM 1
#define SCTP_STATE_ESTABLISHED 1
#define SCTP_COMM_UP 1
#define SCTP_IERROR_NOMEM 1
#define SCTP_IERROR_STALE_COOKIE 2
#define SCTP_IERROR_BAD_SIG 3
#define SCTP_MIB_CURRESTAB 0
#define SCTP_MIB_PASSIVEESTABS 0
#define SCTP_EVENT_TIMEOUT_AUTOCLOSE 0
#define SCTP_NULL() NULL
#define SCTP_ASOC(x) (x)
#define SCTP_STATE(x) (x)
#define SCTP_TO(x) (x)
#define SCTP_CHUNK(x) (x)
#define SCTP_ULPEVENT(x) (x)
#define SCTP_CMD_NEW_ASOC 0
#define SCTP_CMD_NEW_STATE 1
#define SCTP_CMD_HB_TIMERS_START 2
#define SCTP_CMD_TIMER_START 3
#define SCTP_CMD_TRANSMIT 4
#define SCTP_CMD_REPLY 5
#define SCTP_CMD_EVENT_ULP 6

static inline struct sctp_sock *sctp_sk(const struct sock *sk) { return (struct sctp_sock *)sk; }
static inline struct sock *sctp_get_ctl_sock(void) { return NULL; }
static inline sctp_disposition_t sctp_sf_ootb(const struct sctp_endpoint *ep, const struct sctp_association *asoc, sctp_subtype_t type, void *arg, sctp_cmd_seq_t *commands) { return SCTP_DISPOSITION_NOMEM; }
static inline sctp_disposition_t sctp_sf_pdiscard(const struct sctp_endpoint *ep, const struct sctp_association *asoc, sctp_subtype_t type, void *arg, sctp_cmd_seq_t *commands) { return SCTP_DISPOSITION_NOMEM; }
static inline int sctp_chunk_length_valid(struct sctp_chunk *chunk, size_t length) { return 1; }
static inline struct sctp_association *sctp_unpack_cookie(const struct sctp_endpoint *ep, const struct sctp_association *asoc, struct sctp_chunk *chunk, int gfp, int *error, struct sctp_chunk **err_chk_p) { return NULL; }
static inline void sctp_send_stale_cookie_err(const struct sctp_endpoint *ep, const struct sctp_association *asoc, struct sctp_chunk *chunk, sctp_cmd_seq_t *commands, struct sctp_chunk *err_chk_p) {}
static inline void sctp_add_cmd_sf(sctp_cmd_seq_t *commands, int cmd, sctp_cmd_sf_t obj) {}
static inline void SCTP_INC_STATS(int stat) {}
static inline int sctp_process_init(struct sctp_association *asoc, int type, int *peer_addr, sctp_init_chunk_t *peer_init, int gfp) { return 1; }
static inline struct sctp_chunk *sctp_make_cookie_ack(struct sctp_association *asoc, struct sctp_chunk *chunk) { return NULL; }
static inline struct sctp_ulpevent *sctp_ulpevent_make_assoc_change(struct sctp_association *asoc, int flags, int state, int error, int out, int in, int gfp) { return NULL; }
static inline struct sctp_ulpevent *sctp_ulpevent_make_adaption_indication(struct sctp_association *asoc, int gfp) { return NULL; }
static inline void sctp_chunk_free(struct sctp_chunk *chunk) {}
static inline void sctp_association_free(struct sctp_association *asoc) {}
static inline void skb_pull(struct sk_buff *skb, unsigned int len) {}