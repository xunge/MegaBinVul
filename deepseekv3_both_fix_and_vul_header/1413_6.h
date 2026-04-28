#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <stddef.h>

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_type;
    int sk_state;
    int sk_shutdown;
    void (*sk_state_change)(struct sock *);
};

struct timer_list {
    unsigned long data;
    void (*function)(unsigned long);
};

struct ax25_cb {
    struct sock *sk;
    struct ax25_dev *ax25_dev;
    unsigned int state;
    unsigned int n2count;
    struct timer_list timer;
    struct timer_list t1timer;
    struct timer_list t2timer;
    struct timer_list t3timer;
    struct timer_list idletimer;
};

struct ax25_dev {
    int values[256];
    void *dev;
    void *dev_tracker;
};

#define AX25_STATE_0 0
#define AX25_STATE_1 1
#define AX25_STATE_2 2
#define AX25_STATE_3 3
#define AX25_STATE_4 4
#define AX25_VALUES_PROTOCOL 0
#define AX25_PROTO_STD_SIMPLEX 0
#define AX25_PROTO_STD_DUPLEX 1
#define AX25_PROTO_DAMA_SLAVE 2
#define AX25_DISC 0
#define AX25_POLLON 0
#define AX25_COMMAND 0
#define SOCK_DESTROY 0
#define TCP_CLOSE 0
#define SEND_SHUTDOWN 1

static inline void sock_hold(struct sock *sk) {}
static inline void lock_sock(struct sock *sk) {}
static inline void sock_orphan(struct sock *sk) {}
static inline struct ax25_cb *sk_to_ax25(struct sock *sk) { return (struct ax25_cb *)sk; }
static inline void release_sock(struct sock *sk) {}
static inline void ax25_disconnect(struct ax25_cb *ax25, int code) {}
static inline void ax25_destroy_socket(struct ax25_cb *ax25) {}
static inline void ax25_send_control(struct ax25_cb *ax25, int cmd, int poll, int type) {}
static inline int sock_flag(struct sock *sk, int flag) { return 0; }
static inline void ax25_clear_queues(struct ax25_cb *ax25) {}
static inline void ax25_stop_t2timer(struct ax25_cb *ax25) {}
static inline void ax25_stop_t3timer(struct ax25_cb *ax25) {}
static inline void ax25_stop_idletimer(struct ax25_cb *ax25) {}
static inline void ax25_calculate_t1(struct ax25_cb *ax25) {}
static inline void ax25_start_t1timer(struct ax25_cb *ax25) {}
static inline void sock_set_flag(struct sock *sk, int flag) {}
static inline void del_timer_sync(struct timer_list *timer) {}
static inline void dev_put_track(void *dev, void *tracker) {}
static inline void ax25_dev_put(struct ax25_dev *ax25_dev) {}
static inline void sock_put(struct sock *sk) {}

typedef struct ax25_cb ax25_cb;
typedef struct ax25_dev ax25_dev;