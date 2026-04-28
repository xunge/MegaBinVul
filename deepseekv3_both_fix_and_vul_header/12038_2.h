#include <cstdint>
#include <cstddef>
#include <utility>

enum class Http2ErrorClass {
    HTTP2_ERROR_CLASS_NONE,
    HTTP2_ERROR_CLASS_CONNECTION
};

enum class Http2ErrorCode {
    HTTP2_ERROR_PROTOCOL_ERROR,
    HTTP2_ERROR_FRAME_SIZE_ERROR,
    HTTP2_ERROR_ENHANCE_YOUR_CALM
};

enum class ProxyErrorClass {
    TXN
};

struct Http2Error {
    Http2ErrorClass error_class;
    Http2ErrorCode error_code;
    const char* message;
    
    Http2Error(Http2ErrorClass ec, Http2ErrorCode code, const char* msg = nullptr)
        : error_class(ec), error_code(code), message(msg) {}
    Http2Error(Http2ErrorClass ec) : error_class(ec) {}
};

struct Http2FrameHeader {
    uint32_t streamid;
    uint32_t length;
    uint8_t type;
    uint8_t flags;
};

struct Http2Frame {
    Http2FrameHeader header() const;
    class Reader* reader() const;
};

struct Http2RstStream {
    uint32_t error_code;
};

using Http2StreamId = uint32_t;

struct Http2Stream {
    bool change_state(uint8_t type, uint8_t flags);
    void set_rx_error_code(std::pair<ProxyErrorClass, uint32_t>);
    void initiating_close();
};

struct Http2ConnectionState {
    Http2Stream* find_stream(Http2StreamId);
    bool is_valid_streamid(Http2StreamId);
    void increment_received_rst_stream_frame_count();
    uint32_t get_received_rst_stream_frame_count() const;
    uint32_t get_received_settings_frame_count() const;
    uint32_t configured_max_rst_stream_frames_per_minute;
    class Session* session;
};

class Session {};
class Reader {
public:
    char* memcpy(char* buf, size_t len, int);
};

struct iovec {};
iovec make_iovec(const char* buf, size_t len);
bool http2_parse_rst_stream(iovec, Http2RstStream&);

void Http2StreamDebug(Session*, Http2StreamId, const char*, ...);
void HTTP2_INCREMENT_THREAD_DYN_STAT(int, void*);
void* this_ethread();

static const size_t HTTP2_RST_STREAM_LEN = 4;
static const int HTTP2_STAT_MAX_RST_STREAM_FRAMES_PER_MINUTE_EXCEEDED = 0;