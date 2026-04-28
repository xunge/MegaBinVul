#include <stdint.h>
#include <stdlib.h>

#define GFP_KERNEL 0
#define EACCES 13
#define EINVAL 22
#define ENOMEM 12
#define EFAULT 14
#define SCTP_AUTH_NUM_HMACS 32

typedef uint32_t u32;
typedef uint16_t u16;

struct sctp_hmacalgo {
    u32 shmac_num_idents;
    u16 shmac_idents[];
};

struct sock;
struct sctp_endpoint;

struct sctp_sock {
    struct sctp_endpoint *ep;
};

extern int sctp_auth_enable;
extern void *kmalloc(size_t size, int flags);
extern void kfree(void *ptr);
extern int copy_from_user(void *to, const void *from, unsigned long n);
extern int sctp_auth_ep_set_hmacs(struct sctp_endpoint *ep, struct sctp_hmacalgo *hmacs);
extern struct sctp_sock *sctp_sk(struct sock *sk);

#define __user