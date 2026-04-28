#include <sys/socket.h>
#include <errno.h>
#include <stdint.h>

#define BT_OPEN 0
#define BT_BOUND 1
#define EINVAL 22
#define EBADFD 77

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_state;
    int sk_type;
};

struct sockaddr_sco {
    uint16_t sco_family;
    uint8_t sco_bdaddr[6];
};

struct sco_pinfo {
    uint8_t src[6];
};

#define BT_DBG(fmt, ...) 

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline void bacpy(uint8_t *dst, const uint8_t *src) {
    for(int i=0; i<6; i++) dst[i] = src[i];
}
static inline struct sco_pinfo* sco_pi(struct sock *sk) { 
    return (struct sco_pinfo*)sk; 
}