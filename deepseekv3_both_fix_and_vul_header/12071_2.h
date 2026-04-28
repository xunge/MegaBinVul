#include <stdint.h>
#include <string.h>

typedef struct nghttp2_session nghttp2_session;
typedef struct nghttp2_outbound_item nghttp2_outbound_item;
typedef struct nghttp2_frame nghttp2_frame;
typedef struct nghttp2_goaway_aux_data nghttp2_goaway_aux_data;
typedef struct nghttp2_mem nghttp2_mem;

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
    struct nghttp2_frame frame;
    struct {
        struct nghttp2_goaway_aux_data goaway;
    } aux_data;
};

struct nghttp2_session {
    struct nghttp2_mem mem;
    int32_t local_last_stream_id;
    uint8_t goaway_flags;
};

#define NGHTTP2_ERR_INVALID_ARGUMENT -1
#define NGHTTP2_ERR_NOMEM -2
#define NGHTTP2_MAX_PAYLOADLEN 16384
#define NGHTTP2_GOAWAY_SUBMITTED 0x01

extern int nghttp2_session_is_my_stream_id(struct nghttp2_session *session, int32_t stream_id);
extern void *nghttp2_mem_malloc(struct nghttp2_mem *mem, size_t size);
extern void nghttp2_mem_free(struct nghttp2_mem *mem, void *ptr);
extern void nghttp2_outbound_item_init(struct nghttp2_outbound_item *item);
extern void nghttp2_frame_goaway_init(struct nghttp2_frame *frame, int32_t last_stream_id, uint32_t error_code, const uint8_t *opaque_data, size_t opaque_data_len);
extern void nghttp2_frame_goaway_free(struct nghttp2_frame *frame, struct nghttp2_mem *mem);
extern int nghttp2_session_add_item(struct nghttp2_session *session, struct nghttp2_outbound_item *item);

static inline int32_t nghttp2_min(int32_t a, int32_t b) {
    return a < b ? a : b;
}