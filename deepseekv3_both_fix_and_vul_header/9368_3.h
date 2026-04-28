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

namespace zmq {
    struct curve_client_t {
        int produce_initiate(msg_t* msg_);
    };
}

struct options_t {
    int type;
    const char* identity;
    size_t identity_size;
} options;

uint8_t cn_public[32] = {0};
uint8_t server_key[32] = {0};
uint8_t cn_server[32] = {0};
uint8_t secret_key[32] = {0};
uint8_t public_key[32] = {0};
uint8_t cn_cookie[96] = {0};
uint64_t cn_nonce = 0;
uint8_t cn_secret[32] = {0};

static void randombytes(uint8_t* buf, size_t len) {
    for (size_t i = 0; i < len; i++) {
        buf[i] = rand() % 256;
    }
}

static int crypto_box(uint8_t* c, const uint8_t* m, size_t mlen,
                     const uint8_t* n, const uint8_t* pk, const uint8_t* sk) {
    return 0;
}

static void zmq_assert(int condition) {}
static void errno_assert(int condition) {}

static const char* socket_type_string(int type) {
    return "";
}

static size_t add_property(uint8_t* ptr, const char* name, const char* value, size_t value_len) {
    return 0;
}

static void put_uint64(uint8_t* buf, uint64_t value) {
    memcpy(buf, &value, 8);
}