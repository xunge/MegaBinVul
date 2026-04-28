#include <assert.h>
#include <stddef.h>

class object_t {
public:
    virtual ~object_t() {}
};

class io_thread_t;

class i_engine {
public:
    virtual ~i_engine() {}
    virtual bool has_handshake_stage() = 0;
    virtual void plug(io_thread_t* io_thread, object_t* session) = 0;
    virtual const char* get_endpoint() = 0;
};

class pipe_t {
public:
    virtual ~pipe_t() {}
    virtual void set_event_sink(object_t* sink) = 0;
    virtual void set_endpoint_pair(const char* endpoint) = 0;
};

class socket_base_t : public object_t {
};

struct options_t {
    int rcvhwm;
    int sndhwm;
};

namespace zmq {
    class session_base_t : public object_t {
    public:
        void process_attach(i_engine* engine_);
    protected:
        i_engine* _engine;
        pipe_t* _pipe;
        io_thread_t* _io_thread;
        socket_base_t* _socket;
        options_t options;

        bool is_terminating();
        bool get_effective_conflate_option(const options_t& opts);
        void engine_ready();
        void send_bind(socket_base_t* socket, pipe_t* pipe);
    };

    int pipepair(object_t* parents[2], pipe_t* pipes[2], int hwms[2], bool conflates[2]);
    void zmq_assert(bool condition);
    void errno_assert(int rc);
}