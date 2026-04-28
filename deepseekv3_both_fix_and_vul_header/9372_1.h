#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define crypto_box_NONCEBYTES 24
#define crypto_box_ZEROBYTES 32
#define crypto_box_BOXZEROBYTES 16

extern int crypto_box_afternm(unsigned char *c, const unsigned char *m,
                             unsigned long long mlen, const unsigned char *n,
                             const unsigned char *k);

struct msg_t {
    enum {
        more = 1
    };
    size_t size();
    void* data();
    int flags();
    int close();
    int init_size(size_t size);
};

namespace zmq {
    struct curve_server_t {
        enum {
            connected = 1
        };
        int state;
        uint64_t cn_nonce;
        uint8_t cn_precom[crypto_box_NONCEBYTES];
        int encode(msg_t *msg_);
        void put_uint64(uint8_t *dest, uint64_t value);
    };
}

#define zmq_assert(condition) ((void)0)
#define alloc_assert(ptr) ((void)0)