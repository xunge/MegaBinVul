#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define crypto_secretbox_KEYBYTES 32
#define crypto_secretbox_NONCEBYTES 24
#define crypto_secretbox_ZEROBYTES 32
#define crypto_secretbox_BOXZEROBYTES 16
#define crypto_box_NONCEBYTES 24
#define crypto_box_ZEROBYTES 32
#define crypto_box_BOXZEROBYTES 16
#define crypto_box_BEFORENMBYTES 32

extern uint8_t cookie_key[crypto_secretbox_KEYBYTES];
extern uint8_t cn_client[32];
extern uint8_t cn_secret[32];
extern uint8_t cn_precom[crypto_box_BEFORENMBYTES];
extern uint64_t cn_peer_nonce;

struct msg_t {
    size_t size();
    void* data();
};

namespace zmq {
    class session_base_t {
    public:
        int zap_connect();
    };

    class curve_server_t {
    public:
        int process_initiate(msg_t *msg_);
        void send_zap_request(const uint8_t* key);
        int receive_and_process_zap_reply();
        int parse_metadata(const uint8_t* data, size_t size);
        session_base_t* session;
        enum { send_ready, send_error, expect_zap_reply } state;
        const char* status_code;
    };

    void zmq_assert(bool condition);
}

int crypto_secretbox_open(uint8_t* m, const uint8_t* c, unsigned long long clen,
                         const uint8_t* n, const uint8_t* k);

int crypto_box_open(uint8_t* m, const uint8_t* c, unsigned long long clen,
                   const uint8_t* n, const uint8_t* pk, const uint8_t* sk);

int crypto_box_beforenm(uint8_t* k, const uint8_t* pk, const uint8_t* sk);

static inline uint64_t get_uint64(const uint8_t* buffer) {
    return ((uint64_t)buffer[0] << 56) |
           ((uint64_t)buffer[1] << 48) |
           ((uint64_t)buffer[2] << 40) |
           ((uint64_t)buffer[3] << 32) |
           ((uint64_t)buffer[4] << 24) |
           ((uint64_t)buffer[5] << 16) |
           ((uint64_t)buffer[6] << 8)  |
           (uint64_t)buffer[7];
}