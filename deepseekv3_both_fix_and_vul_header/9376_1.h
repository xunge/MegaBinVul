#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define crypto_box_NONCEBYTES 24
#define crypto_box_ZEROBYTES 32
#define crypto_box_BOXZEROBYTES 16
#define ZMQ_REQ 3
#define ZMQ_DEALER 5
#define ZMQ_ROUTER 6

struct msg_t {
    void* data();
    int init_size(size_t size);
};

struct options_t {
    int type;
    const char* identity;
    size_t identity_size;
};

namespace zmq {
    class curve_server_t {
    public:
        options_t options;
        uint64_t cn_nonce;
        uint8_t cn_precom[crypto_box_BOXZEROBYTES];
        int produce_ready(msg_t* msg_);
    };
}

const char* socket_type_string(int type);
size_t add_property(uint8_t* ptr, const char* name, const char* value, size_t value_len);
int crypto_box_afternm(unsigned char* c, const unsigned char* m, unsigned long long mlen, const unsigned char* n, const unsigned char* k);
void zmq_assert(int condition);
void errno_assert(int condition);
void put_uint64(uint8_t* dest, uint64_t value);