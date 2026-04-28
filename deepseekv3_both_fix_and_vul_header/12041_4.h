#include <cstdint>
#include <cinttypes>
#include <sstream>
#include <string>

typedef uint32_t Http2StreamId;

enum class Http2ErrorClass {
    HTTP2_ERROR_CLASS_NONE,
    HTTP2_ERROR_CLASS_CONNECTION,
    HTTP2_ERROR_CLASS_STREAM
};

enum class Http2ErrorCode {
    HTTP2_ERROR_PROTOCOL_ERROR,
    HTTP2_ERROR_FRAME_SIZE_ERROR,
    HTTP2_ERROR_ENHANCE_YOUR_CALM
};

struct Http2Error {
    Http2Error(Http2ErrorClass error_class, Http2ErrorCode error_code, const char* msg) {}
    Http2Error(Http2ErrorClass error_class) {}
};

struct Http2FrameHeader {
    Http2StreamId streamid;
    uint32_t length;
};

struct Http2Frame {
    Http2FrameHeader header() const { return Http2FrameHeader(); }
    struct Reader {
        void memcpy(void* buf, size_t len, size_t offset) const {}
    };
    const Reader* reader() const { return nullptr; }
};

struct Http2Priority {
    Http2StreamId stream_dependency;
    uint8_t weight;
    bool exclusive_flag;
};

struct Http2DependencyTree {
    struct Node {};
    Node* find(Http2StreamId stream_id) { return nullptr; }
    void reprioritize(Node* node, Http2StreamId stream_dependency, bool exclusive_flag) {}
    void dump_tree(std::stringstream& output) {}
    size_t size() { return 0; }
    void add(Http2StreamId stream_dependency, Http2StreamId stream_id, uint8_t weight, bool exclusive_flag, void*) {}
};

struct Http2ConnectionState {
    struct Session {
        int64_t get_connection_id() { return 0; }
    };
    Session* session;
    bool get_zombie_event() { return false; }
    void increment_received_priority_frame_count() {}
    uint32_t get_received_priority_frame_count() { return 0; }
    uint32_t configured_max_priority_frames_per_minute;
    Http2DependencyTree* dependency_tree;
    uint32_t get_client_stream_count() { return 0; }
};

struct Http2 {
    static bool stream_priority_enabled;
    static uint32_t max_concurrent_streams_in;
    static uint32_t max_priority_frames_per_minute;
};

#define HTTP2_PRIORITY_LEN 5
#define HTTP2_STAT_MAX_PRIORITY_FRAMES_PER_MINUTE_EXCEEDED 0

struct iovec {
    void* iov_base;
    size_t iov_len;
};

inline iovec make_iovec(const void* base, size_t len) {
    return {const_cast<void*>(base), len};
}

inline bool http2_parse_priority_parameter(iovec, Http2Priority&) { return true; }

class this_ethread {
public:
    static this_ethread& get() { static this_ethread instance; return instance; }
};

#define HTTP2_INCREMENT_THREAD_DYN_STAT(stat, thread) (void)0
#define Warning(...) (void)0
#define Debug(...) (void)0
#define is_debug_tag_set(tag) false
#define Http2StreamDebug(...) (void)0