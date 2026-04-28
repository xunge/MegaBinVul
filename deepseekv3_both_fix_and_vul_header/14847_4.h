#include <stddef.h>
#include <stdint.h>

typedef int sctp_disposition_t;
typedef int sctp_subtype_t;
typedef int sctp_cmd_seq_t;
#define GFP_ATOMIC 0

struct sctp_endpoint;
struct sctp_association;

typedef struct sctp_chunkhdr sctp_chunkhdr_t;

struct sctp_chunkhdr {
    uint16_t length;
};

struct sctp_signed_cookie;

struct sk_buff {
    unsigned char *data;
};

struct sctp_chunk {
    struct sk_buff *skb;
    struct sctp_chunkhdr *chunk_hdr;
    struct {
        struct sctp_signed_cookie *cookie_hdr;
    } subh;
};

#define ntohs(x) (x)
#define SCTP_IERROR_NOMEM 1
#define SCTP_IERROR_STALE_COOKIE 2
#define SCTP_IERROR_BAD_SIG 3
#define SCTP_DISPOSITION_NOMEM (-1)

static inline void skb_pull(struct sk_buff *skb, unsigned int len) {
    skb->data += len;
}

static inline int sctp_chunk_length_valid(struct sctp_chunk *chunk, size_t len) {
    return 1;
}

static inline sctp_disposition_t sctp_sf_violation_chunklen(const struct sctp_endpoint *ep,
                                                          const struct sctp_association *asoc,
                                                          sctp_subtype_t type,
                                                          void *arg,
                                                          sctp_cmd_seq_t *commands) {
    return 0;
}

static inline struct sctp_association *sctp_unpack_cookie(const struct sctp_endpoint *ep,
                                                        const struct sctp_association *asoc,
                                                        struct sctp_chunk *chunk,
                                                        int gfp,
                                                        int *error,
                                                        struct sctp_chunk **err_chk_p) {
    return NULL;
}

static inline void sctp_send_stale_cookie_err(const struct sctp_endpoint *ep,
                                            const struct sctp_association *asoc,
                                            struct sctp_chunk *chunk,
                                            sctp_cmd_seq_t *commands,
                                            struct sctp_chunk *err_chk_p) {}

static inline sctp_disposition_t sctp_sf_pdiscard(const struct sctp_endpoint *ep,
                                                const struct sctp_association *asoc,
                                                sctp_subtype_t type,
                                                void *arg,
                                                sctp_cmd_seq_t *commands) {
    return 0;
}

static inline char sctp_tietags_compare(struct sctp_association *new_asoc,
                                      const struct sctp_association *asoc) {
    return 0;
}

static inline sctp_disposition_t sctp_sf_do_dupcook_a(const struct sctp_endpoint *ep,
                                                     const struct sctp_association *asoc,
                                                     struct sctp_chunk *chunk,
                                                     sctp_cmd_seq_t *commands,
                                                     struct sctp_association *new_asoc) {
    return 0;
}

static inline sctp_disposition_t sctp_sf_do_dupcook_b(const struct sctp_endpoint *ep,
                                                     const struct sctp_association *asoc,
                                                     struct sctp_chunk *chunk,
                                                     sctp_cmd_seq_t *commands,
                                                     struct sctp_association *new_asoc) {
    return 0;
}

static inline sctp_disposition_t sctp_sf_do_dupcook_c(const struct sctp_endpoint *ep,
                                                     const struct sctp_association *asoc,
                                                     struct sctp_chunk *chunk,
                                                     sctp_cmd_seq_t *commands,
                                                     struct sctp_association *new_asoc) {
    return 0;
}

static inline sctp_disposition_t sctp_sf_do_dupcook_d(const struct sctp_endpoint *ep,
                                                     const struct sctp_association *asoc,
                                                     struct sctp_chunk *chunk,
                                                     sctp_cmd_seq_t *commands,
                                                     struct sctp_association *new_asoc) {
    return 0;
}

static inline void sctp_add_cmd_sf(sctp_cmd_seq_t *commands, int cmd, int arg) {}

#define SCTP_CMD_NEW_ASOC 0
#define SCTP_ASOC(x) (0)
#define SCTP_CMD_DELETE_TCB 1
#define SCTP_NULL() (0)