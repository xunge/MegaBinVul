#include <stddef.h>
#include <stdint.h>

struct nghttp2_mem {
    void *(*malloc)(size_t size);
    void (*free)(void *ptr);
    void *(*calloc)(size_t nmemb, size_t size);
    void *(*realloc)(void *ptr, size_t size);
};

struct nghttp2_stream;
struct nghttp2_settings_entry;

struct nghttp2_priority_spec {
    int32_t stream_id;
    int32_t weight;
    int exclusive;
};

struct nghttp2_frame_hd {
    size_t length;
    uint8_t type;
    uint8_t flags;
    int32_t stream_id;
};

struct nghttp2_frame {
    struct nghttp2_frame_hd hd;
    struct {
        struct nghttp2_settings_entry *iv;
        size_t niv;
    } settings;
};

struct nghttp2_session {
    struct nghttp2_mem mem;
    int server;
    int32_t next_stream_id;
    int32_t last_recv_stream_id;
    int32_t last_sent_stream_id;
    int32_t last_proc_stream_id;
    size_t max_settings;
};

typedef struct nghttp2_session nghttp2_session;
typedef struct nghttp2_stream nghttp2_stream;
typedef struct nghttp2_settings_entry nghttp2_settings_entry;
typedef struct nghttp2_mem nghttp2_mem;
typedef struct nghttp2_priority_spec nghttp2_priority_spec;
typedef struct nghttp2_frame nghttp2_frame;
typedef struct nghttp2_frame_hd nghttp2_frame_hd;

#define NGHTTP2_ERR_PROTO (-1)
#define NGHTTP2_ERR_INVALID_ARGUMENT (-2)
#define NGHTTP2_ERR_TOO_MANY_SETTINGS (-3)
#define NGHTTP2_ERR_NOMEM (-4)
#define NGHTTP2_FRAME_SETTINGS_ENTRY_LENGTH 6
#define NGHTTP2_SETTINGS 0x04
#define NGHTTP2_FLAG_NONE 0x00
#define NGHTTP2_STREAM_FLAG_NONE 0x00
#define NGHTTP2_STREAM_OPENING 0x01
#define NGHTTP2_SHUT_RD 0x01
#define NGHTTP2_SHUT_WR 0x02

int nghttp2_frame_unpack_settings_payload2(nghttp2_settings_entry **iv, size_t *niv,
                                          const uint8_t *payload, size_t payloadlen,
                                          nghttp2_mem *mem);
int nghttp2_session_on_settings_received(nghttp2_session *session, nghttp2_frame *frame, int ack);
int nghttp2_submit_settings(nghttp2_session *session, uint8_t flags, nghttp2_settings_entry *iv, size_t niv);
void nghttp2_priority_spec_default_init(nghttp2_priority_spec *pri_spec);
nghttp2_stream *nghttp2_session_open_stream(nghttp2_session *session, int32_t stream_id,
                                         uint8_t flags, nghttp2_priority_spec *pri_spec,
                                         uint8_t state, void *stream_user_data);
void nghttp2_stream_shutdown(nghttp2_stream *stream, int flags);
void nghttp2_frame_hd_init(nghttp2_frame_hd *hd, size_t length, uint8_t type, uint8_t flags, int32_t stream_id);
void nghttp2_mem_free(nghttp2_mem *mem, void *ptr);