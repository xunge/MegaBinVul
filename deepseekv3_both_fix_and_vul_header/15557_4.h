#include <sys/ioctl.h>
#include <unistd.h>
#include <errno.h>

#define __user
#define SIOCGIFADDR 0x8915
#define SIOCSIFADDR 0x8916
#define SIOCGIFDSTADDR 0x8917
#define SIOCSIFDSTADDR 0x8918
#define SIOCGIFBRDADDR 0x8919
#define SIOCSIFBRDADDR 0x891a
#define SIOCGIFNETMASK 0x891b
#define SIOCSIFNETMASK 0x891c
#define SIOCGIFMETRIC 0x891d
#define SIOCSIFMETRIC 0x891e
#define SIOCADDRT 0x890B
#define SIOCDELRT 0x890C
#define SIOCRSCLRRT 0x890D
#define SIOCRSGCAUSE 0x890E
#define SIOCRSSCAUSE 0x890F
#define SIOCRSSL2CALL 0x8910
#define SIOCRSGL2CALL 0x8911
#define SIOCRSACCEPT 0x8912
#define CAP_NET_ADMIN 12
#define EINVAL 22
#define EPERM 1
#define EFAULT 14
#define ENOIOCTLCMD 515
#define ROSE_STATE_3 3
#define ROSE_STATE_5 5
#define ROSE_CALL_ACCEPTED 0x0F

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_sndbuf;
    struct {
        void *lock;
    } sk_receive_queue;
};

struct sk_buff {
    unsigned int len;
};

struct rose_sock {
    unsigned int cause;
    unsigned int diagnostic;
    int state;
    int condition;
    int vs;
    int va;
    int vr;
    int vl;
};

struct rose_cause_struct {
    unsigned int cause;
    unsigned int diagnostic;
};

typedef struct {
    char ax25_call[7];
} ax25_address;

static ax25_address rose_callsign;
static ax25_address null_ax25_address;

extern struct rose_sock *rose_sk(struct sock *sk);
extern int rose_rt_ioctl(unsigned int cmd, void *argp);
extern int ax25_listen_release(ax25_address *callsign, void *);
extern int ax25_listen_register(ax25_address *callsign, void *);
extern int ax25cmp(ax25_address *, ax25_address *);
extern void rose_write_internal(struct sock *sk, int frametype);
extern void rose_start_idletimer(struct sock *sk);
extern int sk_wmem_alloc_get(struct sock *sk);
extern void spin_lock_irq(void *lock);
extern void spin_unlock_irq(void *lock);
extern struct sk_buff *skb_peek(void *queue);
extern long copy_to_user(void *to, const void *from, unsigned long n);
extern long copy_from_user(void *to, const void *from, unsigned long n);
extern int put_user(long x, void *ptr);
extern int capable(int cap);