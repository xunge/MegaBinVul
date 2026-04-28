#include <map>
#include <unistd.h>

#define unlikely(x) __builtin_expect(!!(x), 0)
#define likely(x) __builtin_expect(!!(x), 1)

namespace zmq {
    class pipe_t {
    public:
        void check_read();
    };

    class engine_t {
    public:
        void restart_output();
        void zap_msg_available();
    };

    class session_base_t {
    public:
        void read_activated(pipe_t *pipe_);
    protected:
        pipe_t* _pipe;
        pipe_t* _zap_pipe;
        engine_t* _engine;
        std::map<pipe_t*, int> _terminating_pipes;
    };

    void zmq_assert(bool condition);
}