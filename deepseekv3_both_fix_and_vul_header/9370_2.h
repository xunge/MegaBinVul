#include <cstring>
#include <cstdint>

#define crypto_box_PUBLICKEYBYTES 32
#define crypto_box_SECRETKEYBYTES 32
#define HAVE_TWEETNACL 1

enum {
    send_hello
};

struct options_t {
    unsigned char curve_public_key[crypto_box_PUBLICKEYBYTES];
    unsigned char curve_secret_key[crypto_box_SECRETKEYBYTES];
    unsigned char curve_server_key[crypto_box_PUBLICKEYBYTES];
};

class mechanism_t {
public:
    mechanism_t(const options_t &options_);
};

class scoped_lock_t {
public:
    scoped_lock_t(void *sync);
};

namespace zmq {
    void zmq_assert(bool condition);
    
    class curve_client_t : public mechanism_t {
    public:
        curve_client_t(const options_t &options_);
        
    private:
        int state;
        unsigned char public_key[crypto_box_PUBLICKEYBYTES];
        unsigned char secret_key[crypto_box_SECRETKEYBYTES];
        unsigned char server_key[crypto_box_PUBLICKEYBYTES];
        unsigned char cn_public[crypto_box_PUBLICKEYBYTES];
        unsigned char cn_secret[crypto_box_SECRETKEYBYTES];
        void *sync;
        uint64_t cn_nonce;
        uint64_t cn_peer_nonce;
    };
}

extern "C" {
    int crypto_box_keypair(unsigned char *pk, unsigned char *sk);
    int sodium_init(void);
    void randombytes(unsigned char *buf, unsigned long long size);
}