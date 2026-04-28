#include <stdint.h>

typedef struct nghttp2_session nghttp2_session;
typedef struct nghttp2_frame nghttp2_frame;
typedef struct nghttp2_stream nghttp2_stream;
typedef struct nghttp2_frame_hd nghttp2_frame_hd;
typedef struct nghttp2_rst_stream nghttp2_rst_stream;

struct nghttp2_frame_hd {
    int32_t stream_id;
};

struct nghttp2_rst_stream {
    uint32_t error_code;
};

struct nghttp2_frame {
    nghttp2_frame_hd hd;
    nghttp2_rst_stream rst_stream;
};

int session_handle_invalid_connection(nghttp2_session *session, nghttp2_frame *frame, int err, const char *reason);
int session_detect_idle_stream(nghttp2_session *session, int32_t stream_id);
nghttp2_stream *nghttp2_session_get_stream(nghttp2_session *session, int32_t stream_id);
void nghttp2_stream_shutdown(nghttp2_stream *stream, int flags);
int session_call_on_frame_received(nghttp2_session *session, nghttp2_frame *frame);
int nghttp2_session_close_stream(nghttp2_session *session, int32_t stream_id, uint32_t error_code);
int nghttp2_is_fatal(int rv);

#define NGHTTP2_ERR_PROTO 0
#define NGHTTP2_SHUT_RD 1