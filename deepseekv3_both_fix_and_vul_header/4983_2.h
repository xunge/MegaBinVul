#include <stddef.h>
#include <errno.h>
#include <stdint.h>

struct ceph_auth_client;
struct ceph_authorizer;

struct ceph_x_authorizer {
    void *reply_buf;
    int service;
    uint64_t nonce;
};

struct ceph_x_ticket_handler {
    void *session_key;
};

struct ceph_x_authorize_reply {
    uint64_t nonce_plus_one;
};

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)-1000L)
#define PTR_ERR(x) ((intptr_t)(x))

static inline uint64_t le64_to_cpu(uint64_t x) { return x; }
static inline int get_ticket_handler(struct ceph_auth_client *ac, int service) { return 0; }
static inline int ceph_x_decrypt(void **key, void **p, void *end, void *reply, size_t size) { return 0; }
static inline void dout(const char *fmt, ...) {}