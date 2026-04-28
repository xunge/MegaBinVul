#include <stddef.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <stdint.h>

struct tty_struct {
    struct {
        int (*write)();
    } *driver;
    void *disc_data;
    int receive_room;
};

struct ppp_channel {
    void *private;
    struct ppp_channel_ops *ops;
    int mtu;
    int hdrlen;
};

struct ppp_channel_ops {
    // Minimal ops structure
};

struct syncppp {
    struct tty_struct *tty;
    unsigned int mru;
    int xmit_lock;
    int recv_lock;
    unsigned int xaccm[4];
    unsigned int raccm;
    void *rqueue;
    void *tsk;
    atomic_int refcnt;
    struct {
        unsigned int done;
    } dead_cmp;
    struct ppp_channel chan;
};

#define GFP_KERNEL 0
#define PPP_MRU 1500
#define EOPNOTSUPP 95
#define ENOMEM 12

extern struct ppp_channel_ops sync_ops;
extern int ppp_register_channel(struct ppp_channel *);
extern void ppp_sync_process(unsigned long);

static inline void spin_lock_init(int *lock) { *lock = 0; }
static inline void skb_queue_head_init(void *q) {}
static inline void tasklet_init(void *t, void (*func)(unsigned long), unsigned long data) {}