#include <stdatomic.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

struct ksmbd_conn {
    struct ksmbd_transport *transport;
    void *srv_mutex;
    unsigned long last_active;
    void *request_buf;
    struct {
        unsigned int max_write_size;
    } *vals;
    int status;
    void *r_count_q;
    atomic_int r_count;
    void *um;
    void *local_nls;
};

struct ksmbd_transport {
    struct {
        int (*prepare)(struct ksmbd_transport *);
        int (*read)(struct ksmbd_transport *, void *, size_t, int);
        void (*disconnect)(struct ksmbd_transport *);
    } *ops;
};

struct smb2_hdr {
    uint32_t ProtocolId;
};

struct unicode_map;
struct nls_table;

#define THIS_MODULE ((void*)0)
#define CONN 0
#define SMB3_MAX_MSGSIZE 0
#define MAX_STREAM_PROT_LEN 0x00FFFFFF
#define SMB1_MIN_SUPPORTED_HEADER_SIZE 0
#define SMB2_MIN_SUPPORTED_HEADER_SIZE 0
#define SMB2_PROTO_NUMBER 0
#define GFP_KERNEL 0
#define CONFIG_UNICODE 0
#define jiffies 0

struct ksmbd_conn_ops {
    int (*process_fn)(struct ksmbd_conn *);
    void (*terminate_fn)(struct ksmbd_conn *);
};

extern struct ksmbd_conn_ops default_conn_ops;

static inline void mutex_init(void *lock) {}
static inline void __module_get(void *module) {}
static inline void module_put(void *module) {}
static inline bool try_to_freeze(void) { return false; }
static inline void kvfree(const void *addr) {}
static inline void *kvmalloc(size_t size, int flags) { return NULL; }
static inline unsigned int get_rfc1002_len(const char *buf) { return 0; }
static inline bool ksmbd_conn_alive(struct ksmbd_conn *conn) { return false; }
static inline bool ksmbd_conn_good(struct ksmbd_conn *conn) { return false; }
static inline void ksmbd_debug(int type, const char *fmt, ...) {}
static inline void pr_err(const char *fmt, ...) {}
static inline void pr_err_ratelimited(const char *fmt, ...) {}
static inline void ksmbd_conn_set_releasing(struct ksmbd_conn *conn) {}
static inline void wait_event(void *q, int condition) {}
static inline void utf8_unload(struct unicode_map *um) {}
static inline void unload_nls(struct nls_table *nls) {}
static inline void *smb2_get_msg(void *buf) { return NULL; }
static inline int READ_ONCE(int val) { return val; }
static inline int ksmbd_smb_request(struct ksmbd_conn *conn) { return 0; }