#include <cstring>

namespace zmq {
    typedef int fd_t;
    const int MAX_HEADER_VALUE_LENGTH = 1024;

    struct options_t {
        int heartbeat_interval;
        int heartbeat_timeout;
    };

    struct endpoint_uri_pair_t {};
    struct ws_address_t {};
    struct stream_engine_base_t {
        stream_engine_base_t(fd_t, const options_t&, const endpoint_uri_pair_t&, bool) {}
        stream_engine_base_t(fd_t, const options_t&, const endpoint_uri_pair_t&) {}
        options_t _options;
    };

    enum {
        client_handshake_initial,
        handshake_initial
    };

    class ws_engine_t : public stream_engine_base_t {
    public:
        ws_engine_t(fd_t, const options_t&, const endpoint_uri_pair_t&, const ws_address_t&, bool);
        
    private:
        bool _client;
        ws_address_t _address;
        int _client_handshake_state;
        int _server_handshake_state;
        int _header_name_position;
        int _header_value_position;
        bool _header_upgrade_websocket;
        bool _header_connection_upgrade;
        int _heartbeat_timeout;
        char _websocket_key[MAX_HEADER_VALUE_LENGTH + 1];
        char _websocket_accept[MAX_HEADER_VALUE_LENGTH + 1];
        char _websocket_protocol[256];
        
        void (ws_engine_t::*_next_msg)();
        void (ws_engine_t::*_process_msg)();
        
        struct close_msg_t {
            void init() {}
        } _close_msg;
        
        void next_handshake_command() {}
        void process_handshake_command() {}
    };
}