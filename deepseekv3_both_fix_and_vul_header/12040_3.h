#include <cstdint>
#include <cstddef>

#define HTTP2_PING_LEN 8
#define HTTP2_FLAGS_PING_ACK 0x1

enum class Http2ErrorClass {
    HTTP2_ERROR_CLASS_NONE,
    HTTP2_ERROR_CLASS_CONNECTION
};

enum class Http2ErrorCode {
    HTTP2_ERROR_PROTOCOL_ERROR,
    HTTP2_ERROR_FRAME_SIZE_ERROR,
    HTTP2_ERROR_ENHANCE_YOUR_CALM
};

struct Http2Error {
    Http2ErrorClass error_class;
    Http2ErrorCode error_code;
    const char *message;
    
    Http2Error(Http2ErrorClass cls, Http2ErrorCode code, const char *msg = nullptr)
        : error_class(cls), error_code(code), message(msg) {}
    Http2Error(Http2ErrorClass cls)
        : error_class(cls), error_code(Http2ErrorCode::HTTP2_ERROR_PROTOCOL_ERROR), message(nullptr) {}
};

using Http2StreamId = uint32_t;

class Http2ConnectionState {
public:
    void schedule_zombie_event();
    void increment_received_ping_frame_count();
    unsigned get_received_ping_frame_count() const;
    void send_ping_frame(Http2StreamId stream_id, uint8_t flags, const uint8_t *opaque_data);
    unsigned configured_max_ping_frames_per_minute;
    void *session;
};

class Http2Frame {
public:
    struct Header {
        Http2StreamId streamid;
        uint32_t length;
        uint8_t flags;
    };
    
    const Header& header() const { return _header; }
    
    class Reader {
    public:
        void memcpy(void *dest, size_t len, size_t offset) const;
    };
    
    const Reader* reader() const;
    
private:
    Header _header;
};

class Http2 {
public:
    static unsigned max_ping_frames_per_minute;
};

void Http2StreamDebug(void *session, Http2StreamId stream_id, const char *fmt, ...);
void *this_ethread();

#define HTTP2_INCREMENT_THREAD_DYN_STAT(stat, thread)
#define HTTP2_STAT_MAX_PING_FRAMES_PER_MINUTE_EXCEEDED 0