#include <cerrno>
#include <string>
#include <map>
#include <utility>

namespace zmq {

class session_base_t;
class mechanism_t;
class socket_base_t;

class stream_engine_base_t {
public:
    void mechanism_ready();
    
private:
    struct options_t {
        int heartbeat_interval;
        bool recv_routing_id;
        int router_notify;
    } _options;
    bool _has_heartbeat_timer;
    bool _has_handshake_stage;
    session_base_t* _session;
    mechanism_t* _mechanism;
    socket_base_t* _socket;
    void* _metadata;
    std::pair<std::string, std::string> _endpoint_uri_pair;
    void (stream_engine_base_t::*_next_msg)();
    void (stream_engine_base_t::*_process_msg)();
    static const int heartbeat_ivl_timer_id = 1;
    
    void add_timer(int, int);
    void init_properties(std::map<std::string, std::string>&);
    void pull_and_encode();
    void write_credential();
};

typedef std::map<std::string, std::string> properties_t;
class metadata_t {
public:
    explicit metadata_t(const properties_t&);
};

class msg_t {
public:
    void init();
};

class session_base_t {
public:
    void engine_ready();
    int push_msg(msg_t*);
    void flush();
};

class mechanism_t {
public:
    void peer_routing_id(msg_t*);
    const properties_t& get_zap_properties();
    const properties_t& get_zmtp_properties();
};

class socket_base_t {
public:
    void event_handshake_succeeded(const std::pair<std::string, std::string>&, int);
};

#define ZMQ_NOTIFY_CONNECT 1
}

void errno_assert(int);
void alloc_assert(void*);
void zmq_assert(bool);