#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

typedef struct picoquic_quic_s {
    void* F_log;
    int rcv_socket;
    int rcv_tos;
} picoquic_quic_t;

typedef struct picoquic_cnx_s picoquic_cnx_t;
typedef struct picoquic_path_s picoquic_path_t;
typedef struct picoquic_packet_header_s picoquic_packet_header;
typedef struct picoquic_connection_id_s picoquic_connection_id_t;

#define PICOQUIC_ERROR_DETECTED (-1)
#define PICOQUIC_ERROR_STATELESS_RESET (-2)
#define PICOQUIC_ERROR_SPURIOUS_REPEAT (-3)
#define PICOQUIC_ERROR_DUPLICATE (-4)
#define PICOQUIC_ERROR_AEAD_CHECK (-5)
#define PICOQUIC_ERROR_INITIAL_TOO_SHORT (-6)
#define PICOQUIC_ERROR_UNEXPECTED_PACKET (-7)
#define PICOQUIC_ERROR_FNV1A_CHECK (-8)
#define PICOQUIC_ERROR_CNXID_CHECK (-9)
#define PICOQUIC_ERROR_RETRY (-10)
#define PICOQUIC_ERROR_CONNECTION_DELETED (-11)
#define PICOQUIC_ERROR_CNXID_SEGMENT (-12)

enum picoquic_state_enum {
    picoquic_state_client_init_sent,
    picoquic_state_disconnected
};

enum picoquic_packet_type_enum {
    picoquic_packet_version_negotiation,
    picoquic_packet_initial,
    picoquic_packet_retry,
    picoquic_packet_handshake,
    picoquic_packet_0rtt_protected,
    picoquic_packet_1rtt_protected_phi0,
    picoquic_packet_1rtt_protected_phi1
};

enum picoquic_packet_context_enum {
    picoquic_packet_context_initial
};

#define LOG
#define DBG_PRINTF(...)
#define PUSH_LOG_CTX(...)
#define POP_LOG_CTX(...)
#define PRIu64 "llu"

struct picoquic_connection_id_s {
    uint8_t id_len;
    uint8_t id[20];
};

struct picoquic_packet_header_s {
    enum picoquic_packet_type_enum ptype;
    int version_index;
    uint32_t vn;
    uint64_t pn64;
    int epoch;
    int pc;
    uint32_t pn;
    picoquic_connection_id_t dest_cnx_id;
    picoquic_connection_id_t srce_cnx_id;
};

struct picoquic_cnx_s {
    int client_mode;
    enum picoquic_state_enum cnx_state;
    picoquic_connection_id_t initial_cnxid;
    picoquic_path_t* path[1];
    struct {
        picoquic_connection_id_t original_destination_connection_id;
    } local_parameters;
    int remote_parameters_received;
    int processed_transport_parameter;
    struct {
        void* aead_decrypt;
        void* aead_encrypt;
    } crypto_context[3];
};

struct picoquic_path_s {
    picoquic_connection_id_t local_cnxid;
    picoquic_connection_id_t remote_cnxid;
    struct sockaddr_storage local_addr;
    socklen_t local_addr_len;
    struct {
        int ack_needed;
    } pkt_ctx[3];
};

static int PROTOOP_NOPARAM_GET_INCOMING_PATH = 0;

static void* protoop_prepare_and_run_noparam(picoquic_cnx_t* cnx, int* op, void* param, picoquic_packet_header* ph) { return NULL; }

static int picoquic_parse_header_and_decrypt(picoquic_quic_t* quic, uint8_t* bytes, uint32_t length, uint32_t packet_length,
    struct sockaddr* addr_from, uint64_t current_time, picoquic_packet_header* ph, picoquic_cnx_t** cnx, uint32_t* consumed, int* new_context_created) { return 0; }

static const char* picoquic_log_ptype_name(enum picoquic_packet_type_enum ptype) { return ""; }

static void picoquic_log_decrypted_segment(void* F_log, int a, picoquic_cnx_t* cnx, int b, picoquic_packet_header* ph, uint8_t* bytes, uint32_t consumed, int ret) {}

static int picoquic_is_connection_id_null(picoquic_connection_id_t cid) { return 0; }

static int picoquic_compare_connection_id(picoquic_connection_id_t* a, picoquic_connection_id_t* b) { return 0; }

static void picoquic_prepare_version_negotiation(picoquic_quic_t* quic, struct sockaddr* addr_from, struct sockaddr* addr_to, int if_index_to, picoquic_packet_header* ph) {}

static void picoquic_process_unexpected_cnxid(picoquic_quic_t* quic, uint32_t length, struct sockaddr* addr_from, struct sockaddr* addr_to, int if_index_to, picoquic_packet_header* ph) {}

static void picoquic_received_packet(picoquic_cnx_t* cnx, int socket, int tos) {}

static void picoquic_header_parsed(picoquic_cnx_t* cnx, picoquic_packet_header* ph, picoquic_path_t* path, uint32_t consumed) {}

static int picoquic_incoming_version_negotiation(picoquic_cnx_t* cnx, uint8_t* bytes, uint32_t length, struct sockaddr* addr_from, picoquic_packet_header* ph, uint64_t current_time) { return 0; }

static int picoquic_incoming_initial(picoquic_cnx_t** cnx, uint8_t* bytes, struct sockaddr* addr_from, struct sockaddr* addr_to, int if_index_to, picoquic_packet_header* ph, uint64_t current_time, int new_context_created) { return 0; }

static int picoquic_incoming_server_cleartext(picoquic_cnx_t* cnx, uint8_t* bytes, struct sockaddr* addr_to, int if_index_to, picoquic_packet_header* ph, uint64_t current_time) { return 0; }

static int picoquic_incoming_retry(picoquic_cnx_t* cnx, uint8_t* bytes, picoquic_packet_header* ph, uint64_t current_time) { return 0; }

static int picoquic_incoming_client_cleartext(picoquic_cnx_t* cnx, uint8_t* bytes, picoquic_packet_header* ph, uint64_t current_time) { return 0; }

static int picoquic_incoming_0rtt(picoquic_cnx_t* cnx, uint8_t* bytes, picoquic_packet_header* ph, uint64_t current_time) { return 0; }

static int picoquic_incoming_encrypted(picoquic_cnx_t* cnx, uint8_t* bytes, picoquic_packet_header* ph, struct sockaddr* addr_from, uint64_t current_time) { return 0; }

static int picoquic_incoming_stateless_reset(picoquic_cnx_t* cnx) { return 0; }

static picoquic_path_t* picoquic_get_incoming_path(picoquic_cnx_t* cnx, picoquic_packet_header* ph) { return NULL; }

static int picoquic_record_pn_received(picoquic_cnx_t* cnx, picoquic_path_t* path, int pc, uint64_t pn64, uint64_t current_time) { return 0; }

static void picoquic_cnx_set_next_wake_time(picoquic_cnx_t* cnx, uint64_t current_time) {}

static void picoquic_implicit_handshake_ack(picoquic_cnx_t* cnx, picoquic_path_t* path, int context, uint64_t current_time) {}

static void picoquic_crypto_context_free(void** ctx) {}

static void picoquic_handle_plugin_negotiation(picoquic_cnx_t* cnx) {}