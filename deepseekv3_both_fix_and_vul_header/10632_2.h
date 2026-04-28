#include <stdint.h>
#include <assert.h>
#include <stddef.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>

typedef struct cell_t {
    char *payload;
} cell_t;

typedef struct circuit_t {
    int purpose;
    unsigned long dirreq_id;
} circuit_t;

typedef struct tor_addr_t {
    uint32_t addr;
} tor_addr_t;

typedef struct edge_connection_t {
    unsigned long dirreq_id;
    struct {
        int purpose;
        uint16_t port;
        char *address;
        tor_addr_t addr;
        int state;
    } base_;
    int begincell_flags;
    int stream_id;
    int package_window;
    int deliver_window;
    void *rend_data;
    struct crypt_path_t *cpath_layer;
    struct edge_connection_t *next_stream;
    struct circuit_t *on_circuit;
} edge_connection_t;

typedef struct relay_header_t {
    int length;
    int command;
    int stream_id;
} relay_header_t;

typedef struct or_circuit_t {
    int is_first_hop;
    struct channel_t *p_chan;
    int purpose;
} or_circuit_t;

typedef struct origin_circuit_t {
    struct crypt_path_t *cpath;
    struct rend_data_t *rend_data;
    struct edge_connection_t *p_streams;
} origin_circuit_t;

typedef struct crypt_path_t {
    struct crypt_path_t *prev;
} crypt_path_t;

typedef struct or_options_t {
    int AllowSingleHopExits;
    int IPv6Exit;
} or_options_t;

typedef struct begin_cell_t {
    char *address;
    uint16_t port;
    int is_begindir;
    int flags;
} begin_cell_t;

typedef struct channel_t {
    char *identity_digest;
} channel_t;

typedef struct rend_data_t {
    int nr_streams;
} rend_data_t;

#define CIRCUIT_IS_ORIGIN(circ) 0
#define TO_OR_CIRCUIT(circ) ((or_circuit_t *)(circ))
#define TO_ORIGIN_CIRCUIT(circ) ((origin_circuit_t *)(circ))
#define RELAY_PAYLOAD_SIZE 0
#define END_CIRC_REASON_TORPROTOCOL 0
#define END_STREAM_REASON_EXITPOLICY 0
#define END_STREAM_REASON_TORPROTOCOL 0
#define END_STREAM_REASON_MISC 0
#define END_STREAM_REASON_NOTDIRECTORY 0
#define END_STREAM_REASON_INTERNAL 0
#define END_STREAM_REASON_DONE 0
#define END_STREAM_REASON_RESOLVEFAILED 0
#define END_STREAM_REASON_HIBERNATING 0
#define END_CIRC_AT_ORIGIN 0
#define CIRCUIT_PURPOSE_S_REND_JOINED 0
#define CIRCUIT_PURPOSE_OR 0
#define CONN_TYPE_EXIT 0
#define EXIT_PURPOSE_CONNECT 0
#define STREAMWINDOW_START 0
#define EXIT_CONN_STATE_CONNECTING 0
#define EXIT_CONN_STATE_RESOLVEFAILED 0
#define RELAY_COMMAND_BEGIN_DIR 0
#define BEGIN_FLAG_IPV6_PREFERRED 0
#define BEGIN_FLAG_IPV4_NOT_OK 0

#define LOG_PROTOCOL_WARN 0
#define LD_PROTOCOL 0
#define LD_REND 0
#define LD_EXIT 0
#define LD_BUG 0

#define assert_circuit_ok(circ) assert(1)
#define tor_assert(expr) assert(expr)
#define relay_header_unpack(rh, payload) (void)0
#define server_mode(options) 0
#define log_fn(level, domain, fmt, ...) (void)0
#define log_warn(domain, fmt, ...) (void)0
#define log_debug(domain, fmt, ...) (void)0
#define log_info(domain, fmt, ...) (void)0
#define relay_send_end_cell_from_edge(stream_id, circ, reason, layer_hint) (void)0
#define begin_cell_parse(cell, bcell, end_reason) 0
#define tor_free(ptr) free(ptr)
#define get_options() NULL
#define should_refuse_unknown_exits(options) 0
#define connection_or_digest_is_known_relay(digest) 0
#define safe_str(str) (str)
#define channel_get_canonical_remote_descr(chan) NULL
#define directory_permits_begindir_requests(options) 0
#define channel_get_actual_remote_address(chan) NULL
#define tor_strdup(str) strdup(str)
#define connection_edge_is_rendezvous_stream(stream) 0
#define rend_data_dup(data) NULL
#define connection_free(conn) free(conn)
#define we_are_hibernating() 0
#define channel_get_addr_if_possible(chan, addr) 0
#define tor_addr_copy(dest, src) memcpy(dest, src, sizeof(tor_addr_t))
#define tor_strlower(str) (void)0
#define pathbias_mark_use_success(circ) (void)0
#define dns_resolve(stream) 0
#define connection_exit_connect(stream) (void)0
#define connection_exit_connect_dir(stream) 0
#define rend_service_set_connection_addr_port(stream, circ) 0
#define edge_connection_new(type, af) NULL
#define TO_CONN(ptr) (ptr)