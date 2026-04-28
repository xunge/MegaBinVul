#include <unistd.h>

namespace zmq {
    class options_t {};
    class endpoint_uri_pair_t {};
    class stream_engine_base_t {
    public:
        stream_engine_base_t(int fd_, const options_t& options_, const endpoint_uri_pair_t& endpoint_uri_pair_, bool flag) {}
        stream_engine_base_t(int fd_, const options_t& options_, const endpoint_uri_pair_t& endpoint_uri_pair_) {}
    };
    typedef int fd_t;
    class raw_engine_t : public stream_engine_base_t {
    public:
        raw_engine_t(fd_t fd_, const options_t& options_, const endpoint_uri_pair_t& endpoint_uri_pair_);
    };
}