#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <errno.h>
#include <linux/if_arp.h>

#define MSG_CMSG_COMPAT 0
#define EINVAL 22
#define ENETDOWN 100
#define EMSGSIZE 90
#define EPROTOTYPE 91
#define IFF_UP 0x1

struct sockaddr_ec {
    unsigned short sec_family;
    unsigned char port;
    unsigned char cb;
    struct {
        unsigned char station;
        unsigned char net;
    } addr;
    unsigned long cookie;
};

struct ec_addr {
    unsigned char station;
    unsigned char net;
};

struct ec_cb {
    unsigned long cookie;
    struct sockaddr_ec sec;
    void (*sent)(void *);
    unsigned long timeout;
    unsigned long start;
    unsigned long seq;
};

struct ec_framehdr {
    unsigned char cb;
    unsigned char port;
};

struct aunhdr {
    unsigned char port;
    unsigned char cb;
    unsigned char code;
    unsigned char pad;
    unsigned long handle;
};

struct net_device {
    unsigned short type;
    unsigned int mtu;
    unsigned int flags;
};

struct socket {
    void *sk;
    int type;
};

struct sock {
    unsigned int sk_priority;
};

struct sk_buff {
    void *data;
    void *dev;
    unsigned short protocol;
    unsigned int priority;
    unsigned int len;
    char cb[48];
};

extern pthread_mutex_t econet_mutex;
extern struct net_device *net2dev_map[];
extern struct socket *udpsock;
extern unsigned long aun_seq;
extern struct sk_buff_head aun_queue;