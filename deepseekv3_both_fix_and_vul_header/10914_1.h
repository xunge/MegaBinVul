#include <stdint.h>
#include <string.h>

#define SCTP_PARAM_BUFFER_SIZE 256
#define SCTP_RANDOM 0x8002
#define SCTP_HMAC_LIST 0x8004
#define SCTP_CHUNK_LIST 0x8006
#define SCTP_SIZE32(x) (((x) + 3) & ~3)

struct sctp_paramhdr {
    uint16_t param_type;
    uint16_t param_length;
};

struct sctp_auth_random {
    struct sctp_paramhdr ph;
    uint8_t random[1];
};

struct sctp_auth_hmac_algo {
    struct sctp_paramhdr ph;
    uint16_t hmac_ids[1];
};

struct sctp_auth_chunk_list {
    struct sctp_paramhdr ph;
    uint8_t chunk_types[1];
};

typedef struct sctp_key {
    uint8_t key[1];
} sctp_key_t;

struct sctp_tcb;
struct mbuf;

struct sctp_asoc {
    struct {
        sctp_key_t *random;
        uint16_t random_len;
        uint16_t assoc_keyid;
        uint16_t recv_keyid;
        uint16_t active_keyid;
    } authinfo;
    void *local_hmacs;
    void *peer_hmacs;
    uint16_t peer_hmac_id;
    void *local_auth_chunks;
    void *shared_keys;
};

struct sctp_ep {
    uint16_t default_keyid;
    void *shared_keys;
};

struct sctp_tcb {
    struct sctp_asoc asoc;
    struct {
        struct sctp_ep sctp_ep;
    } *sctp_ep;
};

uint16_t ntohs(uint16_t netshort);
void *sctp_m_getptr(struct mbuf *m, uint32_t offset, uint32_t len, uint8_t *buf);
void *sctp_get_next_param(struct mbuf *m, uint32_t offset, struct sctp_paramhdr *store, uint16_t len);
void sctp_free_hmaclist(void *list);
void *sctp_alloc_hmaclist(uint16_t num_hmacs);
int sctp_auth_add_hmacid(void *list, uint16_t id);
void sctp_clear_chunklist(void *list);
void *sctp_alloc_chunklist(void);
int sctp_auth_add_chunk(uint8_t type, void *list);
sctp_key_t *sctp_alloc_key(uint32_t keylen);
void sctp_free_key(sctp_key_t *key);
void sctp_clear_cachedkeys(struct sctp_tcb *stcb, uint16_t keyid);
uint16_t sctp_negotiate_hmacid(void *peer_hmacs, void *local_hmacs);
void sctp_copy_skeylist(void *src, void *dst);