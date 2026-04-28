#include <string.h>
#include <stddef.h>

#define SOL_PACKET 263
#define PACKET_ADD_MEMBERSHIP 0
#define PACKET_DROP_MEMBERSHIP 1
#define PACKET_RX_RING 5
#define PACKET_TX_RING 6
#define PACKET_COPY_THRESH 12
#define PACKET_VERSION 10
#define PACKET_RESERVE 11
#define PACKET_LOSS 13
#define PACKET_AUXDATA 14
#define PACKET_ORIGDEV 15
#define PACKET_VNET_HDR 16
#define PACKET_TIMESTAMP 17
#define PACKET_FANOUT 18
#define PACKET_FANOUT_DATA 19
#define PACKET_TX_HAS_OFF 20
#define PACKET_QDISC_BYPASS 21

#define TPACKET_V1 0
#define TPACKET_V2 1
#define TPACKET_V3 2

#define SOCK_RAW 3
#define ENOPROTOOPT 92
#define EINVAL 22
#define EFAULT 14
#define EBUSY 16

struct socket {
    int type;
    struct sock *sk;
};

struct sock;
struct packet_sock {
    unsigned int tp_version;
    unsigned int tp_reserve;
    unsigned int tp_loss;
    unsigned int tp_tstamp;
    unsigned int tp_tx_has_off;
    int auxdata;
    int origdev;
    int has_vnet_hdr;
    int copy_thresh;
    void *fanout;
    struct {
        void *pg_vec;
    } rx_ring, tx_ring;
    void (*xmit)(void *);
};

struct packet_mreq_max {
    unsigned short mr_ifindex;
    unsigned short mr_type;
    unsigned short mr_alen;
    unsigned char mr_address[0];
};

struct packet_mreq {
    unsigned short mr_ifindex;
    unsigned short mr_type;
    unsigned short mr_alen;
    unsigned char mr_address[0];
};

union tpacket_req_u {
    struct {
        unsigned int tp_block_size;
        unsigned int tp_block_nr;
        unsigned int tp_frame_size;
        unsigned int tp_frame_nr;
    } req;
    struct {
        unsigned int tp_block_size;
        unsigned int tp_block_nr;
        unsigned int tp_frame_size;
        unsigned int tp_frame_nr;
    } req3;
};

#define __user

static inline struct packet_sock *pkt_sk(struct sock *sk) { return (struct packet_sock *)sk; }
static int packet_mc_add(struct sock *sk, struct packet_mreq_max *mreq) { return 0; }
static int packet_mc_drop(struct sock *sk, struct packet_mreq_max *mreq) { return 0; }
static int packet_set_ring(struct sock *sk, union tpacket_req_u *req_u, int flags, int tx_ring) { return 0; }
static int fanout_add(struct sock *sk, int id, int type) { return 0; }
static int fanout_set_data(struct packet_sock *po, char *optval, unsigned int optlen) { return 0; }
static int packet_direct_xmit(void *skb) { return 0; }
static int dev_queue_xmit(void *skb) { return 0; }
static int copy_from_user(void *to, const char *from, unsigned long n) { return 0; }