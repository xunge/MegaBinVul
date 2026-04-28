#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

typedef uint32_t __u32;
typedef uint16_t __u16;
typedef uint8_t __u8;
typedef unsigned int gfp_t;
typedef unsigned long jiffies_t;

#define GFP_KERNEL 0
#define SCTP_SIGNATURE_SIZE 20
#define SCTP_AUTH_NUM_HMACS 1
#define SCTP_NUM_CHUNK_TYPES 256
#define SCTP_SECRET_SIZE 32
#define SCTP_PARAM_HMAC_ALGO 1
#define SCTP_PARAM_CHUNKS 2
#define SCTP_AUTH_HMAC_ID_SHA1 1
#define SCTP_CID_ASCONF 1
#define SCTP_CID_ASCONF_ACK 2
#define SCTP_EP_TYPE_SOCKET 1
#define SOCK_USE_WRITE_QUEUE (1<<0)

struct sock {
    void (*sk_write_space)(struct sock *sk);
};

struct list_head {
    struct list_head *next, *prev;
};

struct sctp_paramhdr {
    __u16 type;
    __u16 length;
};

typedef struct sctp_paramhdr sctp_paramhdr_t;
typedef struct sctp_hmac_algo_param sctp_hmac_algo_param_t;
typedef struct sctp_chunks_param sctp_chunks_param_t;

struct sctp_hmac_algo_param {
    struct sctp_paramhdr param_hdr;
    __u16 hmac_ids[];
};

struct sctp_chunks_param {
    struct sctp_paramhdr param_hdr;
    __u8 chunks[];
};

struct sctp_shared_key {
    struct list_head key_list;
    __u16 key_id;
};

struct sctp_ep_common {
    int type;
    int refcnt;
    int dead;
    int malloced;
    struct sock *sk;
    struct list_head inqueue;
    struct list_head bind_addr;
};

struct sctp_endpoint {
    struct sctp_ep_common base;
    struct list_head asocs;
    void *digest;
    struct sctp_hmac_algo_param *auth_hmacs_list;
    struct sctp_chunks_param *auth_chunk_list;
    unsigned int sndbuf_policy;
    unsigned int rcvbuf_policy;
    __u8 secret_key[SCTP_SECRET_SIZE];
    __u32 last_key;
    __u32 current_key;
    jiffies_t key_changed_at;
    struct list_head endpoint_shared_keys;
};

extern int sctp_auth_enable;
extern int sctp_addip_enable;
extern unsigned int sctp_sndbuf_policy;
extern unsigned int sctp_rcvbuf_policy;
extern jiffies_t jiffies;

static inline __u16 htons(__u16 val) {
    return ((val >> 8) & 0xff) | ((val & 0xff) << 8);
}

static inline void *kzalloc(size_t size, gfp_t flags) {
    return calloc(1, size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}

static inline void atomic_set(int *v, int i) {
    *v = i;
}

static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

static inline void list_add(struct list_head *new, struct list_head *head) {
    new->next = head->next;
    new->prev = head;
    head->next->prev = new;
    head->next = new;
}

static inline void sock_hold(struct sock *sk) {
}

static inline void sock_set_flag(struct sock *sk, int flag) {
}

static inline void get_random_bytes(void *buf, int nbytes) {
    srand(time(NULL));
    for (int i = 0; i < nbytes; i++) {
        ((unsigned char *)buf)[i] = rand() % 256;
    }
}

static inline void sctp_inq_init(struct list_head *queue) {
    INIT_LIST_HEAD(queue);
}

static inline void sctp_inq_set_th_handler(struct list_head *queue, void (*handler)(void)) {
}

static inline void sctp_bind_addr_init(struct list_head *bind_addr, int flags) {
    INIT_LIST_HEAD(bind_addr);
}

static inline void sctp_write_space(struct sock *sk) {
}

static inline struct sctp_shared_key *sctp_auth_shkey_create(__u16 key_id, gfp_t gfp) {
    return kzalloc(sizeof(struct sctp_shared_key), gfp);
}

static inline int sctp_auth_init_hmacs(struct sctp_endpoint *ep, gfp_t gfp) {
    return 0;
}

static inline void sctp_auth_destroy_keys(struct list_head *keys) {
}

static inline void sctp_endpoint_bh_rcv(void) {
}