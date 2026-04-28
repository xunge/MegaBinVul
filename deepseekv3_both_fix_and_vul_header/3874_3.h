#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <cstddef>

typedef int fd_t;

namespace zmq {
    class options_t {};
    class endpoint_uri_pair_t {};
    class handle_t {
    public:
        handle_t() {}
        handle_t(std::nullptr_t) {}
    };
    class msg_t { public: int init() { return 0; } } _tx_msg;
    class decoder_t {};
    class encoder_t {};
    class mechanism_t {};
    class metadata_t {};
    class session_t {};
    class socket_t {};
    
    class stream_engine_base_t {
    protected:
        const options_t& _options;
        void* _inpos;
        size_t _insize;
        decoder_t* _decoder;
        void* _outpos;
        size_t _outsize;
        encoder_t* _encoder;
        mechanism_t* _mechanism;
        void* _next_msg;
        void* _process_msg;
        metadata_t* _metadata;
        bool _input_stopped;
        bool _output_stopped;
        const endpoint_uri_pair_t& _endpoint_uri_pair;
        bool _has_handshake_timer;
        bool _has_ttl_timer;
        bool _has_timeout_timer;
        bool _has_heartbeat_timer;
        std::string _peer_address;
        fd_t _s;
        handle_t _handle;
        bool _plugged;
        bool _handshaking;
        bool _io_error;
        session_t* _session;
        socket_t* _socket;
        bool _has_handshake_stage;
    public:
        stream_engine_base_t(fd_t, const options_t&, const endpoint_uri_pair_t&, bool);
        stream_engine_base_t(fd_t, const options_t&, const endpoint_uri_pair_t&);
    };
    
    static std::string get_peer_address(fd_t) { return ""; }
    static void unblock_socket(fd_t) {}
    static void errno_assert(bool) {}
}