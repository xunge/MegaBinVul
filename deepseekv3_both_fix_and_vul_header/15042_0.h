#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define GFP_KERNEL 0
#define __user
#define EINVAL 22
#define ENOMEM 12  
#define EFAULT 14
#define EACCES 13
#define SCTP_AUTH_NUM_HMACS 10

struct sock;
struct sctp_sock {
    struct sctp_endpoint *ep;
};

struct sctp_hmacalgo {
    int shmac_num_idents;
};

struct sctp_endpoint;

static int sctp_auth_enable = 1;

static inline struct sctp_sock *sctp_sk(struct sock *sk) { return (struct sctp_sock *)sk; }
static int sctp_auth_ep_set_hmacs(struct sctp_endpoint *ep, struct sctp_hmacalgo *hmacs) { return 0; }

static void *kmalloc(size_t size, int flags) { return malloc(size); }
static void kfree(void *ptr) { free(ptr); }
static int copy_from_user(void *to, const void __user *from, unsigned long n) { 
    memcpy(to, from, n); 
    return 0; 
}