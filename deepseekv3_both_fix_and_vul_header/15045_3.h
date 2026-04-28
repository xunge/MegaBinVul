#include <stdint.h>
#include <string.h>

struct sock;
struct sctp_association;
struct sctp_sock {
    void *ep;
};
struct sctp_authkeyid {
    uint16_t scact_assoc_id;
    uint16_t scact_keynumber;
};

extern int sctp_auth_enable;
extern struct sctp_association *sctp_id2assoc(struct sock *sk, uint16_t assoc_id);
extern int sctp_style(struct sock *sk, int style);
extern int sctp_auth_set_active_key(void *ep, struct sctp_association *asoc, uint16_t keynumber);
extern struct sctp_sock *sctp_sk(struct sock *sk);

#define EACCES 13
#define EINVAL 22
#define EFAULT 14
#define UDP 1

#define __user
#define copy_from_user(dst, src, len) memcpy(dst, src, len)