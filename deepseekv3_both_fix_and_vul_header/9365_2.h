#include <stdint.h>
#include <string.h>

#define crypto_box_NONCEBYTES 24
#define crypto_box_ZEROBYTES 32
#define crypto_box_BOXZEROBYTES 16
#define crypto_box_PUBLICKEYBYTES 32

class msg_t {
public:
    int init_size(size_t size);
    void* data();
};

namespace zmq {
    class curve_client_t {
    public:
        int produce_hello(msg_t* msg_);
    };
}

extern uint64_t cn_nonce;
extern uint8_t server_key[crypto_box_PUBLICKEYBYTES];
extern uint8_t cn_secret[crypto_box_PUBLICKEYBYTES];
extern uint8_t cn_public[crypto_box_PUBLICKEYBYTES];

int crypto_box(unsigned char *c, const unsigned char *m,
               unsigned long long mlen, const unsigned char *n,
               const unsigned char *pk, const unsigned char *sk);

void zmq_assert(int condition);
void errno_assert(int condition);
void put_uint64(uint8_t* dest, uint64_t value);