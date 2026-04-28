#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef struct nghttp2_mem {
    void *(*malloc)(size_t size);
    void *(*calloc)(size_t nmemb, size_t size);
    void *(*realloc)(void *ptr, size_t size);
    void (*free)(void *ptr);
} nghttp2_mem;

typedef struct nghttp2_stream {
    uint32_t stream_id;
    uint8_t flags;
    uint8_t state;
    int32_t weight;
    int32_t remote_initial_window_size;
    int32_t local_initial_window_size;
    struct nghttp2_stream *parent;
} nghttp2_stream;

typedef struct nghttp2_ratelim {
    size_t burst;
    size_t rate;
    size_t tokens;
    uint64_t last_tick;
} nghttp2_ratelim;

typedef struct nghttp2_settings {
    uint32_t max_concurrent_streams;
    uint32_t header_table_size;
    uint32_t enable_push;
    uint32_t max_window_size;
    uint32_t max_frame_size;
    uint32_t max_header_list_size;
} nghttp2_settings;

typedef struct nghttp2_hd_deflater {
    size_t max_deflate_dynamic_table_size;
} nghttp2_hd_deflater;

typedef struct nghttp2_hd_inflater {
    size_t max_inflate_dynamic_table_size;
} nghttp2_hd_inflater;

typedef struct nghttp2_bufs {
    size_t chunk_length;
    size_t chunk_keep;
    size_t chunk_overhead;
    size_t chunk_overhead_max;
} nghttp2_bufs;

typedef struct nghttp2_active_outbound_item {
    struct nghttp2_bufs framebufs;
    uint8_t state;
} nghttp2_active_outbound_item;

typedef struct nghttp2_map {
    size_t size;
} nghttp2_map;

typedef struct nghttp2_session_callbacks {
    void *user_data;
} nghttp2_session_callbacks;

typedef struct nghttp2_inbound_frame {
    uint8_t state;
    size_t payloadleft;
} nghttp2_inbound_frame;

typedef struct nghttp2_pq {
    size_t capacity;
} nghttp2_pq;

typedef struct nghttp2_session {
    struct nghttp2_mem mem;
    struct nghttp2_stream root;
    size_t remote_window_size;
    size_t recv_window_size;
    size_t consumed_size;
    size_t recv_reduction;
    size_t local_window_size;
    uint8_t goaway_flags;
    uint32_t local_last_stream_id;
    uint32_t remote_last_stream_id;
    uint32_t pending_local_max_concurrent_stream;
    uint8_t pending_enable_push;
    uint8_t pending_no_rfc7540_priorities;
    struct nghttp2_ratelim stream_reset_ratelim;
    int server;
    struct nghttp2_settings remote_settings;
    struct nghttp2_settings local_settings;
    size_t max_incoming_reserved_streams;
    size_t max_send_header_block_length;
    size_t max_outbound_ack;
    size_t max_settings;
    uint32_t opt_flags;
    uint8_t user_recv_ext_types[32];
    uint32_t builtin_recv_ext_types;
    struct nghttp2_hd_deflater hd_deflater;
    struct nghttp2_hd_inflater hd_inflater;
    struct nghttp2_active_outbound_item aob;
    struct nghttp2_map streams;
    struct nghttp2_session_callbacks callbacks;
    void *user_data;
    struct nghttp2_inbound_frame iframe;
    struct {
        struct nghttp2_pq ob_data;
    } sched[8];
} nghttp2_session;

typedef struct nghttp2_option {
    uint32_t opt_set_mask;
    int no_auto_window_update;
    uint32_t peer_max_concurrent_streams;
    size_t max_reserved_remote_streams;
    int no_recv_client_magic;
    int no_http_messaging;
    uint8_t user_recv_ext_types[32];
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
} nghttp2_option;

#define NGHTTP2_HD_DEFAULT_MAX_DEFLATE_BUFFER_SIZE 4096
#define NGHTTP2_ERR_NOMEM -901
#define NGHTTP2_STREAM_FLAG_NONE 0
#define NGHTTP2_STREAM_IDLE 0
#define NGHTTP2_DEFAULT_WEIGHT 16
#define NGHTTP2_INITIAL_CONNECTION_WINDOW_SIZE 65535
#define NGHTTP2_GOAWAY_NONE 0
#define NGHTTP2_DEFAULT_MAX_CONCURRENT_STREAMS 100
#define NGHTTP2_DEFAULT_STREAM_RESET_BURST 10
#define NGHTTP2_DEFAULT_STREAM_RESET_RATE 30
#define NGHTTP2_MAX_INCOMING_RESERVED_STREAMS 100
#define NGHTTP2_MAX_HEADERSLEN 65536
#define NGHTTP2_DEFAULT_MAX_OBQ_FLOOD_ITEM 1000
#define NGHTTP2_DEFAULT_MAX_SETTINGS 32
#define NGHTTP2_OPT_NO_AUTO_WINDOW_UPDATE (1U << 0)
#define NGHTTP2_OPTMASK_NO_AUTO_WINDOW_UPDATE (1U << 0)
#define NGHTTP2_OPT_PEER_MAX_CONCURRENT_STREAMS (1U << 1)
#define NGHTTP2_OPT_MAX_RESERVED_REMOTE_STREAMS (1U << 2)
#define NGHTTP2_OPT_NO_RECV_CLIENT_MAGIC (1U << 3)
#define NGHTTP2_OPTMASK_NO_RECV_CLIENT_MAGIC (1U << 1)
#define NGHTTP2_OPT_NO_HTTP_MESSAGING (1U << 4)
#define NGHTTP2_OPTMASK_NO_HTTP_MESSAGING (1U << 2)
#define NGHTTP2_OPT_USER_RECV_EXT_TYPES (1U << 5)
#define NGHTTP2_OPT_BUILTIN_RECV_EXT_TYPES (1U << 6)
#define NGHTTP2_OPT_NO_AUTO_PING_ACK (1U << 7)
#define NGHTTP2_OPTMASK_NO_AUTO_PING_ACK (1U << 3)
#define NGHTTP2_OPT_MAX_SEND_HEADER_BLOCK_LENGTH (1U << 8)
#define NGHTTP2_OPT_MAX_DEFLATE_DYNAMIC_TABLE_SIZE (1U << 9)
#define NGHTTP2_OPT_NO_CLOSED_STREAMS (1U << 10)
#define NGHTTP2_OPTMASK_NO_CLOSED_STREAMS (1U << 4)
#define NGHTTP2_OPT_MAX_OUTBOUND_ACK (1U << 11)
#define NGHTTP2_OPT_MAX_SETTINGS (1U << 12)
#define NGHTTP2_OPT_SERVER_FALLBACK_RFC7540_PRIORITIES (1U << 13)
#define NGHTTP2_OPTMASK_SERVER_FALLBACK_RFC7540_PRIORITIES (1U << 5)
#define NGHTTP2_OPT_NO_RFC9113_LEADING_AND_TRAILING_WS_VALIDATION (1U << 14)
#define NGHTTP2_OPTMASK_NO_RFC9113_LEADING_AND_TRAILING_WS_VALIDATION (1U << 6)
#define NGHTTP2_OPT_STREAM_RESET_RATE_LIMIT (1U << 15)
#define NGHTTP2_FRAMEBUF_CHUNKLEN 4096
#define NGHTTP2_FRAME_HDLEN 9
#define NGHTTP2_CLIENT_MAGIC_LEN 24
#define NGHTTP2_IB_READ_CLIENT_MAGIC 0
#define NGHTTP2_IB_READ_FIRST_SETTINGS 1
#define NGHTTP2_OB_SEND_CLIENT_MAGIC 0
#define NGHTTP2_EXTPRI_URGENCY_LEVELS 8

extern const uint8_t NGHTTP2_CLIENT_MAGIC[24];
extern int nghttp2_enable_strict_preface;

void *nghttp2_mem_default(void);
void *nghttp2_mem_calloc(nghttp2_mem *mem, size_t nmemb, size_t size);
void nghttp2_mem_free(nghttp2_mem *mem, void *ptr);
void nghttp2_stream_init(nghttp2_stream *stream, uint32_t stream_id, uint8_t flags, uint8_t state, int32_t weight, int32_t remote_initial_window_size, int32_t local_initial_window_size, nghttp2_stream *parent, nghttp2_mem *mem);
void nghttp2_ratelim_init(nghttp2_ratelim *rl, size_t burst, size_t rate);
void init_settings(nghttp2_settings *settings);
int nghttp2_hd_deflate_init2(nghttp2_hd_deflater *deflater, size_t deflate_dynamic_table_size, nghttp2_mem *mem);
int nghttp2_hd_inflate_init(nghttp2_hd_inflater *inflater, nghttp2_mem *mem);
int nghttp2_bufs_init3(nghttp2_bufs *bufs, size_t chunk_length, size_t chunk_keep, size_t chunk_overhead, size_t chunk_overhead_max, nghttp2_mem *mem);
void nghttp2_map_init(nghttp2_map *map, nghttp2_mem *mem);
void active_outbound_item_reset(nghttp2_active_outbound_item *aob, nghttp2_mem *mem);
void session_inbound_frame_reset(nghttp2_session *session);
void nghttp2_bufs_add(nghttp2_bufs *bufs, const uint8_t *data, size_t len);
void nghttp2_pq_init(nghttp2_pq *pq, int (*less)(const void *, const void *), nghttp2_mem *mem);
void nghttp2_hd_inflate_free(nghttp2_hd_inflater *inflater);
void nghttp2_hd_deflate_free(nghttp2_hd_deflater *deflater);
int stream_less(const void *lhs, const void *rhs);