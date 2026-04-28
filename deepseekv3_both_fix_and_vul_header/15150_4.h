#include <poll.h>
#include <sys/socket.h>
#include <linux/net.h>

#define SOCK_ASYNC_NOSPACE 0
#define NETREG_REGISTERED 1
#define KERN_INFO ""

struct file {
    void *private_data;
};

struct tun_file;

struct tun_struct {
    struct sock *sk;
    struct {
        struct {
            void *wait;
        } socket;
    };
    struct {
        void *next;
        void *prev;
    } readq;
    struct {
        int reg_state;
        char *name;
    } *dev;
};

struct sock {
    struct {
        unsigned long flags;
    } *sk_socket;
};

struct poll_table_struct;
typedef struct poll_table_struct poll_table;

extern struct tun_struct *__tun_get(struct tun_file *tfile);
extern void tun_put(struct tun_struct *tun);
extern int sock_writeable(const struct sock *sk);
extern int test_and_set_bit(int nr, volatile unsigned long *addr);
extern int skb_queue_empty(const void *list);
extern void poll_wait(struct file *file, void *wait_address, poll_table *p);
extern int DBG(const char *fmt, ...);