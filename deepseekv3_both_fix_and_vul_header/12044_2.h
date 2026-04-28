#include <stdint.h>
#include <string.h>

typedef struct nghttp2_mem nghttp2_mem;
typedef struct nghttp2_goaway_aux_data nghttp2_goaway_aux_data;
typedef struct nghttp2_frame nghttp2_frame;
typedef struct nghttp2_outbound_item nghttp2_outbound_item;
typedef struct nghttp2_session nghttp2_session;

struct nghttp2_mem {
    void *(*malloc)(size_t size);
    void (*free)(void *ptr);
};

struct nghttp2_goaway_aux_data {
    uint8_t flags;
};

struct nghttp2_frame {
    struct {
        int32_t last_stream_id;
        uint32_t error_code;
        uint8_t *opaque_data;
        size_t opaque_data_len;
    } goaway;
};

struct nghttp2_outbound_item {
    nghttp2_frame frame;
    struct {
        nghttp2_goaway_aux_data goaway;
    } aux_data;
};

struct nghttp2_session {
    nghttp2_mem mem;
    int32_t local_last_stream_id;
    uint8_t goaway_flags;
};

#define NGHTTP2_ERR_INVALID_ARGUMENT -1
#define NGHTTP2_ERR_NOMEM -2
#define NGHTTP2_MAX_PAYLOADLEN 16384
#define NGHTTP2_GOAWAY_SUBMITTED 0x01

int nghttp2_session_is_my_stream_id(nghttp2_session *session, int32_t stream_id);
void *nghttp2_mem_malloc(nghttp2_mem *mem, size_t size);
void nghttp2_mem_free(nghttp2_mem *mem, void *ptr);
void nghttp2_outbound_item_init(nghttp2_outbound_item *item);
void nghttp2_frame_goaway_init(nghttp2_frame *frame, int32_t last_stream_id, uint32_t error_code, const uint8_t *opaque_data, size_t opaque_data_len);
void nghttp2_frame_goaway_free(nghttp2_frame *frame, nghttp2_mem *mem);
int nghttp2_session_add_item(nghttp2_session *session, nghttp2_outbound_item *item);
int32_t nghttp2_min(int32_t a, int32_t b);