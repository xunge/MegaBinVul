#include <stddef.h>
#include <signal.h>
#include <stdatomic.h>

struct list_head {
    struct list_head *next, *prev;
};

struct delayed_work {
    int dummy;
};

struct task_struct {
    int dummy;
};

struct TCP_Server_Info {
    int srv_count;
    struct list_head tcp_ses_list;
    int srv_lock;
    int tcpStatus;
    struct delayed_work echo;
    struct delayed_work resolve;
    struct delayed_work reconnect;
    struct TCP_Server_Info *primary_server;
    struct {
        void *response;
        int len;
    } session_key;
    char *hostname;
    struct task_struct *tsk;
};

int cifs_tcp_ses_lock;
#define CifsExiting 1
#define CIFS_SERVER_IS_CHAN(server) (0)

static inline void spin_lock(int *lock) { (void)lock; }
static inline void spin_unlock(int *lock) { (void)lock; }
static inline void list_del_init(struct list_head *entry) { (void)entry; }
static inline void WARN_ON(int condition) { (void)condition; }
static inline void *cifs_net_ns(struct TCP_Server_Info *s) { return NULL; }
static inline void put_net(void *net) { (void)net; }
static inline void cancel_delayed_work_sync(struct delayed_work *work) { (void)work; }
static inline void cancel_delayed_work(struct delayed_work *work) { (void)work; }
static inline void cifs_crypto_secmech_release(struct TCP_Server_Info *server) { (void)server; }
static inline void kfree_sensitive(void *ptr) { (void)ptr; }
static inline void kfree(void *ptr) { (void)ptr; }
static inline struct task_struct *xchg(struct task_struct **ptr, struct task_struct *new) { 
    struct task_struct *old = *ptr;
    *ptr = new;
    return old;
}
static inline int send_sig(int sig, struct task_struct *task, int priv) { 
    (void)sig; (void)task; (void)priv; 
    return 0; 
}