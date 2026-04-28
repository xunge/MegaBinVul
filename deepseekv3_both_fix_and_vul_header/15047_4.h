#include <errno.h>
#include <stdint.h>
#include <string.h>

#define __user
#define UDP 1

struct sock;
struct sctp_association;
struct sctp_endpoint {
    void *ep;
};
struct sctp_sock {
    struct sctp_endpoint *ep;
};
struct sctp_authkeyid {
    uint16_t scact_assoc_id;
    uint16_t scact_keynumber;
};

extern int sctp_auth_enable;
extern int copy_from_user(void *to, const void *from, unsigned long n);
extern struct sctp_association *sctp_id2assoc(struct sock *sk, uint16_t assoc_id);
extern int sctp_style(struct sock *sk, int style);
extern int sctp_auth_del_key_id(struct sctp_endpoint *ep, struct sctp_association *asoc, uint16_t keynumber);
extern struct sctp_sock *sctp_sk(struct sock *sk);