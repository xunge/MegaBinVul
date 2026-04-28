#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/uio.h>
#include <stdbool.h>

typedef enum {
    picoquic_packet_initial,
    picoquic_packet_handshake
} picoquic_packet_type_enum;

typedef enum {
    picoquic_packet_context_initial,
    picoquic_packet_context_handshake
} picoquic_packet_context_enum;

typedef enum {
    picoquic_state_server_ready,
    picoquic_state_server_handshake
} picoquic_state_enum;

typedef enum {
    picoquic_callback_almost_ready
} picoquic_callback_enum;

typedef struct picoquic_path_t {
    uint32_t send_mtu;
    uint32_t cwin;
    uint32_t bytes_in_transit;
    struct {
        uint32_t send_sequence;
        bool ack_needed;
    } pkt_ctx[2];
} picoquic_path_t;

typedef struct queue_t {
    void* data;
    struct queue_t* next;
} queue_t;

typedef struct picoquic_packet_t {
    uint8_t* bytes;
    uint32_t length;
    uint32_t offset;
    uint32_t sequence_number;
    uint64_t send_time;
    picoquic_path_t* send_path;
    uint32_t checksum_overhead;
    bool is_pure_ack;
    bool is_congestion_controlled;
    bool contains_crypto;
    picoquic_packet_type_enum ptype;
    picoquic_packet_context_enum pc;
} picoquic_packet_t;

typedef struct picoquic_cnx_t {
    picoquic_path_t* path[1];
    struct {
        void* aead_encrypt;
    } crypto_context[3];
    struct {
        void* send_queue;
    } tls_stream[3];
    queue_t* rtx_frames[2];
    void* quic;
    int (*callback_fn)(void*, int, void*, int, int, void*, void*);
    void* callback_ctx;
} picoquic_cnx_t;

typedef struct protoop_id_t {
    const char* id;
    unsigned int hash;
} protoop_id_t;

#define PICOQUIC_ERROR_FRAME_BUFFER_TOO_SMALL (-1)
#define PICOQUIC_TRANSPORT_INTERNAL_ERROR (-2)

#define PUSH_LOG_CTX(cnx, ...) 
#define POP_LOG_CTX(cnx) 

void* queue_peek(queue_t* queue);
void* queue_dequeue(queue_t* queue);
uint32_t picoquic_prepare_packet_old_context(picoquic_cnx_t* cnx, picoquic_packet_context_enum pc, picoquic_path_t* path, picoquic_packet_t* packet, size_t send_buffer_max, uint64_t current_time, uint32_t* header_length);
uint32_t picoquic_get_checksum_length(picoquic_cnx_t* cnx, int is_cleartext_mode);
int picoquic_is_tls_stream_ready(picoquic_cnx_t* cnx);
uint32_t picoquic_predict_packet_header_length(picoquic_cnx_t* cnx, picoquic_packet_type_enum packet_type, picoquic_path_t* path);
int picoquic_prepare_ack_frame(picoquic_cnx_t* cnx, uint64_t current_time, picoquic_packet_context_enum pc, uint8_t* bytes, size_t length, size_t* data_bytes);
int picoquic_prepare_crypto_hs_frame(picoquic_cnx_t* cnx, int epoch, uint8_t* bytes, size_t length, size_t* data_bytes);
int picoquic_tls_client_authentication_activated(void* quic);
void picoquic_set_cnx_state(picoquic_cnx_t* cnx, picoquic_state_enum state);
void picoquic_connection_error(picoquic_cnx_t* cnx, int error_code, int frame_type);
uint32_t picoquic_retransmit_needed(picoquic_cnx_t* cnx, picoquic_packet_context_enum pc, picoquic_path_t* path, uint64_t current_time, picoquic_packet_t* packet, size_t send_buffer_max, int* is_cleartext_mode, uint32_t* header_length, char** reason);
void picoquic_finalize_and_protect_packet(picoquic_cnx_t* cnx, picoquic_packet_t* packet, int ret, uint32_t length, uint32_t header_length, uint32_t checksum_overhead, size_t* send_length, uint8_t* send_buffer, uint32_t send_buffer_max, picoquic_path_t* path, uint64_t current_time);
void picoquic_cnx_set_next_wake_time(picoquic_cnx_t* cnx, uint64_t current_time);
const char* picoquic_log_ptype_name(picoquic_packet_type_enum packet_type);
unsigned int hash_value_str(const char* str);
void protoop_prepare_and_run_noparam(picoquic_cnx_t* cnx, protoop_id_t* pid, void* param, picoquic_packet_t* packet);