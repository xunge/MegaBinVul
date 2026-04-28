#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>

#define ROSE_MAX_DIGIS 8
#define SOCK_ZAPPED 0x00000001
#define CAP_NET_BIND_SERVICE 0
#define EINVAL 22
#define EADDRNOTAVAIL 99
#define EACCES 13

typedef struct {
    unsigned char ax25_call[7];
} ax25_address;

typedef struct {
    unsigned char rose_addr[5];
} rose_address;

typedef struct {
    ax25_address call;
} ax25_uid_assoc;

struct sockaddr_rose {
    unsigned short srose_family;
    unsigned char srose_ndigis;
    ax25_address srose_call;
    rose_address srose_addr;
    ax25_address srose_digi;
};

struct full_sockaddr_rose {
    unsigned short srose_family;
    unsigned char srose_ndigis;
    ax25_address srose_call;
    rose_address srose_addr;
    ax25_address srose_digis[ROSE_MAX_DIGIS];
};

struct socket {
    struct sock *sk;
};

struct sock {
    unsigned long flags;
};

struct net_device;

struct rose_sock {
    struct sock sk;
    ax25_address source_call;
    rose_address source_addr;
    struct net_device *device;
    unsigned char source_ndigis;
    ax25_address source_digis[ROSE_MAX_DIGIS];
};

static inline int sock_flag(struct sock *sk, int flag) { return sk->flags & flag; }
static inline void sock_reset_flag(struct sock *sk, int flag) { sk->flags &= ~flag; }
#define SOCK_DEBUG(sk, fmt) do {} while(0)
#define capable(cap) (1)
#define current_euid() (0)

static struct net_device *rose_dev_get(rose_address *addr) { return 0; }
static ax25_uid_assoc *ax25_findbyuid(uid_t uid) { return 0; }
static void ax25_uid_put(ax25_uid_assoc *user) {}
static void rose_insert_socket(struct sock *sk) {}

extern int ax25_uid_policy;

#define rose_sk(sk) ((struct rose_sock *)(sk))