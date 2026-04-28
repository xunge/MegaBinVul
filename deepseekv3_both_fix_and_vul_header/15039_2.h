#include <stdint.h>

#define __user
#define EACCES 13
#define EINVAL 22
#define EFAULT 14
#define UDP 1

struct sctp_authkeyid {
    uint16_t scact_assoc_id;
    uint16_t scact_keynumber;
};

struct sctp_association {
    uint16_t active_key_id;
};

struct sctp_sock {
    struct {
        uint16_t active_key_id;
    } *ep;
};

struct sock;

extern int sctp_auth_enable;
extern int copy_from_user(void *, const void *, unsigned long);
extern int copy_to_user(void *, const void *, unsigned long);
extern int put_user(int, int *);
extern struct sctp_association *sctp_id2assoc(struct sock *sk, uint16_t assoc_id);
extern int sctp_style(struct sock *sk, int style);
extern struct sctp_sock *sctp_sk(struct sock *sk);