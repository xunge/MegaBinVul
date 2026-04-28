#include <stdint.h>
#include <netinet/in.h>
#include <stddef.h>
#include <stdio.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

#define DEBUG_L1OIP_MSG   0x01
#define DEBUG_L1OIP_SOCKET 0x02
#define L1OIP_VERSION 1
#define L1OIP_TIMEOUT 10
#define GFP_ATOMIC 0
#define KERN_DEBUG ""
#define KERN_WARNING ""
#define HZ 100
#define jiffies 0

struct timer_list {
    unsigned long expires;
};

struct l1oip {
    struct sockaddr_in sin_remote;
    struct timer_list timeout_tl;
    int timeout_on;
    int shutdown;
    u32 id;
    int pri;
    int d_idx;
    struct {
        struct dchannel *dch;
    } *chan;
};

struct dchannel {
    unsigned long Flags;
    struct {
        void *D;
    } dev;
};

#define FLG_ACTIVE 0
#define PH_ACTIVATE_IND 1
#define MISDN_ID_ANY 0

extern int debug;
extern void l1oip_socket_recv(struct l1oip *hc, u8 remotecodec, u8 channel, u16 timebase, u8 *buf, int len);
extern void _queue_data(void *q, int prim, int id, int len, void *arg, int gfp);
extern int test_bit(int nr, const volatile unsigned long *addr);
extern void test_and_set_bit(int nr, volatile unsigned long *addr);
extern int time_before(unsigned long a, unsigned long b);
extern void mod_timer(struct timer_list *timer, unsigned long expires);
extern int printk(const char *fmt, ...);