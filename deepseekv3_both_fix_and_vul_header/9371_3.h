#include <string>
#include <cstring>
#include <mutex>

#define crypto_box_SECRETKEYBYTES 32
#define crypto_box_PUBLICKEYBYTES 32
#define HAVE_TWEETNACL

namespace zmq {
    class session_base_t;
    
    class options_t {
    public:
        unsigned char curve_secret_key[crypto_box_SECRETKEYBYTES];
    };

    class mechanism_t {
    public:
        mechanism_t(const options_t& options);
    };

    class scoped_lock_t {
    public:
        scoped_lock_t(std::mutex& mutex);
        ~scoped_lock_t();
    private:
        std::mutex& mutex;
    };

    class curve_server_t : public mechanism_t {
    public:
        curve_server_t(session_base_t* session_, const std::string& peer_address_, const options_t& options_);
        
    private:
        session_base_t* session;
        std::string peer_address;
        enum { expect_hello } state;
        uint64_t cn_nonce;
        uint64_t cn_peer_nonce;
        std::mutex sync;
        unsigned char secret_key[crypto_box_SECRETKEYBYTES];
        unsigned char cn_public[crypto_box_PUBLICKEYBYTES];
        unsigned char cn_secret[crypto_box_SECRETKEYBYTES];
    };

    void zmq_assert(bool condition);
    int crypto_box_keypair(unsigned char* pk, unsigned char* sk);
    void randombytes(unsigned char* buf, unsigned long long size);
    int sodium_init();
}