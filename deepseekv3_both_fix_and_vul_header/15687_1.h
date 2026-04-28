#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <sys/socket.h>

typedef struct picoquic_quic_s picoquic_quic_t;
typedef struct picoquic_cnx_s picoquic_cnx_t;
typedef struct picoquic_packet_header_s picoquic_packet_header;
typedef struct picoquic_path_s picoquic_path_t;

enum picoquic_packet_type_enum {
    picoquic_packet_initial,
    picoquic_packet_version_negotiation,
    picoquic_packet_retry,
    picoquic_packet_handshake,
    picoquic_packet_0rtt_protected,
    picoquic_packet_1rtt_protected_phi0,
    picoquic_packet_1rtt_protected_phi1
};

#define PICOQUIC_ENFORCED_INITIAL_MTU 1200
#define PICOQUIC_RESET_PACKET_MIN_SIZE 16
#define PICOQUIC_RESET_SECRET_SIZE 16

#define PICOQUIC_ERROR_INITIAL_TOO_SHORT -1
#define PICOQUIC_ERROR_DETECTED -2
#define PICOQUIC_ERROR_AEAD_CHECK -3
#define PICOQUIC_ERROR_DUPLICATE -4
#define PICOQUIC_ERROR_STATELESS_RESET -5

struct picoquic_packet_header_s {
    uint8_t ptype;
    uint16_t offset;
    uint16_t payload_length;
    uint64_t dest_cnx_id;
    uint64_t srce_cnx_id;
    uint32_t vn;
    uint32_t pn;
    uint64_t pn64;
    uint32_t pnmask;
};

struct picoquic_crypto_context_s {
    void* hp_dec;
    void* aead_decrypt;
};

struct picoquic_cnx_s {
    int client_mode;
    picoquic_path_t* path[1];
    struct picoquic_crypto_context_s crypto_context[4];
    uint8_t reset_secret[PICOQUIC_RESET_SECRET_SIZE];
};

struct picoquic_path_s {
    uint8_t reset_secret[PICOQUIC_RESET_SECRET_SIZE];
};

int picoquic_parse_packet_header(picoquic_quic_t* quic, uint8_t* bytes, uint32_t length, struct sockaddr* addr_from, picoquic_packet_header* ph, picoquic_cnx_t** pcnx, int flag);
size_t picoquic_decrypt_packet(picoquic_cnx_t* cnx, uint8_t* bytes, uint32_t packet_length, picoquic_packet_header* ph, void* hp_dec, void* aead_decrypt, int* already_received, picoquic_path_t* path_from);
picoquic_cnx_t* picoquic_create_cnx(picoquic_quic_t* quic, uint64_t dest_cnx_id, uint64_t srce_cnx_id, struct sockaddr* addr_from, uint64_t current_time, uint32_t vn, void* p1, void* p2, int flag);
void picoquic_delete_cnx(picoquic_cnx_t* cnx);
picoquic_cnx_t* picoquic_cnx_by_net(picoquic_quic_t* quic, struct sockaddr* addr_from);
picoquic_path_t* picoquic_get_incoming_path(picoquic_cnx_t* cnx, picoquic_packet_header* ph);