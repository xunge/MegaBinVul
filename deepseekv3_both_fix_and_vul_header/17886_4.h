#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
#include <netinet/in.h>

typedef uint32_t __u32;
typedef uint16_t __u16;
typedef uint8_t __u8;
typedef __u32 __be32;
typedef __u16 __be16;

typedef int gfp_t;

struct sctp_paramhdr {
    __be16 type;
    __be16 length;
};
typedef struct sctp_paramhdr sctp_paramhdr_t;

struct sctp_inithdr {
    __be32 init_tag;
    __be32 a_rwnd;
    __be16 num_outbound_streams;
    __be16 num_inbound_streams;
    __be32 initial_tsn;
};
typedef struct sctp_inithdr sctp_inithdr_t;

struct sctp_supported_addrs_param {
    sctp_paramhdr_t param_hdr;
    __u16 types[0];
};
typedef struct sctp_supported_addrs_param sctp_supported_addrs_param_t;

struct sctp_adaptation_ind_param {
    sctp_paramhdr_t param_hdr;
    __u32 adaptation_ind;
};
typedef struct sctp_adaptation_ind_param sctp_adaptation_ind_param_t;

struct sctp_supported_ext_param {
    sctp_paramhdr_t param_hdr;
    __u8 chunks[0];
};
typedef struct sctp_supported_ext_param sctp_supported_ext_param_t;

union sctp_params {
    void *v;
    sctp_paramhdr_t *p;
};

struct sctp_chunk_subh {
    sctp_inithdr_t *init_hdr;
};

struct sctp_chunk {
    struct sctp_chunk_subh subh;
    union {
        void *v;
    } param_hdr;
};

struct sctp_assoc_c {
    __be32 my_vtag;
    __be16 sinit_num_ostreams;
    __be16 sinit_max_instreams;
    __be32 initial_tsn;
    __u8 auth_random[0];
    __u8 auth_hmacs[0];
    __u8 auth_chunks[0];
};

struct sctp_assoc_base {
    struct sock *sk;
};

struct sctp_association {
    struct sctp_assoc_c c;
    __be32 rwnd;
    struct sctp_assoc_base base;
};

struct sctp_pf {
    int (*supported_addrs)(struct sctp_sock *, __be16 *);
};

struct sctp_sock {
    struct sctp_pf *pf;
    __u32 adaptation_ind;
};

struct sctp_bind_addr;

#define SCTP_CID_INIT         1
#define SCTP_CID_ASCONF       0xC1
#define SCTP_CID_ASCONF_ACK   0x80
#define SCTP_CID_AUTH         0x0F

#define SCTP_PARAM_SUPPORTED_ADDRESS_TYPES  0xC000
#define SCTP_PARAM_ADAPTATION_LAYER_IND     0xC006
#define SCTP_PARAM_SUPPORTED_EXT            0x8008

#define SCTP_SAT_LEN(num_types) (sizeof(sctp_supported_addrs_param_t) + (num_types) * sizeof(__u16))

extern int sctp_prsctp_enable;
extern int sctp_addip_enable;
extern int sctp_auth_enable;

extern sctp_paramhdr_t ecap_param;
extern sctp_paramhdr_t prsctp_param;

static inline struct sctp_sock *sctp_sk(struct sock *sk) { return (struct sctp_sock *)sk; }
static inline void kfree(void *ptr) {}
static inline struct sctp_chunk *sctp_make_chunk(const struct sctp_association *asoc, __u8 type, __u8 flags, size_t len) { return 0; }
static inline void *sctp_addto_chunk(struct sctp_chunk *chunk, size_t len, const void *data) { return 0; }
static inline void sctp_addto_param(struct sctp_chunk *chunk, int len, const __u8 *data) {}
static inline union sctp_params sctp_bind_addrs_to_raw(const struct sctp_bind_addr *bp, int *len, gfp_t gfp) { union sctp_params p = {0}; return p; }