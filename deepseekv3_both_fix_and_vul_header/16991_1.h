#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <time.h>

struct mosquitto;
struct mosquitto_msg_store;
struct mosquitto_client_msg;
struct mosquitto_msg_data;
struct mosquitto_bridge;

enum mosquitto_msg_direction {
    mosq_md_in,
    mosq_md_out
};

enum mosquitto_msg_state {
    mosq_ms_invalid,
    mosq_ms_publish_qos0,
    mosq_ms_publish_qos1,
    mosq_ms_publish_qos2,
    mosq_ms_wait_for_pubrel,
    mosq_ms_queued
};

enum mosquitto_protocol {
    mosq_p_mqtt5
};

enum bridge_start_type {
    bst_lazy
};

enum mosq_log_level {
    MOSQ_LOG_NOTICE
};

typedef struct mosquitto_property mosquitto_property;

#define MOSQ_ERR_INVAL 1
#define MOSQ_ERR_SUCCESS 0
#define MOSQ_ERR_NOMEM 2
#define INVALID_SOCKET (-1)

#define G_MSGS_DROPPED_INC()
#define DL_APPEND(head, item)
#define WITH_PERSISTENCE
#define WITH_BRIDGE

struct db_config {
    bool allow_duplicate_messages;
    bool queue_qos0_messages;
};

struct db {
    struct db_config *config;
    int persistence_changes;
    time_t now_s;
};

extern struct db db;

struct mosquitto_msg_data {
    struct mosquitto_client_msg *queued;
    struct mosquitto_client_msg *inflight;
    int inflight_count;
    int queued_count;
};

struct mosquitto {
    char *id;
    int sock;
    uint8_t max_qos;
    bool is_dropping;
    struct mosquitto_bridge *bridge;
    enum mosquitto_protocol protocol;
    struct mosquitto_msg_data msgs_out;
    struct mosquitto_msg_data msgs_in;
};

struct mosquitto_msg_store {
    char **dest_ids;
    int dest_id_count;
};

struct mosquitto_bridge {
    enum bridge_start_type start_type;
    bool clean_start_local;
    bool lazy_reconnect;
    int threshold;
};

struct mosquitto_client_msg {
    struct mosquitto_client_msg *prev;
    struct mosquitto_client_msg *next;
    struct mosquitto_msg_store *store;
    uint16_t mid;
    time_t timestamp;
    enum mosquitto_msg_direction direction;
    enum mosquitto_msg_state state;
    bool dup;
    uint8_t qos;
    bool retain;
    mosquitto_property *properties;
};

void mosquitto_property_free_all(mosquitto_property **properties);
void *mosquitto__malloc(size_t size);
void *mosquitto__realloc(void *ptr, size_t size);
char *mosquitto__strdup(const char *s);
void db__msg_store_ref_inc(struct mosquitto_msg_store *store);
void db__msg_add_to_queued_stats(struct mosquitto_msg_data *msg_data, struct mosquitto_client_msg *msg);
void db__msg_add_to_inflight_stats(struct mosquitto_msg_data *msg_data, struct mosquitto_client_msg *msg);
bool db__ready_for_flight(struct mosquitto *context, enum mosquitto_msg_direction dir, uint8_t qos);
bool db__ready_for_queue(struct mosquitto *context, uint8_t qos, struct mosquitto_msg_data *msg_data);
int db__message_write_inflight_out_latest(struct mosquitto *context);
int db__message_write_queued_out(struct mosquitto *context);
void util__decrement_send_quota(struct mosquitto *context);
void log__printf(void *unused, int level, const char *fmt, ...);