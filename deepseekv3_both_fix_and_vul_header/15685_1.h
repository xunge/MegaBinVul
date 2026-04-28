#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef void* protoop_arg_t;

typedef struct {
    uint8_t id[20];
    uint8_t id_len;
} picoquic_connection_id_t;

typedef struct {
    uint64_t sequence;
    uint64_t retire_prior_to;
    picoquic_connection_id_t connection_id;
    uint8_t stateless_reset_token[16];
} new_connection_id_frame_t;

typedef struct {
    void* protoop_inputv[2];
    int active_connection_id_count;
    struct {
        int active_connection_id_limit;
    } local_parameters;
    void* quic;
} picoquic_cnx_t;

#define PICOQUIC_CONNECTION_ID_MAX_SIZE 20
#define PICOQUIC_TRANSPORT_CONNECTION_ID_LIMIT_ERROR 0
#define PICOQUIC_TRANSPORT_FRAME_FORMAT_ERROR 0
#define picoquic_frame_type_new_connection_id 0

void protoop_save_outputs(picoquic_cnx_t* cnx, void* frame, int ack_needed, int is_retransmittable);
uint8_t* picoquic_frames_varint_decode(uint8_t* bytes, const uint8_t* bytes_max, uint64_t* value);
int picoquic_varint_skip(uint8_t* bytes);
uint8_t* picoquic_frames_uint8_decode(uint8_t* bytes, const uint8_t* bytes_max, uint8_t* value);
void picoquic_connection_error(picoquic_cnx_t* cnx, int error_code, int frame_type);
void picoquic_reinsert_by_wake_time(void* quic, picoquic_cnx_t* cnx, int current_time);
int picoquic_current_time();