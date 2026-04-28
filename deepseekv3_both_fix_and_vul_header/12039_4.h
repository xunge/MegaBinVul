#include <cstdint>
#include <cinttypes>

enum Http2ErrorClass {
  HTTP2_ERROR_CLASS_NONE,
  HTTP2_ERROR_CLASS_CONNECTION
};

enum Http2ErrorCode {
  HTTP2_ERROR_ENHANCE_YOUR_CALM,
  HTTP2_ERROR_PROTOCOL_ERROR,
  HTTP2_ERROR_FRAME_SIZE_ERROR,
  HTTP2_ERROR_FLOW_CONTROL_ERROR
};

struct Http2Error {
  Http2ErrorClass error_class;
  Http2ErrorCode error_code;
  const char *message;
  
  Http2Error(Http2ErrorClass ec = HTTP2_ERROR_CLASS_NONE, Http2ErrorCode code = HTTP2_ERROR_ENHANCE_YOUR_CALM, const char *msg = nullptr)
    : error_class(ec), error_code(code), message(msg) {}
};

struct Http2FrameHeader {
  uint32_t streamid;
  uint32_t length;
  uint8_t flags;
};

struct Http2SettingsFrame;

struct Http2Session {
  void xmit(const Http2SettingsFrame& frame);
  int64_t get_connection_id() const;
};

struct Http2Frame {
  Http2FrameHeader hdr;
  const Http2FrameHeader& header() const { return hdr; }
};

struct Http2SettingsParameter {
  uint16_t id;
  uint32_t value;
};

enum Http2SettingsIdentifier {
  HTTP2_SETTINGS_INITIAL_WINDOW_SIZE
};

struct Http2ClientSettings {
  void set(Http2SettingsIdentifier id, uint32_t value);
};

struct Http2ConnectionState {
  Http2Session* session;
  unsigned configured_max_settings_frames_per_minute;
  
  void increment_received_settings_frame_count();
  unsigned get_received_settings_frame_count() const;
  void* get_zombie_event() const;
  void update_initial_rwnd(uint32_t value);
  void increment_received_settings_count(uint32_t n);
  unsigned get_received_settings_count() const;
  
  Http2ClientSettings client_settings;
};

struct Http2SettingsFrame {
  Http2SettingsFrame(uint32_t stream_id, uint8_t flags);
};

namespace Http2 {
  constexpr unsigned max_settings_per_frame = 32;
  constexpr unsigned max_settings_per_minute = 100;
  constexpr unsigned max_settings_frames_per_minute = 10;
};

#define HTTP2_SETTINGS_PARAMETER_LEN 6
#define HTTP2_FLAGS_SETTINGS_ACK 0x1
#define HTTP2_STAT_MAX_SETTINGS_FRAMES_PER_MINUTE_EXCEEDED 1
#define HTTP2_STAT_MAX_SETTINGS_PER_FRAME_EXCEEDED 2
#define HTTP2_STAT_MAX_SETTINGS_PER_MINUTE_EXCEEDED 3

typedef uint32_t Http2StreamId;

void Http2StreamDebug(Http2Session* session, Http2StreamId stream_id, const char* fmt, ...);
void Warning(const char* fmt, ...);
unsigned read_rcv_buffer(char* buf, unsigned size, unsigned offset, const Http2Frame& frame);
bool http2_parse_settings_parameter(void* iovec, Http2SettingsParameter& param);
bool http2_settings_parameter_is_valid(const Http2SettingsParameter& param);
void* make_iovec(const char* buf, unsigned len);
void* this_ethread();
void HTTP2_INCREMENT_THREAD_DYN_STAT(int stat, void* thread);

namespace Http2DebugNames {
  const char* get_settings_param_name(uint16_t id);
}