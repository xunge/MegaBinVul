#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <climits>

typedef int fd_t;
typedef unsigned char UCHAR;

namespace zmq {
    class msg_t {
    public:
        int init();
        int close();
    };

    class options_t {
    public:
        int heartbeat_interval;
        int heartbeat_timeout;
        size_t routing_id_size;
        int type;
        int mechanism;
    };

    class endpoint_uri_pair_t {};

    class stream_engine_base_t {
    public:
        stream_engine_base_t(fd_t, const options_t&, const endpoint_uri_pair_t&, bool);
        stream_engine_base_t(fd_t, const options_t&, const endpoint_uri_pair_t&);
        void set_pollin();
        void set_pollout();
        void in_event();
        void set_handshake_timer();
        void cancel_timer(int);
        void error(int);
        int read(void*, size_t);
        const options_t& _options;
    };

    class zmtp_engine_t : public stream_engine_base_t {
    public:
        zmtp_engine_t(fd_t, const options_t&, const endpoint_uri_pair_t&);
        ~zmtp_engine_t();
        void plug_internal();
        bool handshake();
        int receive_greeting();
        void receive_greeting_versioned();
        typedef bool (zmtp_engine_t::*handshake_fun_t)();
        handshake_fun_t select_handshake_fun(bool, unsigned char, unsigned char);
        bool handshake_v1_0_unversioned();
        bool handshake_v1_0();
        bool handshake_v2_0();
        bool handshake_v3_0();
        bool handshake_v3_1();
        int routing_id_msg(msg_t*);
        int process_routing_id_msg(msg_t*);

    private:
        static const size_t v2_greeting_size = 64;
        static const size_t v3_greeting_size = 128;
        static const size_t signature_size = 10;
        static const int ZMTP_1_0 = 0;
        static const int ZMTP_2_0 = 1;
        static const int ZMTP_3_x = 2;
        static const int ZMQ_NULL = 0;
        static const int ZMQ_PLAIN = 1;
        static const int ZMQ_CURVE = 2;
        static const int ZMQ_GSSAPI = 3;
        static const int connection_error = 1;
        static const int handshake_timer_id = 1;

        size_t _greeting_size;
        size_t _greeting_bytes_read;
        bool _subscription_required;
        int _heartbeat_timeout;
        int (stream_engine_base_t::*_next_msg)(msg_t*);
        int (stream_engine_base_t::*_process_msg)(msg_t*);
        msg_t _pong_msg;
        msg_t _routing_id_msg;
        unsigned char* _outpos;
        size_t _outsize;
        unsigned char _greeting_recv[128];
        unsigned char _greeting_send[128];
        bool _has_handshake_timer;
    };

    void put_uint64(unsigned char*, uint64_t);
    void zmq_assert(bool);
    void errno_assert(int);
}