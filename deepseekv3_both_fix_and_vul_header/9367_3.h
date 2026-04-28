#include <stdint.h>
#include <stdlib.h>
#include <string.h>

namespace zmq {
    class msg_t {
    public:
        enum { more = 0x01 };
        int flags() const;
        size_t size() const;
        void* data();
        int close();
        int init_size(size_t size);
    };

    class curve_client_t {
    public:
        int encode(msg_t *msg_);
    private:
        enum { connected };
        int state;
        uint64_t cn_nonce;
        uint8_t cn_precom[32]; // crypto_box_BEFORENMBYTES
    };
}

#define crypto_box_NONCEBYTES 24
#define crypto_box_ZEROBYTES 32
#define crypto_box_BOXZEROBYTES 16
#define crypto_box_BEFORENMBYTES 32

static void put_uint64(uint8_t *buf, uint64_t value) {
    buf[0] = (uint8_t)(value >> 56);
    buf[1] = (uint8_t)(value >> 48);
    buf[2] = (uint8_t)(value >> 40);
    buf[3] = (uint8_t)(value >> 32);
    buf[4] = (uint8_t)(value >> 24);
    buf[5] = (uint8_t)(value >> 16);
    buf[6] = (uint8_t)(value >> 8);
    buf[7] = (uint8_t)value;
}

static int crypto_box_afternm(uint8_t *c, const uint8_t *m,
                             uint64_t mlen, const uint8_t *n,
                             const uint8_t *k) {
    return 0;
}

#define zmq_assert(expr) ((void)0)
#define alloc_assert(ptr) ((void)0)