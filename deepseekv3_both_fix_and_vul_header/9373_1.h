#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#define crypto_box_NONCEBYTES 24
#define crypto_box_BOXZEROBYTES 16
#define crypto_box_ZEROBYTES 32

struct msg_t {
    size_t size();
    void* data();
    int close();
    int init_size(size_t);
    void set_flags(int);
    enum { more };
};

namespace zmq {
    enum { connected };
    
    struct curve_server_t {
        int state;
        uint64_t cn_peer_nonce;
        uint8_t cn_precom[32];
        int decode(msg_t*);
    };

    void zmq_assert(bool);
    void alloc_assert(void*);
    uint64_t get_uint64(const void*);
}

extern "C" {
    int crypto_box_open_afternm(unsigned char*, const unsigned char*,
                              unsigned long long, const unsigned char*,
                              const unsigned char*);
}