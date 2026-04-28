#include <errno.h>
#include <string.h>

struct sock;
struct sctp_sk {
    void *ep;
};
struct sctp_authchunk {
    int sauth_chunk;
};

#define SCTP_CID_INIT 0
#define SCTP_CID_INIT_ACK 1
#define SCTP_CID_SHUTDOWN_COMPLETE 2
#define SCTP_CID_AUTH 3

#define EACCES 13
#define EINVAL 22
#define EFAULT 14

extern int sctp_auth_enable;
extern struct sctp_sk *sctp_sk(struct sock *sk);
extern int sctp_auth_ep_add_chunkid(void *ep, int chunk);

static inline int copy_from_user(void *to, const void *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}

#define __user