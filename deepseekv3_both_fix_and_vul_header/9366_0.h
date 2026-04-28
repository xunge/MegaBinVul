#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define crypto_box_NONCEBYTES 24
#define crypto_box_BOXZEROBYTES 16
#define crypto_box_ZEROBYTES 32

extern int crypto_box_open_afternm(unsigned char *m, const unsigned char *c,
                                  unsigned long long clen,
                                  const unsigned char *n,
                                  const unsigned char *k);

struct msg_t {
    void *data();
    size_t size();
    int close();
    int init_size(size_t size);
    void set_flags(int flags);
    enum { more };
};

namespace zmq {
    class curve_client_t {
    public:
        int decode(msg_t *msg_);
    private:
        int state;
        uint64_t cn_peer_nonce;
        uint8_t cn_precom[32];
    };
}

#define zmq_assert(condition) ((void)0)
#define alloc_assert(ptr) ((void)0)

static inline uint64_t get_uint64(const uint8_t *buf) {
    return ((uint64_t)buf[0] << 56) |
           ((uint64_t)buf[1] << 48) |
           ((uint64_t)buf[2] << 40) |
           ((uint64_t)buf[3] << 32) |
           ((uint64_t)buf[4] << 24) |
           ((uint64_t)buf[5] << 16) |
           ((uint64_t)buf[6] << 8) |
           (uint64_t)buf[7];
}