#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>

typedef uint32_t (*fuzz_fn_t)(void* fuzz_ctx, void* cnx, uint8_t* bytes, uint32_t send_buffer_max, uint32_t length, uint32_t header_length);

typedef struct picoquic_quic_t {
    fuzz_fn_t fuzz_fn;
    void* fuzz_ctx;
    void* F_log;
} picoquic_quic_t;

typedef struct picoquic_cnx_t {
    picoquic_quic_t* quic;
} picoquic_cnx_t;

typedef struct picoquic_path_t {
    struct sockaddr_storage local_addr;
} picoquic_path_t;

typedef struct picoquic_packet_header {
    int ptype;
} picoquic_packet_header;

typedef enum picoquic_packet_type_enum {
    picoquic_packet_1rtt_protected_phi0,
    picoquic_packet_1rtt_protected_phi1
} picoquic_packet_type_enum;

size_t picoquic_aead_get_checksum_length(void* aead_context);
uint32_t picoquic_create_packet_header(picoquic_cnx_t* cnx, picoquic_packet_type_enum ptype, picoquic_path_t* path_x, uint64_t sequence_number, uint8_t* send_buffer, uint32_t* pn_offset, uint32_t* pn_length);
void picoquic_update_payload_length(uint8_t* send_buffer, uint32_t pn_offset, uint32_t h_length_minus_pn, uint32_t payload_length);
void picoquic_parse_packet_header(picoquic_quic_t* quic, uint8_t* send_buffer, uint32_t length, struct sockaddr* local_addr, picoquic_packet_header* ph, picoquic_cnx_t** pcnx, bool flag);
size_t picoquic_aead_encrypt_generic(uint8_t* output, uint8_t* input, size_t input_length, uint64_t sequence_number, uint8_t* header, size_t header_length, void* aead_context);
void picoquic_log_outgoing_segment(void* F_log, int flag, picoquic_cnx_t* cnx, uint8_t* bytes, uint64_t sequence_number, uint32_t length, uint8_t* send_buffer, uint32_t send_length);
void picoquic_hp_encrypt(void* pn_enc, uint8_t* sample, uint8_t* mask, uint8_t* output_mask, size_t mask_length);