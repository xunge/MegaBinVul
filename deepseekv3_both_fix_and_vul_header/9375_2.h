#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#define crypto_box_NONCEBYTES 24
#define crypto_box_ZEROBYTES 32
#define crypto_box_BOXZEROBYTES 16

class msg_t {
public:
    size_t size();
    void* data();
};

namespace zmq {
    class curve_server_t {
    public:
        int process_hello(msg_t* msg_);
    };
}

uint8_t cn_client[32];
uint8_t secret_key[32];
uint64_t cn_peer_nonce;
int state;
const int send_welcome = 0;

uint64_t get_uint64(const uint8_t *buffer);
int crypto_box_open(uint8_t *m, const uint8_t *c, unsigned long long clen,
                   const uint8_t *n, const uint8_t *pk, const uint8_t *sk);