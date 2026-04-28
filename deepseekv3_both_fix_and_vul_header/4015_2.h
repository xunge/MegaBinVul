#include <stdatomic.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct ksmbd_conn;
struct ksmbd_transport;

struct ksmbd_transport_ops {
    int (*prepare)(struct ksmbd_transport *t);
    int (*read)(struct ksmbd_transport *t, char *buf, unsigned int size, int timeout);
    void (*disconnect)(struct ksmbd_transport *t);
};

struct ksmbd_transport {
    struct ksmbd_transport_ops *ops;
};

struct ksmbd_conn_ops {
    int (*process_fn)(struct ksmbd_conn *conn);
    void (*terminate_fn)(struct ksmbd_conn *conn);
};

struct ksmbd_conn_vals {
    unsigned int max_write_size;
};

struct ksmbd_conn {
    struct ksmbd_transport *transport;
    unsigned long last_active;
    char *request_buf;
    atomic_int srv_mutex;
    atomic_int r_count;
    int status;
    struct ksmbd_conn_vals *vals;
    void *um;
    void *local_nls;
    int r_count_q;
};

extern struct ksmbd_conn_ops default_conn_ops;
extern int THIS_MODULE;

#define SMB3_MAX_MSGSIZE (1024 * 1024)
#define MAX_STREAM_PROT_LEN 0x00FFFFFF
#define CONN 0
#define GFP_KERNEL 0
#define READ_ONCE(x) (x)
#define IS_ENABLED(x) (1)

static inline unsigned long jiffies = 0;

void mutex_init(atomic_int *lock);
void __module_get(int module);
void module_put(int module);
bool try_to_freeze(void);
void kvfree(const void *addr);
void *kvmalloc(size_t size, int flags);
void pr_err(const char *fmt, ...);
void pr_err_ratelimited(const char *fmt, ...);
void ksmbd_debug(int type, const char *fmt, ...);
bool ksmbd_conn_alive(struct ksmbd_conn *conn);
bool ksmbd_conn_good(struct ksmbd_conn *conn);
void ksmbd_conn_set_releasing(struct ksmbd_conn *conn);
bool ksmbd_smb_request(struct ksmbd_conn *conn);
unsigned int get_rfc1002_len(const char *buf);
void utf8_unload(void *um);
void unload_nls(void *nls);
void wait_event(int q, int condition);

static inline int atomic_read(const atomic_int *v) {
    return *v;
}