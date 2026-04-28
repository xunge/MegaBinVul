#include <unistd.h>
#include <errno.h>
#include <stddef.h>
#include <stdbool.h>

#define unlikely(x) __builtin_expect(!!(x), 0)
#define likely(x) __builtin_expect(!!(x), 1)
#define zmq_assert(expr) ((void)0)

struct zmq_msg_t {
    // dummy implementation
};

class zmq_decoder_t {
public:
    void get_buffer(char**, size_t*);
    void resize_buffer(size_t);
    int decode(char*, size_t, size_t&);
    zmq_msg_t* msg();
};

class zmq_session_t {
public:
    void engine_ready();
    void flush();
};

class zmq_mechanism_t {
    // dummy implementation
};

namespace zmq {
    class stream_engine_base_t {
    private:
        bool _io_error;
        bool _handshaking;
        zmq_mechanism_t* _mechanism;
        bool _has_handshake_stage;
        zmq_session_t* _session;
        zmq_decoder_t* _decoder;
        bool _input_stopped;
        void* _handle;
        char* _inpos;
        size_t _insize;
        int (stream_engine_base_t::*_process_msg)(zmq_msg_t*);

    public:
        bool in_event_internal();
        bool handshake();
        int read(void*, size_t);
        void error(int);
        void rm_fd(void*);
        void reset_pollin(void*);
    };

    enum {
        connection_error,
        protocol_error
    };
}