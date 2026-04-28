#include <stdint.h>

#define __user
#define __be16 uint16_t
#define ntohs(x) (x)
#define sctp_paramhdr_t struct sctp_paramhdr

typedef uint32_t u32;

struct sctp_authchunks {
    u32 gauth_assoc_id;
    u32 gauth_number_of_chunks;
    char gauth_chunks[0];
};

struct sctp_paramhdr {
    __be16 length;
    __be16 type;
};

struct sctp_chunks_param {
    struct sctp_paramhdr param_hdr;
    uint8_t chunks[0];
};

struct sctp_association {
    struct {
        struct sctp_chunks_param *auth_chunks;
    } c;
};

struct sctp_sock;
struct sock;

int sctp_auth_enable;
struct sctp_association *sctp_id2assoc(struct sock *sk, u32 assoc_id);
struct sctp_sock *sctp_sk(struct sock *sk);
int sctp_style(struct sock *sk, int style);

struct sctp_sock {
    struct {
        struct sctp_chunks_param *auth_chunk_list;
    } *ep;
};

#define EACCES 13
#define EINVAL 22
#define EFAULT 14

static inline int copy_from_user(void *to, const void __user *from, unsigned long n) { return 0; }
static inline int copy_to_user(void __user *to, const void *from, unsigned long n) { return 0; }
static inline int put_user(int x, void __user *ptr) { return 0; }

#define UDP 0