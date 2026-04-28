#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct cell_t {
    uint8_t command;
    char payload[];
} cell_t;

typedef struct circuit_t {
    int purpose;
    int deliver_window;
    int package_window;
    uint64_t dirreq_id;
    void *n_hop;
    void *n_chan;
    void *n_chan_create_cell;
    unsigned n_circ_id;
} circuit_t;

typedef struct connection_t {
    int type;
    int state;
    int marked_for_close;
    int s;
} connection_t;

typedef struct edge_connection_t {
    connection_t base_;
    int stream_id;
    int deliver_window;
    int package_window;
    int edge_has_sent_end;
    int end_reason;
} edge_connection_t;

typedef struct crypt_path_t {
    int deliver_window;
    int package_window;
    struct crypt_path_t *prev;
} crypt_path_t;

typedef struct relay_header_t {
    uint8_t command;
    uint16_t stream_id;
    uint16_t length;
} relay_header_t;

typedef struct or_circuit_t {
    struct {
        uint64_t dirreq_id;
    } *p_chan;
} or_circuit_t;

typedef struct origin_circuit_t {
    crypt_path_t *cpath;
} origin_circuit_t;

typedef struct socks_request_t {
    int has_finished;
} socks_request_t;

typedef struct entry_connection_t {
    socks_request_t *socks_request;
} entry_connection_t;

typedef struct extended_cell_t {
    void *created_cell;
} extended_cell_t;

typedef struct ratelim_t {
    int interval;
} ratelim_t;

#define LD_APP 0
#define LD_EXIT 1
#define LD_PROTOCOL 2
#define LD_BUG 3
#define END_CIRC_REASON_TORPROTOCOL 0
#define END_STREAM_REASON_TORPROTOCOL 0
#define END_STREAM_REASON_MISC 0
#define RELAY_PAYLOAD_SIZE 498
#define RELAY_HEADER_SIZE 11
#define CIRCWINDOW_INCREMENT 100
#define CIRCWINDOW_START_MAX 1000
#define STREAMWINDOW_INCREMENT 50
#define CELL_RELAY_EARLY 0
#define CELL_RELAY 1
#define CONN_TYPE_EXIT 0
#define CONN_TYPE_AP 1
#define EXIT_CONN_STATE_CONNECTING 0
#define EXIT_CONN_STATE_RESOLVING 1
#define CIRCUIT_PURPOSE_S_REND_JOINED 0
#define CIRCUIT_PURPOSE_OR 1
#define CIRCUIT_STATE_OPEN 0
#define END_CIRC_REASON_REQUESTED 0
#define END_STREAM_REASON_FLAG_REMOTE (1 << 0)
#define EARLY_WARNING_INTERVAL 3600

enum {
    RELAY_COMMAND_BEGIN,
    RELAY_COMMAND_DATA,
    RELAY_COMMAND_END,
    RELAY_COMMAND_CONNECTED,
    RELAY_COMMAND_SENDME,
    RELAY_COMMAND_EXTEND,
    RELAY_COMMAND_EXTENDED,
    RELAY_COMMAND_TRUNCATE,
    RELAY_COMMAND_TRUNCATED,
    RELAY_COMMAND_RESOLVE,
    RELAY_COMMAND_RESOLVED,
    RELAY_COMMAND_BEGIN_DIR,
    RELAY_COMMAND_EXTEND2,
    RELAY_COMMAND_EXTENDED2,
    RELAY_COMMAND_DROP,
    RELAY_COMMAND_ESTABLISH_INTRO,
    RELAY_COMMAND_ESTABLISH_RENDEZVOUS,
    RELAY_COMMAND_INTRODUCE1,
    RELAY_COMMAND_INTRODUCE2,
    RELAY_COMMAND_INTRODUCE_ACK,
    RELAY_COMMAND_RENDEZVOUS1,
    RELAY_COMMAND_RENDEZVOUS2,
    RELAY_COMMAND_INTRO_ESTABLISHED,
    RELAY_COMMAND_RENDEZVOUS_ESTABLISHED
};

#define TOR_SOCKET_T_FORMAT "%d"
#define LOG_DEBUG 0
#define LOG_PROTOCOL_WARN 1
#define LOG_WARN 2
#define LOG_INFO 3
#define LOG_BUG 4

static int stats_n_data_cells_received;
static int stats_n_data_bytes_received;

#define tor_assert(expr) (void)(expr)
#define log_fn(severity, domain, ...) (void)(severity, domain)
#define log_debug(domain, ...) (void)(domain)
#define log_info(domain, ...) (void)(domain)
#define log_warn(domain, ...) (void)(domain)
#define TO_CONN(conn) ((connection_t*)(conn))
#define TO_ORIGIN_CIRCUIT(circ) ((origin_circuit_t*)(circ))
#define TO_OR_CIRCUIT(circ) ((or_circuit_t*)(circ))
#define EDGE_TO_ENTRY_CONN(conn) ((entry_connection_t*)(conn))
#define RATELIM_INIT(interval) {interval}

static int connection_state_is_open(connection_t *conn);
static void relay_header_unpack(relay_header_t *rh, const char *payload);
static int connection_edge_process_relay_cell_not_open(relay_header_t *rh, cell_t *cell, circuit_t *circ, edge_connection_t *conn, crypt_path_t *layer_hint);
static int connection_exit_begin_conn(cell_t *cell, circuit_t *circ);
static void connection_edge_end(edge_connection_t *conn, int reason);
static void connection_mark_for_close(void *conn);
static void circuit_consider_sending_sendme(circuit_t *circ, crypt_path_t *layer_hint);
static void connection_write_to_buf(const char *data, size_t len, void *conn);
static void connection_edge_consider_sending_sendme(edge_connection_t *conn);
static int connection_edge_package_raw_inbuf(edge_connection_t *conn, int package_partial, size_t *max_to_package);
static int circuit_extend(cell_t *cell, circuit_t *circ);
static int extended_cell_parse(extended_cell_t *cell, int command, const uint8_t *body, size_t body_len);
static int circuit_finish_handshake(origin_circuit_t *circ, void *created_cell);
static int circuit_send_next_onion_skin(origin_circuit_t *circ);
static void extend_info_free(void *info);
static void circuit_set_state(circuit_t *circ, int state);
static void circuit_clear_cell_queue(circuit_t *circ, void *chan);
static void channel_send_destroy(unsigned circ_id, void *chan, uint8_t reason);
static void circuit_set_n_circid_chan(circuit_t *circ, unsigned id, void *chan);
static void relay_send_command_from_edge(int stream_id, circuit_t *circ, int command, const char *payload, size_t payload_len, crypt_path_t *layer_hint);
static void circuit_truncated(origin_circuit_t *circ, crypt_path_t *layer_hint, uint8_t reason);
static void circuit_resume_edge_reading(circuit_t *circ, crypt_path_t *layer_hint);
static void connection_start_reading(void *conn);
static int circuit_queue_streams_are_blocked(circuit_t *circ);
static void connection_exit_begin_resolve(cell_t *cell, or_circuit_t *circ);
static void rend_process_relay_cell(circuit_t *circ, crypt_path_t *layer_hint, int command, int length, const char *payload);
static const char *stream_end_reason_to_string(int reason);
static uint8_t get_uint8(const char *cp);
static void connection_mark_and_flush(void *conn);
static double approx_time(void);
static void *networkstatus_get_param(const char *ns, const char *param, int def, int min, int max);
static char *rate_limit_log(ratelim_t *lim, double now);
static void tor_free(void *ptr);