#include <stdbool.h>
#include <stddef.h>

struct l1oip {
    bool shutdown;
    void *keep_tl;
    void *timeout_tl;
    void *workq;
    void *socket_thread;
    bool registered;
    unsigned int d_idx;
    struct {
        struct {
            void *dev;
        } *dch;
        void *bch;
#ifdef REORDER_DEBUG
        void *disorder_skb;
#endif
    } chan[128];
    void *list;
};

void *l1oip_lock;

int timer_pending(void *);
void del_timer(void *);
void cancel_work_sync(void *);
void l1oip_socket_close(void *);
void mISDN_unregister_device(void *);
void mISDN_freedchannel(void *);
void mISDN_freebchannel(void *);
void kfree(void *);
void spin_lock(void *);
void spin_unlock(void *);
void list_del(void *);