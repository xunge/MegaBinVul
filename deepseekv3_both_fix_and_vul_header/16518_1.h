#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

typedef struct picoquic_cnx_t {
    int client_mode;
    void* quic;
    void* initial_cnxid;
    int (*callback_fn)(void*, uint64_t, void*, size_t, int, void*, void*);
    void* callback_ctx;
} picoquic_cnx_t;

typedef struct picoquic_stream_head_t {
    uint64_t stream_id;
    int stop_sending_received;
    int reset_requested;
    uint64_t remote_stop_error;
    int stop_sending_signalled;
    void* app_stream_ctx;
} picoquic_stream_head_t;

#define PICOQUIC_TRANSPORT_FRAME_FORMAT_ERROR 0
#define PICOQUIC_TRANSPORT_PROTOCOL_VIOLATION 0
#define PICOQUIC_TRANSPORT_INTERNAL_ERROR 0

#define IS_BIDIR_STREAM_ID(id) (0)
#define IS_LOCAL_STREAM_ID(id, mode) (0)

typedef enum {
    picoquic_frame_type_stop_sending
} picoquic_frame_type_enum;

typedef enum {
    picoquic_callback_stop_sending
} picoquic_callback_event_t;

uint8_t* picoquic_frames_varint_decode(uint8_t* bytes, const uint8_t* bytes_max, uint64_t* value);
void picoquic_connection_error(picoquic_cnx_t* cnx, uint32_t error_code, picoquic_frame_type_enum frame_type);
picoquic_stream_head_t* picoquic_find_or_create_stream(picoquic_cnx_t* cnx, uint64_t stream_id, int create_if_not_found);
void picoquic_log_app_message(void* quic, void* initial_cnxid, const char* fmt, ...);