#include <cstddef>
#include <cerrno>
#include <cstring>
#include <new>

namespace zmq {
    class stream_engine_t {
    public:
        bool handshake();
        void pull_msg_from_session();
        void write_identity();
        void next_handshake_command();
        void process_handshake_command();
    };
}

#define ZMQ_NULL 0
#define ZMQ_PLAIN 1
#define ZMQ_CURVE 2
#define ZMQ_PUB 1
#define ZMQ_XPUB 2
#define ZMTP_1_0 0
#define ZMTP_2_0 1
#define EAGAIN 11

struct options_t {
    int type;
    int mechanism;
    bool as_server;
    size_t maxmsgsize;
    size_t identity_size;
    const char* identity;
};

struct msg_t {
    int init_size(size_t);
    void* data();
};

class encoder_base_t {
public:
    virtual void load_msg(msg_t*) = 0;
    virtual size_t encode(unsigned char**, size_t) = 0;
    virtual ~encoder_base_t() {}
};

class decoder_base_t {
public:
    virtual ~decoder_base_t() {}
};

class v1_encoder_t : public encoder_base_t {
public:
    v1_encoder_t(size_t);
    void load_msg(msg_t*);
    size_t encode(unsigned char**, size_t);
};

class v1_decoder_t : public decoder_base_t {
public:
    v1_decoder_t(size_t, size_t);
};

class v2_encoder_t : public encoder_base_t {
public:
    v2_encoder_t(size_t);
    void load_msg(msg_t*);
    size_t encode(unsigned char**, size_t);
};

class v2_decoder_t : public decoder_base_t {
public:
    v2_decoder_t(size_t, size_t);
};

struct null_mechanism_t {
    null_mechanism_t(void*, const char*, const options_t&);
};

struct plain_mechanism_t {
    plain_mechanism_t(void*, const char*, const options_t&);
};

struct curve_server_t {
    curve_server_t(void*, const char*, const options_t&);
};

struct curve_client_t {
    curve_client_t(const options_t&);
};

static size_t greeting_size = 64;
static const size_t signature_size = 10;
static const size_t v3_greeting_size = 64;
static size_t greeting_bytes_read = 0;
static unsigned char greeting_recv[64];
static unsigned char greeting_send[64];
static unsigned char* outpos;
static size_t outsize = 0;
static unsigned char* inpos;
static size_t insize = 0;
static bool handshaking = false;
static void* handle;
static void* session;
static const char* peer_address;
static size_t out_batch_size;
static size_t in_batch_size;
static bool subscription_required = false;
static msg_t tx_msg;
static encoder_base_t* encoder;
static decoder_base_t* decoder;
static void* mechanism;
static options_t options;
static void (zmq::stream_engine_t::*read_msg)();
static void (zmq::stream_engine_t::*write_msg)();

void zmq_assert(bool);
int read(void*, size_t);
void error();
void set_pollout(void*);
void alloc_assert(void*);