#include <stdint.h>
#include <stddef.h>

typedef struct st_picoquic_cnx_t {
    uint64_t retire_cnxid_before;
} picoquic_cnx_t;

#define PICOQUIC_RESET_SECRET_SIZE 16
#define PICOQUIC_CONNECTION_ID_MAX_SIZE 20
#define PICOQUIC_TRANSPORT_FRAME_FORMAT_ERROR 1
#define PICOQUIC_TRANSPORT_PROTOCOL_VIOLATION 2

extern uint8_t* picoquic_frames_varint_decode(uint8_t* bytes, const uint8_t* bytes_max, uint64_t* value);
extern uint8_t* picoquic_frames_uint8_decode(uint8_t* bytes, const uint8_t* bytes_max, uint8_t* value);
extern uint8_t* picoquic_frames_fixed_skip(uint8_t* bytes, const uint8_t* bytes_max, size_t length);
extern void picoquic_connection_error(picoquic_cnx_t* cnx, uint16_t error_code, uint8_t frame_type);
extern uint64_t picoquic_remove_not_before_cid(picoquic_cnx_t* cnx, uint64_t retire_before, uint64_t current_time);
extern uint64_t picoquic_enqueue_cnxid_stash(picoquic_cnx_t* cnx, uint64_t sequence, uint8_t cid_length, uint8_t* cnxid_bytes, uint8_t* secret_bytes, void* arg);
extern uint8_t picoquic_frame_type_new_connection_id;