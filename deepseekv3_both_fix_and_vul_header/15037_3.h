#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct sock;
struct sctp_authkey {
    int sca_keylength;
    int sca_assoc_id;
};
struct sctp_association;
struct sctp_sock {
    void *ep;
};

extern int sctp_auth_enable;
extern void *kmalloc(size_t size, int flags);
extern void kfree(void *ptr);
extern int copy_from_user(void *to, const void *from, unsigned long n);
extern struct sctp_association *sctp_id2assoc(struct sock *sk, int id);
extern int sctp_style(struct sock *sk, int type);
extern int sctp_auth_set_key(void *ep, struct sctp_association *asoc, struct sctp_authkey *authkey);
extern struct sctp_sock *sctp_sk(struct sock *sk);

#define GFP_KERNEL 0
#define EACCES 13
#define EINVAL 22
#define ENOMEM 12
#define EFAULT 14
#define UDP 0

typedef char user_char;
#define __user