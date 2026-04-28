#include <cstdint>
#include <memory>
#include <optional>

#define HTTP2_INITIAL_WINDOW_SIZE 65535
#define HTTP2_HEADER_TABLE_SIZE 4096

class HpackHandle {
public:
    HpackHandle(int size);
};

class DependencyTree {
public:
    DependencyTree(int max_streams);
};

class NetVC {
public:
    virtual ~NetVC() = default;
};

class TLSSNISupport : public NetVC {
public:
    struct {
        std::optional<int> http2_max_settings_frames_per_minute;
        std::optional<int> http2_max_ping_frames_per_minute;
        std::optional<int> http2_max_priority_frames_per_minute;
        std::optional<int> http2_max_rst_stream_frames_per_minute;
    } hints_from_sni;
};

class Http2CommonSession {
public:
    NetVC* get_netvc();
};

class Http2Stream;

struct Http2 {
    static int initial_window_size;
    static bool stream_priority_enabled;
    static int max_concurrent_streams_in;
    static int max_settings_frames_per_minute;
    static int max_ping_frames_per_minute;
    static int max_priority_frames_per_minute;
    static int max_rst_stream_frames_per_minute;
};

template <typename T>
class ActivityCop {
public:
    ActivityCop(void* mutex, void* stream_list, int);
    void start();
};

struct Http2ConnectionState {
    void init(Http2CommonSession* ssn);
    
    Http2CommonSession* session;
    int _server_rwnd;
    bool server_rwnd_is_shrinking;
    HpackHandle* local_hpack_handle;
    HpackHandle* remote_hpack_handle;
    DependencyTree* dependency_tree;
    int configured_max_settings_frames_per_minute;
    int configured_max_ping_frames_per_minute;
    int configured_max_priority_frames_per_minute;
    int configured_max_rst_stream_frames_per_minute;
    void* mutex;
    void* stream_list;
    ActivityCop<Http2Stream> _cop;
};