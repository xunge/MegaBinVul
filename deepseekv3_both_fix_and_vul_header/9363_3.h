#include <errno.h>
#include <string.h>
#include <new>

namespace zmq {
    class stream_engine_t {
    public:
        bool handshake();
        void pull_msg_from_session();
        void process_identity_msg();
        void next_handshake_command();
        void process_handshake_command();
    };
}

#define ZMQ_NULL 0
#define ZMQ_PLAIN 1
#define ZMQ_CURVE 2
#define ZMQ_GSSAPI 3

#define ZMTP_1_0 0
#define ZMTP_2_0 1

#define ZMQ_PUB 1
#define ZMQ_XPUB 2

#define EAGAIN 11

static bool handshaking;
static size_t greeting_bytes_read;
static size_t greeting_size = 64;
static const size_t signature_size = 10;
static const size_t v3_greeting_size = 64;
static int s;
static unsigned char greeting_recv[64];
static unsigned char* outpos;
static size_t outsize;
static unsigned char greeting_send[64];
static void* handle;
static int connection_error;
static int protocol_error;
static bool has_handshake_timer;
static int handshake_timer_id;

struct options_t {
    int type;
    int mechanism;
    bool as_server;
    size_t identity_size;
    const char* identity;
    size_t maxmsgsize;
};

struct msg_t {
    int init_size(size_t);
    void* data();
};

struct encoder_base_t {
    virtual void load_msg(msg_t*) = 0;
    virtual size_t encode(unsigned char**, size_t) = 0;
    virtual ~encoder_base_t() {}
};

struct decoder_base_t {
    virtual ~decoder_base_t() {}
};

struct v1_encoder_t : encoder_base_t {
    v1_encoder_t(size_t);
    void load_msg(msg_t*);
    size_t encode(unsigned char**, size_t);
};

struct v1_decoder_t : decoder_base_t {
    v1_decoder_t(size_t, size_t);
};

struct v2_encoder_t : encoder_base_t {
    v2_encoder_t(size_t);
    void load_msg(msg_t*);
    size_t encode(unsigned char**, size_t);
};

struct v2_decoder_t : decoder_base_t {
    v2_decoder_t(size_t, size_t);
};

struct null_mechanism_t {
    null_mechanism_t(void*, const char*, const options_t&);
};

struct plain_server_t {
    plain_server_t(void*, const char*, const options_t&);
};

struct plain_client_t {
    plain_client_t(const options_t&);
};

struct curve_server_t {
    curve_server_t(void*, const char*, const options_t&);
};

struct curve_client_t {
    curve_client_t(const options_t&);
};

struct gssapi_server_t {
    gssapi_server_t(void*, const char*, const options_t&);
};

struct gssapi_client_t {
    gssapi_client_t(const options_t&);
};

static void* session;
static const char* peer_address;
static options_t options;
static encoder_base_t* encoder;
static decoder_base_t* decoder;
static void* mechanism;
static msg_t tx_msg;
static unsigned char* inpos;
static size_t insize;
static bool subscription_required;
static void (zmq::stream_engine_t::*next_msg)();
static void (zmq::stream_engine_t::*process_msg)();
static size_t out_batch_size;
static size_t in_batch_size;

static int tcp_read(int, void*, size_t) { return 0; }
static void error(int) {}
static void set_pollout(void*) {}
static void cancel_timer(int) {}
static void zmq_assert(bool) {}
static void alloc_assert(void*) {}