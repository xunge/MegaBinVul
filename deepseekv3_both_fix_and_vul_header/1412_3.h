#include <stddef.h>
#include <errno.h>
#include <sys/socket.h>

#define TCP_CLOSE 7
#define SOCK_DESTROY 3
#define SOCK_DEAD 4
#define SEND_SHUTDOWN 1
#define ENETUNREACH 101

struct sock {
    int sk_state;
    int sk_err;
    int sk_shutdown;
    void (*sk_state_change)(struct sock*);
};

typedef struct ax25_cb {
    void* timer;
    void* t1timer;
    void* t2timer;
    void* t3timer;
    void* idletimer;
    struct sock* sk;
    unsigned int state;
} ax25_cb;

enum {
    AX25_STATE_0,
    AX25_STATE_1,
    AX25_STATE_2,
    AX25_STATE_3,
    AX25_STATE_4
};

void ax25_clear_queues(ax25_cb* ax25);
void del_timer_sync(void* timer);
void ax25_stop_heartbeat(ax25_cb* ax25);
void ax25_stop_t1timer(ax25_cb* ax25);
void ax25_stop_t2timer(ax25_cb* ax25);
void ax25_stop_t3timer(ax25_cb* ax25);
void ax25_stop_idletimer(ax25_cb* ax25);
void ax25_link_failed(ax25_cb* ax25, int reason);
void local_bh_disable(void);
void local_bh_enable(void);
void bh_lock_sock(struct sock* sk);
void bh_unlock_sock(struct sock* sk);
void sock_set_flag(struct sock* sk, int flag);
int sock_flag(struct sock* sk, int flag);