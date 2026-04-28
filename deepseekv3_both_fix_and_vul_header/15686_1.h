#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

typedef struct picoquic_quic_t picoquic_quic_t;
typedef struct picoquic_cnx_t picoquic_cnx_t;
typedef struct picoquic_connection_id_t picoquic_connection_id_t;
typedef struct picoquic_tp_t picoquic_tp_t;
typedef struct picoquic_path_t picoquic_path_t;
typedef struct picoquic_stream_t picoquic_stream_t;

#define PICOQUIC_DEFAULT_0RTT_WINDOW 0
#define PICOQUIC_STREAM_ID_BIDIR 0
#define PICOQUIC_STREAM_ID_UNIDIR 1
#define PICOQUIC_NUMBER_OF_EPOCHS 4
#define PICOQUIC_INTEROP_VERSION_INDEX 0
#define picoquic_nb_packet_context 3
#define picoquic_state_client_init 0
#define picoquic_state_server_init 1

struct picoquic_connection_id_t {
    uint8_t id[8];
    uint8_t len;
};

struct picoquic_tp_t {
    uint32_t initial_max_data;
    uint32_t initial_max_streams_bidi;
    uint32_t initial_max_streams_uni;
    uint32_t max_packet_size;
    picoquic_connection_id_t initial_source_connection_id;
    uint32_t initial_max_stream_data_bidi_remote;
    uint32_t initial_max_stream_data_uni;
};

struct picoquic_path_t {
    picoquic_connection_id_t local_cnxid;
    picoquic_connection_id_t remote_cnxid;
    uint8_t reset_secret[16];
    int challenge_verified;
};

struct picoquic_stream_t {
    uint64_t stream_id;
    uint64_t consumed_offset;
    uint64_t fin_offset;
    struct picoquic_stream_t* next_stream;
    void* stream_data;
    uint64_t sent_offset;
    uint32_t local_error;
    uint32_t remote_error;
    uint64_t maxdata_local;
    uint64_t maxdata_remote;
    void* send_queue;
};

struct picoquic_cnx_t {
    picoquic_quic_t* quic;
    int client_mode;
    picoquic_path_t* path[1];
    uint64_t next_wake_time;
    uint64_t start_time;
    picoquic_tp_t local_parameters;
    picoquic_tp_t remote_parameters;
    uint64_t maxdata_local;
    uint64_t maxdata_remote;
    uint64_t max_stream_id_bidir_local;
    uint64_t max_stream_id_bidir_local_computed;
    uint64_t max_stream_id_unidir_local;
    uint64_t max_stream_id_unidir_local_computed;
    uint64_t max_stream_id_bidir_remote;
    uint64_t max_stream_id_unidir_remote;
    char* sni;
    char* alpn;
    void (*callback_fn)(picoquic_connection_id_t, picoquic_connection_id_t, void*, picoquic_connection_id_t*);
    void* callback_ctx;
    struct {
        void (*alg_init)(picoquic_cnx_t*, picoquic_path_t*);
    } *congestion_alg;
    uint32_t proposed_version;
    int version_index;
    int cnx_state;
    picoquic_connection_id_t initial_cnxid;
    uint64_t latest_progress_time;
    picoquic_stream_t tls_stream[PICOQUIC_NUMBER_OF_EPOCHS];
    void* reserved_frames;
    void* retry_frames;
    void* rtx_frames[picoquic_nb_packet_context];
    uint32_t core_rate;
    int active_connection_id_count;
};

struct picoquic_quic_t {
    picoquic_tp_t* default_tp;
    uint32_t mtu_max;
    void (*default_callback_fn)(void);
    void* default_callback_ctx;
    struct {
        void (*alg_init)(picoquic_cnx_t*, picoquic_path_t*);
    } *default_congestion_alg;
    void (*cnx_id_callback_fn)(picoquic_connection_id_t, picoquic_connection_id_t, void*, picoquic_connection_id_t*);
    void* cnx_id_callback_ctx;
    struct {
        size_t size;
        void** elems;
    } local_plugins;
};

static picoquic_connection_id_t picoquic_null_connection_id = { {0}, 0 };

typedef struct {
    uint32_t version;
} picoquic_version_t;

static picoquic_version_t picoquic_supported_versions[] = {
    {0}
};

static int picoquic_create_path(picoquic_cnx_t* cnx, uint64_t start_time, struct sockaddr* addr) { return 0; }
static void picoquic_insert_cnx_in_list(picoquic_quic_t* quic, picoquic_cnx_t* cnx) {}
static void picoquic_insert_cnx_by_wake_time(picoquic_quic_t* quic, picoquic_cnx_t* cnx) {}
static void picoquic_init_transport_parameters(picoquic_tp_t* tp, int client_mode) {}
static uint64_t picoquic_transport_param_to_stream_id(uint32_t param, int client_mode, int stream_type) { return 0; }
static int picoquic_is_connection_id_null(picoquic_connection_id_t cnx_id) { return 0; }
static void picoquic_create_random_cnx_id(picoquic_quic_t* quic, picoquic_connection_id_t* cnx_id, int len) {}
static int picoquic_get_version_index(uint32_t version) { return 0; }
static char* picoquic_string_duplicate(const char* str) { return NULL; }
static int picoquic_create_cnxid_reset_secret(picoquic_quic_t* quic, picoquic_connection_id_t* cnx_id, uint8_t* reset_secret) { return 0; }
static void register_protocol_operations(picoquic_cnx_t* cnx) {}
static int plugin_insert_plugins(picoquic_cnx_t* cnx, size_t size, void** elems) { return 0; }
static int picoquic_tlscontext_create(picoquic_quic_t* quic, picoquic_cnx_t* cnx, uint64_t start_time) { return 0; }
static void picoquic_delete_cnx(picoquic_cnx_t* cnx) {}
static int picoquic_setup_initial_traffic_keys(picoquic_cnx_t* cnx) { return 0; }
static int picoquic_register_cnx_id(picoquic_quic_t* quic, picoquic_cnx_t* cnx, picoquic_connection_id_t* cnx_id) { return 0; }
static int picoquic_register_net_id(picoquic_quic_t* quic, picoquic_cnx_t* cnx, struct sockaddr* addr) { return 0; }
static void* queue_init() { return NULL; }