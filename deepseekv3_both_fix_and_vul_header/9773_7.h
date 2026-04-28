#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/time.h>
#include <stdint.h>

#define TCP_CA_NAME_MAX 16
#define MAX_TCP_WINDOW 65535
#define SOCK_MIN_RCVBUF 256
#define HZ 100
#define TCP_RTO_MAX (120*HZ)
#define TCP_TIMEOUT_INIT (1*HZ)
#define TCP_NAGLE_OFF 1
#define TCP_NAGLE_PUSH 4
#define TCP_NAGLE_CORK 2
#define SOCK_KEEPOPEN 1
#define TCPF_CLOSE (1 << 0)
#define TCPF_LISTEN (1 << 1)
#define TCPF_ESTABLISHED (1 << 2)
#define TCPF_CLOSE_WAIT (1 << 3)
#define ICSK_ACK_PUSHED 1
#define GFP_KERNEL 0
#define MAX_TCP_KEEPIDLE 32767
#define MAX_TCP_KEEPINTVL 32767
#define MAX_TCP_KEEPCNT 127
#define MAX_TCP_SYNCNT 6
#define TCP_MSS_DESIRED 1460
#define TCP_COOKIE_MAX 65535
#define TCP_COOKIE_MIN 0
#define TCP_COOKIE_IN_ALWAYS (1 << 0)
#define TCP_COOKIE_OUT_NEVER (1 << 1)
#define sysctl_tcp_cookie_size 0
#define sysctl_tcp_fin_timeout (60*HZ)

typedef uint32_t u32;
typedef char* user_ptr;

struct sock {
    int sk_state;
    void *af_specific;
};

struct tcp_sock {
    struct {
        int user_mss;
        int cookie_in_always;
        int cookie_out_never;
    } rx_opt;
    struct tcp_cookie_values *cookie_values;
    int nonagle;
    int thin_lto;
    int thin_dupack;
    int keepalive_time;
    int keepalive_intvl;
    int keepalive_probes;
    int linger2;
    int window_clamp;
};

struct inet_connection_sock {
    struct {
        struct {
            int pingpong;
            int pending;
        } icsk_ack;
        struct {
            int rskq_defer_accept;
        } icsk_accept_queue;
        int icsk_syn_retries;
        int icsk_user_timeout;
    };
};

struct tcp_cookie_values {
    int kref;
    unsigned short cookie_desired;
    unsigned char s_data_desired;
    unsigned char s_data_constant;
    unsigned char s_data_payload[0];
};

static inline struct tcp_sock *tcp_sk(const struct sock *sk) { return (struct tcp_sock *)sk; }
static inline struct inet_connection_sock *inet_csk(struct sock *sk) { return (struct inet_connection_sock *)sk; }

extern int tcp_set_congestion_control(struct sock *sk, const char *name);
extern void tcp_push_pending_frames(struct sock *sk);
extern void tcp_cleanup_rbuf(struct sock *sk, int copied);
extern void tcp_cookie_values_release(int *kref);
extern int strncpy_from_user(char *dest, const char *src, long count);
extern int copy_from_user(void *to, const void *from, unsigned long n);
extern int get_user(int *val, const int *addr);
extern void *kzalloc(size_t size, int flags);
extern void kref_init(int *kref);
extern void kref_put(int *kref, void (*release)(int *));
extern void lock_sock(struct sock *sk);
extern void release_sock(struct sock *sk);
extern int sock_flag(struct sock *sk, int flag);
extern u32 keepalive_time_elapsed(struct tcp_sock *tp);
extern void inet_csk_reset_keepalive_timer(struct sock *sk, u32 timeout);
extern int inet_csk_ack_scheduled(struct sock *sk);
extern int secs_to_retrans(int secs, int timeout, int rto_max);
extern unsigned long msecs_to_jiffies(unsigned int msecs);

#define __user
#define min_t(type, x, y) ((type)(x) < (type)(y) ? (type)(x) : (type)(y))