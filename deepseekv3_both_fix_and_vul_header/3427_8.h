#include <stddef.h>
#include <stdint.h>
#include <arpa/inet.h>

typedef int sctp_disposition_t;
typedef int sctp_subtype_t;
typedef int sctp_cmd_seq_t;
typedef int sctp_ierror_t;
typedef int sctp_init_chunk_t;

struct sock {
    struct sctp_endpoint *ep;
};

struct net {
    struct {
        struct sock *ctl_sock;
        int auth_enable;
    } sctp;
};

struct sctp_endpoint {
    struct {
        struct sock *sk;
    } base;
    struct sock *ep;
};

struct sctp_association {
    struct {
        int sinit_num_ostreams;
        int sinit_max_instreams;
    } c;
    struct {
        int auth_capable;
        int adaptation_ind;
    } peer;
    int timeouts[1];
};

struct sk_buff {
    unsigned char *data;
};

struct sctp_chunk {
    struct {
        struct sctp_signed_cookie *cookie_hdr;
    } subh;
    struct sk_buff *skb;
    struct sctp_chunkhdr *chunk_hdr;
    struct sk_buff *auth_chunk;
    struct sctp_association *asoc;
    void *transport;
    void *sctp_hdr;
};

struct sctp_ulpevent;
struct sctp_signed_cookie {
    struct {
        void *peer_addr;
        sctp_init_chunk_t peer_init[0];
    } c;
};

typedef struct sctp_chunkhdr {
    uint16_t length;
} sctp_chunkhdr_t;

#define LISTENING 1
#define TCP 1
#define SCTP_MIB_OUTOFBLUES 0
#define SCTP_MIB_CURRESTAB 0
#define SCTP_MIB_PASSIVEESTABS 0
#define SCTP_STATE_ESTABLISHED 0
#define SCTP_EVENT_TIMEOUT_AUTOCLOSE 0
#define SCTP_COMM_UP 0
#define GFP_ATOMIC 0
#define SCTP_IERROR_NOMEM 1
#define SCTP_IERROR_STALE_COOKIE 2
#define SCTP_IERROR_BAD_SIG 3
#define SCTP_IERROR_NO_ERROR 0
#define SCTP_CMD_NEW_ASOC 0
#define SCTP_CMD_NEW_STATE 1
#define SCTP_CMD_HB_TIMERS_START 2
#define SCTP_CMD_TIMER_START 3
#define SCTP_CMD_REPLY 4
#define SCTP_CMD_EVENT_ULP 5
#define SCTP_DISPOSITION_CONSUME 0
#define SCTP_DISPOSITION_NOMEM 1

static inline struct sock *sctp_sk(struct sock *sk) { return sk; }
static inline void SCTP_INC_STATS(struct net *net, int stat) {}
static inline sctp_disposition_t sctp_sf_tabort_8_4_8(struct net *net, const struct sctp_endpoint *ep,
                    const struct sctp_association *asoc, const sctp_subtype_t type,
                    void *arg, sctp_cmd_seq_t *commands) { return 0; }
static inline int sctp_chunk_length_valid(struct sctp_chunk *chunk, size_t len) { return 1; }
static inline sctp_disposition_t sctp_sf_pdiscard(struct net *net, const struct sctp_endpoint *ep,
                    const struct sctp_association *asoc, const sctp_subtype_t type,
                    void *arg, sctp_cmd_seq_t *commands) { return 0; }
static inline int sctp_sstate(struct sock *sk, int state) { return 1; }
static inline int sctp_style(struct sock *sk, int style) { return 1; }
static inline int sk_acceptq_is_full(struct sock *sk) { return 0; }
static inline int pskb_pull(struct sk_buff *skb, int len) { return 1; }
static inline struct sctp_association *sctp_unpack_cookie(const struct sctp_endpoint *ep,
                    const struct sctp_association *asoc, struct sctp_chunk *chunk,
                    int gfp, int *error, struct sctp_chunk **err_chk_p) { return NULL; }
static inline void sctp_send_stale_cookie_err(struct net *net, const struct sctp_endpoint *ep,
                    const struct sctp_association *asoc, struct sctp_chunk *chunk,
                    sctp_cmd_seq_t *commands, struct sctp_chunk *err_chk_p) {}
static inline int sctp_process_init(struct sctp_association *asoc, struct sctp_chunk *chunk,
                    void *peer_addr, sctp_init_chunk_t *init, int gfp) { return 1; }
static inline int sctp_auth_asoc_init_active_key(struct sctp_association *asoc, int gfp) { return 0; }
static inline void kfree_skb(struct sk_buff *skb) {}
static inline void sctp_association_free(struct sctp_association *asoc) {}
static inline void *skb_push(struct sk_buff *skb, unsigned int len) { return NULL; }
static inline void skb_pull(struct sk_buff *skb, unsigned int len) {}
static inline sctp_ierror_t sctp_sf_authenticate(struct net *net, const struct sctp_endpoint *ep,
                    struct sctp_association *asoc, sctp_subtype_t type, struct sctp_chunk *auth) { return 0; }
static inline struct sctp_chunk *sctp_make_cookie_ack(struct sctp_association *asoc, struct sctp_chunk *chunk) { return NULL; }
static inline struct sctp_ulpevent *sctp_ulpevent_make_assoc_change(struct sctp_association *asoc,
                    int flags, int state, int error, int out, int in, void *data, int gfp) { return NULL; }
static inline struct sctp_ulpevent *sctp_ulpevent_make_adaptation_indication(struct sctp_association *asoc, int gfp) { return NULL; }
static inline void sctp_add_cmd_sf(sctp_cmd_seq_t *commands, int cmd, void *arg) {}
static inline void *SCTP_ASOC(struct sctp_association *asoc) { return asoc; }
static inline void *SCTP_STATE(int state) { return (void *)(long)state; }
static inline void *SCTP_NULL() { return NULL; }
static inline void *SCTP_TO(int timeout) { return (void *)(long)timeout; }
static inline void *SCTP_CHUNK(struct sctp_chunk *chunk) { return chunk; }
static inline void *SCTP_ULPEVENT(struct sctp_ulpevent *event) { return event; }
static inline void sctp_ulpevent_free(struct sctp_ulpevent *ev) {}
static inline void sctp_chunk_free(struct sctp_chunk *chunk) {}