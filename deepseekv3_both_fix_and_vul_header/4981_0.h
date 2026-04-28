#include <stdint.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define TEMP_TICKET_BUF_LEN 256
#define EINVAL 22
#define ENOMEM 12
#define GFP_NOFS 0

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t s32;

struct ceph_auth_client {
    void *private;
};

struct ceph_crypto_key {
    int dummy;
};

struct ceph_timespec {
    int dummy;
};

struct ceph_buffer {
    struct {
        int iov_len;
    } vec;
};

struct ceph_x_ticket_handler {
    struct ceph_crypto_key session_key;
    struct ceph_buffer *ticket_blob;
    struct ceph_timespec validity;
    u64 secret_id;
    unsigned long expires;
    unsigned long renew_after;
    int service;
};

struct ceph_x_info {
    int have_keys;
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

static inline unsigned long get_seconds(void) {
    return time(NULL);
}

static inline void ceph_decode_need(void **p, void *end, size_t n, int bad) {}
static inline u32 ceph_decode_32(void **p) { return 0; }
static inline void dout(const char *fmt, ...) {}
static inline const char *ceph_entity_type_name(int type) { return ""; }
static inline u8 ceph_decode_8(void **p) { return 0; }
static inline struct ceph_x_ticket_handler *get_ticket_handler(struct ceph_auth_client *ac, int type) { return NULL; }
static inline int ceph_x_decrypt(struct ceph_crypto_key *secret, void **p, void *end, void *dbuf, int len) { return 0; }
static inline int ceph_crypto_key_decode(struct ceph_crypto_key *key, void **p, void *end) { return 0; }
static inline void ceph_decode_copy(void **p, void *dest, size_t n) {}
static inline void ceph_decode_timespec(struct timespec *ts, struct ceph_timespec *cts) {}
static inline void ceph_decode_8_safe(void **p, void *end, u8 v, int bad) {}
static inline void ceph_decode_32_safe(void **p, void *end, u32 v, int bad) {}
static inline u64 ceph_decode_64(void **p) { return 0; }
static inline int ceph_decode_buffer(struct ceph_buffer **b, void **p, void *end) { return 0; }
static inline void ceph_crypto_key_destroy(struct ceph_crypto_key *key) {}
static inline void ceph_buffer_put(struct ceph_buffer *b) {}
static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }

enum { bad };