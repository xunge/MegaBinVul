#include <stdint.h>
#include <string.h>
#include <errno.h>

namespace zmq {
    class curve_client_t {
    public:
        int process_ready(const uint8_t *msg_data, size_t msg_size);
    };
}

#define crypto_box_NONCEBYTES 24
#define crypto_box_ZEROBYTES 32
#define crypto_box_BOXZEROBYTES 16
#define EPROTO 71

extern uint64_t cn_peer_nonce;
extern uint8_t *cn_precom;
extern int parse_metadata(const uint8_t *, size_t);
extern uint64_t get_uint64(const uint8_t *);
extern "C" int crypto_box_open_afternm(unsigned char *, const unsigned char *, unsigned long long, const unsigned char *, const unsigned char *);

enum { connected };
extern int state;