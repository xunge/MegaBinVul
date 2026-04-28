#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <stdarg.h>

#define MAX_DFRAME_LEN_L1 1024
#define L1OIP_VERSION 1
#define L1OIP_KEEPALIVE 10
#define DEBUG_L1OIP_MSG 1
#define HZ 100
#define KERN_DEBUG ""

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct timer_list {
    time_t expires;
};

struct socket {
    int dummy;
};

struct l1oip {
    struct timer_list keep_tl;
    int shutdown;
    struct sockaddr_in sin_remote;
    pthread_spinlock_t socket_lock;
    struct socket *socket;
    int pri;
    u32 id;
    struct {
        int codecstate;
    } chan[32];
    struct iovec sendiov;
    struct msghdr sendmsg;
};

static int debug;
static int ulaw;
static unsigned long jiffies;

static int time_before(time_t a, time_t b) { return a < b; }
static void mod_timer(struct timer_list *timer, time_t expires) { timer->expires = expires; }
static void spin_lock(pthread_spinlock_t *lock) { pthread_spin_lock(lock); }
static void spin_unlock(pthread_spinlock_t *lock) { pthread_spin_unlock(lock); }
static int printk(const char *fmt, ...) { 
    va_list args;
    va_start(args, fmt);
    int ret = vprintf(fmt, args);
    va_end(args);
    return ret;
}
static int kernel_sendmsg(struct socket *sock, struct msghdr *msg, struct iovec *iov, int iov_len, int len) { return 0; }
static void l1oip_ulaw_to_alaw(u8 *src, int len, u8 *dst) {}
static void l1oip_alaw_to_ulaw(u8 *src, int len, u8 *dst) {}
static int l1oip_law_to_4bit(u8 *src, int len, u8 *dst, int *state) { return 0; }