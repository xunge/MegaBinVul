#include <stdlib.h>
#include <string.h>

#define GFP_KERNEL 0
#define EACCES 13
#define EINVAL 22
#define ENOMEM 12
#define EFAULT 14
#define UDP 1

struct sock;
struct sctp_authkey {
    int sca_assoc_id;
};
struct sctp_association;
struct sctp_sock {
    struct sctp_endpoint *ep;
};
struct sctp_endpoint;

int sctp_auth_enable;

#define kmalloc(size, flags) malloc(size)
#define kfree(ptr) free(ptr)
#define copy_from_user(to, from, size) memcpy(to, from, size)

struct sctp_association *sctp_id2assoc(struct sock *sk, int assoc_id);
int sctp_style(struct sock *sk, int type);
struct sctp_sock *sctp_sk(struct sock *sk);
int sctp_auth_set_key(struct sctp_endpoint *ep, struct sctp_association *asoc, struct sctp_authkey *authkey);

#define __user