#include <stdint.h>
#include <string.h>

#define NGHTTP2_HD_DEFAULT_MAX_DEFLATE_BUFFER_SIZE 4096
#define NGHTTP2_ERR_NOMEM -901
#define NGHTTP2_STREAM_FLAG_NONE 0
#define NGHTTP2_STREAM_IDLE 0
#define NGHTTP2_DEFAULT_WEIGHT 16
#define NGHTTP2_INITIAL_CONNECTION_WINDOW_SIZE 65535
#define NGHTTP2_GOAWAY_NONE 0
#define NGHTTP2_DEFAULT_MAX_CONCURRENT_STREAMS 100
#define NGHTTP2_MAX_INCOMING_RESERVED_STREAMS 100
#define NGHTTP2_MAX_HEADERSLEN 65536
#define NGHTTP2_DEFAULT_MAX_OBQ_FLOOD_ITEM 1000
#define NGHTTP2_DEFAULT_MAX_SETTINGS 32
#define NGHTTP2_OPTMASK_NO_AUTO_WINDOW_UPDATE (1 << 0)
#define NGHTTP2_OPTMASK_NO_RECV_CLIENT_MAGIC (1 << 1)
#define NGHTTP2_OPTMASK_NO_HTTP_MESSAGING (1 << 2)
#define NGHTTP2_OPTMASK_NO_AUTO_PING_ACK (1 << 3)
#define NGHTTP2_OPTMASK_NO_CLOSED_STREAMS (1 << 4)
#define NGHTTP2_OPTMASK_SERVER_FALLBACK_RFC7540_PRIORITIES (1 << 5)
#define NGHTTP2_OPTMASK_NO_RFC9113_LEADING_AND_TRAILING_WS_VALIDATION (1 << 6)
#define NGHTTP2_FRAMEBUF_CHUNKLEN 4096
#define NGHTTP2_FRAME_HDLEN 9
#define NGHTTP2_CLIENT_MAGIC_LEN 24
#define NGHTTP2_IB_READ_CLIENT_MAGIC 0
#define NGHTTP2_IB_READ_FIRST_SETTINGS 1
#define NGHTTP2_OB_SEND_CLIENT_MAGIC 0
#define NGHTTP2_EXTPRI_URGENCY_LEVELS 8
#define NGHTTP2_DEFAULT_STREAM_RESET_BURST 100
#define NGHTTP2_DEFAULT_STREAM_RESET_RATE 30

#define NGHTTP2_OPT_NO_AUTO_WINDOW_UPDATE (1 << 0)
#define NGHTTP2_OPT_PEER_MAX_CONCURRENT_STREAMS (1 << 1)
#define NGHTTP2_OPT_MAX_RESERVED_REMOTE_STREAMS (1 << 2)
#define NGHTTP2_OPT_NO_RECV_CLIENT_MAGIC (1 << 3)
#define NGHTTP2_OPT_NO_HTTP_MESSAGING (1 << 4)
#define NGHTTP2_OPT_USER_RECV_EXT_TYPES (1 << 5)
#define NGHTTP2_OPT_BUILTIN_RECV_EXT_TYPES (1 << 6)
#define NGHTTP2_OPT_NO_AUTO_PING_ACK (1 << 7)
#define NGHTTP2_OPT_MAX_SEND_HEADER_BLOCK_LENGTH (1 << 8)
#define NGHTTP2_OPT_MAX_DEFLATE_DYNAMIC_TABLE_SIZE (1 << 9)
#define NGHTTP2_OPT_NO_CLOSED_STREAMS (1 << 10)
#define NGHTTP2_OPT_MAX_OUTBOUND_ACK (1 << 11)
#define NGHTTP2_OPT_MAX_SETTINGS (1 << 12)
#define NGHTTP2_OPT_SERVER_FALLBACK_RFC7540_PRIORITIES (1 << 13)
#define NGHTTP2_OPT_NO_RFC9113_LEADING_AND_TRAILING_WS_VALIDATION (1 << 14)
#define NGHTTP2_OPT_STREAM_RESET_RATE_LIMIT (1 << 15)

typedef struct nghttp2_session_callbacks nghttp2_session_callbacks;
typedef struct nghttp2_option nghttp2_option;
typedef struct nghttp2_mem nghttp2_mem;
typedef struct nghttp2_stream nghttp2_stream;
typedef struct nghttp2_inbound_frame nghttp2_inbound_frame;
typedef struct nghttp2_active_outbound_item nghttp2_active_outbound_item;
typedef struct nghttp2_hd_deflater nghttp2_hd_deflater;
typedef struct nghttp2_hd_inflater nghttp2_hd_inflater;
typedef struct nghttp2_bufs nghttp2_bufs;
typedef struct nghttp2_map nghttp2_map;
typedef struct nghttp2_pq nghttp2_pq;
typedef struct nghttp2_ratelim nghttp2_ratelim;
typedef struct nghttp2_settings nghttp2_settings;
typedef struct nghttp2_scheduler nghttp2_scheduler;
typedef struct nghttp2_session nghttp2_session;

struct nghttp2_mem {
    void *(*malloc)(size_t size);
    void *(*calloc)(size_t nmemb, size_t size);
    void *(*realloc)(void *ptr, size_t size);
    void (*free)(void *ptr);
};

struct nghttp2_pq {
    void *ptr;
    size_t size;
    size_t capacity;
};

struct nghttp2_settings {
    uint32_t max_concurrent_streams;
};

struct nghttp2_scheduler {
    nghttp2_pq ob_data;
};

struct nghttp2_stream {
    int dummy;
};

struct nghttp2_ratelim {
    int dummy;
};

struct nghttp2_hd_deflater {
    int dummy;
};

struct nghttp2_hd_inflater {
    int dummy;
};

struct nghttp2_bufs {
    int dummy;
};

struct nghttp2_active_outbound_item {
    nghttp2_bufs framebufs;
    uint8_t state;
};

struct nghttp2_map {
    int dummy;
};

struct nghttp2_inbound_frame {
    uint8_t state;
    size_t payloadleft;
};

struct nghttp2_option {
    uint32_t opt_set_mask;
    int no_auto_window_update;
    uint32_t peer_max_concurrent_streams;
    uint32_t max_reserved_remote_streams;
    int no_recv_client_magic;
    int no_http_messaging;
    uint8_t user_recv_ext_types[256];
    uint32_t builtin_recv_ext_types;
    int no_auto_ping_ack;
    size_t max_send_header_block_length;
    size_t max_deflate_dynamic_table_size;
    int no_closed_streams;
    size_t max_outbound_ack;
    size_t max_settings;
    int server_fallback_rfc7540_priorities;
    int no_rfc9113_leading_and_trailing_ws_validation;
    size_t stream_reset_burst;
    size_t stream_reset_rate;
};

struct nghttp2_session_callbacks {
    int dummy;
};

struct nghttp2_session {
    nghttp2_mem mem;
    nghttp2_stream root;
    uint32_t remote_window_size;
    uint32_t recv_window_size;
    uint32_t consumed_size;
    uint32_t recv_reduction;
    uint32_t local_window_size;
    uint8_t goaway_flags;
    int32_t local_last_stream_id;
    int32_t remote_last_stream_id;
    uint32_t pending_local_max_concurrent_stream;
    uint8_t pending_enable_push;
    uint8_t pending_no_rfc7540_priorities;
    nghttp2_ratelim stream_reset_ratelim;
    uint8_t server;
    nghttp2_settings remote_settings;
    nghttp2_settings local_settings;
    uint32_t max_incoming_reserved_streams;
    size_t max_send_header_block_length;
    size_t max_outbound_ack;
    size_t max_settings;
    uint32_t opt_flags;
    uint8_t user_recv_ext_types[256];
    uint32_t builtin_recv_ext_types;
    nghttp2_hd_deflater hd_deflater;
    nghttp2_hd_inflater hd_inflater;
    nghttp2_active_outbound_item aob;
    nghttp2_map streams;
    nghttp2_session_callbacks callbacks;
    void *user_data;
    nghttp2_inbound_frame iframe;
    nghttp2_scheduler sched[NGHTTP2_EXTPRI_URGENCY_LEVELS];
};

extern const uint8_t NGHTTP2_CLIENT_MAGIC[24];
extern int nghttp2_enable_strict_preface;

void nghttp2_stream_init(nghttp2_stream *stream, int32_t stream_id, uint8_t flags,
                         uint8_t state, uint32_t weight, int32_t remote_initial_window_size,
                         int32_t local_initial_window_size, void *stream_user_data,
                         nghttp2_mem *mem);
void nghttp2_ratelim_init(nghttp2_ratelim *rl, size_t burst, size_t rate);
void nghttp2_hd_deflate_free(nghttp2_hd_deflater *deflater);
void nghttp2_hd_inflate_free(nghttp2_hd_inflater *inflater);
void nghttp2_mem_free(nghttp2_mem *mem, void *ptr);
void *nghttp2_mem_calloc(nghttp2_mem *mem, size_t nmemb, size_t size);
nghttp2_mem *nghttp2_mem_default(void);
int nghttp2_hd_deflate_init2(nghttp2_hd_deflater *deflater, size_t max_deflate_dynamic_table_size,
                             nghttp2_mem *mem);
int nghttp2_hd_inflate_init(nghttp2_hd_inflater *inflater, nghttp2_mem *mem);
int nghttp2_bufs_init3(nghttp2_bufs *bufs, size_t chunk_length, size_t max_chunk,
                       size_t offset, size_t chunk_keep, nghttp2_mem *mem);
void nghttp2_map_init(nghttp2_map *map, nghttp2_mem *mem);
void nghttp2_pq_init(nghttp2_pq *pq, int (*less)(const void *, const void *),
                     nghttp2_mem *mem);
void nghttp2_bufs_add(nghttp2_bufs *bufs, const uint8_t *data, size_t len);
void active_outbound_item_reset(nghttp2_active_outbound_item *aob, nghttp2_mem *mem);
void session_inbound_frame_reset(nghttp2_session *session);
void init_settings(nghttp2_settings *settings);
int stream_less(const void *lhs, const void *rhs);