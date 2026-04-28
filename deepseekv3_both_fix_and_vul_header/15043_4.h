#include <stdint.h>
#include <errno.h>
#include <string.h>

typedef uint16_t __u16;
typedef uint16_t u16;
typedef uint32_t u32;

struct sock;

typedef struct {
    __u16 length;
} sctp_paramhdr_t;

struct sctp_hmac_algo_param {
    sctp_paramhdr_t param_hdr;
    __u16 hmac_ids[];
};

struct sctp_hmacalgo {
    u32 shmac_num_idents;
    __u16 shmac_idents[];
};

#define ntohs(x) (x)
#define __user
#define EINVAL 22
#define EFAULT 14
#define EACCES 13

static int sctp_auth_enable = 1;

static inline int put_user(int val, int *addr) {
    *addr = val;
    return 0;
}

static inline int copy_to_user(void *dst, const void *src, size_t len) {
    memcpy(dst, src, len);
    return 0;
}

struct sctp_sock;
static inline struct sctp_sock *sctp_sk(struct sock *sk) {
    return (struct sctp_sock *)sk;
}

struct sctp_sock {
    struct {
        struct sctp_hmac_algo_param *auth_hmacs_list;
    } *ep;
};