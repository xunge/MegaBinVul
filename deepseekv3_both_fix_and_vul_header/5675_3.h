#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <new>

#define ZMQ_NULL 0
#define ZMQ_PLAIN 1
#define ZMQ_CURVE 2
#define ZMTP_1_0 1
#define ZMTP_2_0 2
#define ZMQ_PUB 1
#define ZMQ_XPUB 2
#define EAGAIN 11

struct zmq_msg_t {
    int init_size(size_t) { return 0; }
    void* data() { return nullptr; }
};

struct options_t {
    int type;
    size_t identity_size;
    void* identity;
    size_t maxmsgsize;
    int mechanism;
    bool as_server;
};

struct encoder_base_t {
    virtual void load_msg(zmq_msg_t*) = 0;
    virtual size_t encode(unsigned char**, size_t) = 0;
    virtual ~encoder_base_t() {}
};

struct decoder_base_t {
    virtual ~decoder_base_t() {}
};

struct v1_encoder_t : encoder_base_t {
    v1_encoder_t(size_t) {}
    void load_msg(zmq_msg_t*) override {}
    size_t encode(unsigned char**, size_t) override { return 0; }
};

struct v1_decoder_t : decoder_base_t {
    v1_decoder_t(size_t, size_t) {}
};

struct v2_encoder_t : encoder_base_t {
    v2_encoder_t(size_t) {}
    void load_msg(zmq_msg_t*) override {}
    size_t encode(unsigned char**, size_t) override { return 0; }
};

struct v2_decoder_t : decoder_base_t {
    v2_decoder_t(size_t, size_t) {}
};

struct null_mechanism_t {
    null_mechanism_t(void*, void*, options_t) {}
};

struct plain_mechanism_t {
    plain_mechanism_t(void*, void*, options_t) {}
};

struct session_t {
    bool zap_enabled() { return false; }
};

namespace zmq {
    struct stream_engine_t {
        bool handshaking;
        size_t greeting_bytes_read;
        size_t greeting_size;
        static const size_t v3_greeting_size;
        static const size_t signature_size;
        char greeting_recv[128];
        char greeting_send[128];
        char* outpos;
        size_t outsize;
        void* handle;
        options_t options;
        session_t* session;
        zmq_msg_t tx_msg;
        encoder_base_t* encoder;
        decoder_base_t* decoder;
        void* mechanism;
        char* inpos;
        size_t insize;
        bool subscription_required;
        size_t out_batch_size;
        size_t in_batch_size;
        void* peer_address;
        void (stream_engine_t::*read_msg)();
        void (stream_engine_t::*write_msg)();

        int read(void*, size_t) { return 0; }
        void error() {}
        void set_pollout(void*) {}
        void pull_msg_from_session() {}
        void write_identity() {}
        void next_handshake_command() {}
        void process_handshake_command() {}
        void zmq_assert(bool) {}
        void alloc_assert(void*) {}
        bool handshake();
    };

    const size_t stream_engine_t::v3_greeting_size = 128;
    const size_t stream_engine_t::signature_size = 10;
}