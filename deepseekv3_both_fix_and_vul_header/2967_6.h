#include <sys/socket.h>
#include <sys/uio.h>
#include <errno.h>
#include <stddef.h>

#define TCP_ESTABLISHED 1
#define ENOTCONN 107
#define ROSE_Q_BIT 0x01
#define ROSE_MIN_LEN 1

struct kiocb;
struct socket {
    struct sock *sk;
};
struct sock {
    int sk_state;
};
struct rose_sock {
    int qbitincl;
    unsigned int dest_addr;
    unsigned int dest_call;
    unsigned int dest_ndigis;
    unsigned int dest_digis[8];
};
struct sockaddr_rose {
    unsigned short srose_family;
    unsigned int srose_addr;
    unsigned int srose_call;
    unsigned int srose_ndigis;
    unsigned int srose_digi;
};
struct full_sockaddr_rose {
    unsigned short srose_family;
    unsigned int srose_addr;
    unsigned int srose_call;
    unsigned int srose_ndigis;
    unsigned int srose_digis[8];
};
struct sk_buff {
    unsigned char *data;
    unsigned int len;
};