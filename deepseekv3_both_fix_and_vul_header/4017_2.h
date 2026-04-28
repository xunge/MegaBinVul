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
    const struct ksmbd_transport_ops *ops;
};

struct conn_ops {
    int (*process_fn)(struct ksmbd_conn *conn);
    void (*terminate_fn)(struct ksmbd_conn *conn);
    unsigned int max_write_size;
};

struct ksmbd_conn {
    struct ksmbd_transport *transport;
    uint64_t last_active;
    void *request_buf;
    int status;
    atomic_int r_count;
    void *r_count_q;
    void *srv_mutex;
    void *um;
    void *local_nls;
    struct conn_ops *vals;
};

struct smb2_hdr {
    uint32_t ProtocolId;
};

extern struct conn_ops default_conn_ops;
extern unsigned long jiffies;

#define SMB3_MAX_MSGSIZE 0x00FFFFFF
#define MAX_STREAM_PROT_LEN 0x00FFFFFF
#define SMB1_MIN_SUPPORTED_HEADER_SIZE 32
#define SMB2_MIN_SUPPORTED_HEADER_SIZE 64
#define SMB2_PROTO_NUMBER 0xFE534D42
#define GFP_KERNEL 0
#define CONN 0
#define CONFIG_UNICODE 0
#define THIS_MODULE NULL

static inline unsigned int get_rfc1002_len(const char *hdr) {
    return *(unsigned int *)hdr;
}

static inline bool ksmbd_conn_alive(struct ksmbd_conn *conn) {
    return true;
}

static inline bool ksmbd_conn_good(struct ksmbd_conn *conn) {
    return true;
}

static inline void ksmbd_conn_set_releasing(struct ksmbd_conn *conn) {}

static inline void *smb2_get_msg(void *buf) {
    return buf;
}

static inline void mutex_init(void **mutex) {
    *mutex = NULL;
}

static inline bool try_to_freeze(void) {
    return false;
}

static inline void *kvmalloc(size_t size, int flags) {
    return malloc(size);
}

static inline void kvfree(const void *addr) {
    free((void *)addr);
}

static inline int READ_ONCE(int x) {
    return x;
}

static inline void ksmbd_debug(int type, const char *fmt, ...) {}

static inline void pr_err(const char *fmt, ...) {}

static inline void pr_err_ratelimited(const char *fmt, ...) {}

static inline void wait_event(void *wq, bool condition) {}

static inline void utf8_unload(void *um) {}

static inline void unload_nls(void *nls) {}

static inline void __module_get(void *module) {}

static inline void module_put(void *module) {}

static inline int ksmbd_smb_request(struct ksmbd_conn *conn) {
    return 1;
}

static inline int atomic_read(atomic_int *v) {
    return *v;
}

#define IS_ENABLED(x) 0