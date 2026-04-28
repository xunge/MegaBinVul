#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>

typedef uint32_t __u32;
typedef uint16_t __u16;
typedef uint8_t __u8;
typedef int gfp_t;

struct sctp_association {
    struct {
        struct {
            void *bind_addr;
            void *sk;
        } base;
        struct {
            __u32 my_vtag;
            __u16 sinit_num_ostreams;
            __u16 sinit_max_instreams;
            __u32 initial_tsn;
            void *auth_random;
            void *auth_hmacs;
            void *auth_chunks;
        } c;
        void *ep;
        __u32 rwnd;
        struct {
            int ecn_capable;
            int prsctp_capable;
            int asconf_capable;
            int auth_capable;
        } peer;
    };
};

struct sctp_chunk {
    void *transport;
    struct {
        void *init_hdr;
    } subh;
    union {
        void *v;
    } param_hdr;
    struct sctp_association *asoc;
};

struct sctp_sock {
    __u32 adaptation_ind;
};

union sctp_params {
    void *v;
    struct {
        __u16 type;
        __u16 length;
    } *p;
};

typedef struct {
    __u32 init_tag;
    __u32 a_rwnd;
    __u16 num_outbound_streams;
    __u16 num_inbound_streams;
    __u32 initial_tsn;
} sctp_inithdr_t;

typedef struct {
    __u16 type;
    __u16 length;
} sctp_paramhdr_t;

typedef struct {
    sctp_paramhdr_t param_hdr;
    __u32 adaptation_ind;
} sctp_adaptation_ind_param_t;

typedef struct {
    sctp_paramhdr_t param_hdr;
    __u8 chunks[];
} sctp_supported_ext_param_t;

typedef struct {
    sctp_paramhdr_t param_hdr;
    __u8 body[];
} sctp_cookie_param_t;

#define SCTP_CID_INIT_ACK         2
#define SCTP_CID_ASCONF           0xC1
#define SCTP_CID_ASCONF_ACK       0x80
#define SCTP_CID_AUTH             0x0F

#define SCTP_PARAM_SUPPORTED_EXT          0x8008
#define SCTP_PARAM_ADAPTATION_LAYER_IND   0xC006

static sctp_paramhdr_t ecap_param;
static sctp_paramhdr_t prsctp_param;

static inline struct sctp_sock *sctp_sk(void *sk)
{
    return (struct sctp_sock *)sk;
}

extern union sctp_params sctp_bind_addrs_to_raw(const void *, int *, gfp_t);
extern sctp_cookie_param_t *sctp_pack_cookie(void *, const struct sctp_association *, const struct sctp_chunk *, int *, void *, int);
extern struct sctp_chunk *sctp_make_chunk(const struct sctp_association *, __u8, __u8, size_t);
extern void *sctp_addto_chunk(struct sctp_chunk *, size_t, const void *);
extern void sctp_addto_param(struct sctp_chunk *, int, const __u8 *);