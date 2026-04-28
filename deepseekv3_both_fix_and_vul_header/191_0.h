#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t ipsec_spi_t;
typedef uint32_t v2_notification_t;

enum ikev2_sec_proto_id {
    IKEV2_SEC_PROTO_RESERVED = 0,
    IKEV2_SEC_PROTO_IKE = 1,
    IKEV2_SEC_PROTO_AH = 2,
    IKEV2_SEC_PROTO_ESP = 3
};

enum isakmp_xchg_types {
    ISAKMP_v2_IKE_SA_INIT = 34,
    ISAKMP_v2_IKE_AUTH = 35,
    ISAKMP_v2_CREATE_CHILD_SA = 36,
    ISAKMP_v2_INFORMATIONAL = 37
};

enum v2_notification_types {
    v2N_INVALID_SELECTORS = 42,
    v2N_REKEY_SA = 44
};

enum message_role_t {
    MESSAGE_REQUEST = 0,
    MESSAGE_RESPONSE = 1
};

typedef enum {
    STF_OK = 0,
    STF_FAIL = 1
} stf_status;

#define MIN_OUTPUT_UDP_SIZE 1280
#define IS_IKE_SA_ESTABLISHED(st) (1)
#define RC_LOG_SERIOUS 1

typedef struct chunk_t {
    uint8_t *ptr;
    size_t len;
} chunk_t;

typedef struct ipstr_buf {
    char buf[64];
} ipstr_buf;

typedef struct sa_state {
    void *st_remoteaddr;
    uint16_t st_remoteport;
} sa_state;

typedef struct ike_sa {
    sa_state sa;
} ike_sa;

typedef struct isakmp_hdr {
    uint32_t isa_msgid;
    enum isakmp_xchg_types isa_xchg;
} isakmp_hdr;

typedef struct msg_digest {
    isakmp_hdr hdr;
    sa_state st;
} msg_digest;

typedef struct pb_stream {
    uint8_t *cur;
    uint8_t *end;
} pb_stream;

typedef struct v2SK_payload_t {
    pb_stream pbs;
} v2SK_payload_t;

extern const void *ikev2_notify_names;
extern const void *ikev2_exchange_names;
extern int ikev2_sent_notifies_e;

extern const char *enum_short_name(const void *names, int value);
extern void libreswan_log(const char *format, ...);
extern void passert(bool condition);
extern void PEXPECT_LOG(const char *format, ...);
extern void loglog(int level, const char *format, ...);
extern enum message_role_t v2_msg_role(struct msg_digest *md);
extern struct pb_stream open_out_pbs(const char *name, uint8_t *buf, size_t size);
extern struct pb_stream open_v2_message(struct pb_stream *reply, struct ike_sa *ike, struct msg_digest *md, enum isakmp_xchg_types exchange_type);
extern bool pbs_ok(const struct pb_stream *pbs);
extern struct v2SK_payload_t open_v2SK_payload(struct pb_stream *pbs, struct ike_sa *ike);
extern bool emit_v2Nsa_pl(v2_notification_t ntype, enum ikev2_sec_proto_id protoid, ipsec_spi_t *spi, struct pb_stream *pbs, struct pb_stream *n_pbs);
extern bool out_chunk(struct chunk_t chunk, struct pb_stream *pbs, const char *name);
extern void close_output_pbs(struct pb_stream *pbs);
extern bool close_v2SK_payload(struct v2SK_payload_t *sk);
extern stf_status encrypt_v2SK_payload(struct v2SK_payload_t *sk);
extern void send_chunk_using_state(struct sa_state *sa, const char *name, struct chunk_t chunk);
extern void pstat(int stat, v2_notification_t ntype);
extern const char *sensitive_ipstr(void *addr, struct ipstr_buf *buf);
extern struct chunk_t same_out_pbs_as_chunk(struct pb_stream *pbs);