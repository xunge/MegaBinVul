#include <stddef.h>

enum mosquitto_msg_state {
    mosq_ms_publish_qos0,
    mosq_ms_publish_qos1,
    mosq_ms_publish_qos2
};

struct mosquitto_client_msg {
    struct mosquitto_client_msg *next;
    int qos;
    int dup;
    enum mosquitto_msg_state state;
};

enum mosquitto_msg_direction {
    mosq_md_in,
    mosq_md_out
};

struct mosquitto_msg_in {
    struct mosquitto_client_msg *inflight;
    struct mosquitto_client_msg *queued;
    size_t inflight_bytes;
    size_t inflight_bytes12;
    size_t inflight_count;
    size_t inflight_count12;
    size_t queued_bytes;
    size_t queued_bytes12;
    size_t queued_count;
    size_t queued_count12;
    size_t inflight_quota;
    size_t inflight_maximum;
};

struct mosquitto {
    struct mosquitto_msg_in msgs_in;
};

#define DL_FOREACH_SAFE(head, el, tmp) \
    for((el) = (head); (el) && ((tmp) = (el)->next, 1); (el) = (tmp))

#define MOSQ_ERR_SUCCESS 0

static void db__msg_add_to_inflight_stats(struct mosquitto_msg_in *msgs_in, struct mosquitto_client_msg *msg);
static void util__decrement_receive_quota(struct mosquitto *context);
static void db__message_remove_from_inflight(struct mosquitto_msg_in *msgs_in, struct mosquitto_client_msg *msg);
static void db__msg_add_to_queued_stats(struct mosquitto_msg_in *msgs_in, struct mosquitto_client_msg *msg);
static int db__ready_for_flight(struct mosquitto *context, enum mosquitto_msg_direction dir, int qos);
static void db__message_dequeue_first(struct mosquitto *context, struct mosquitto_msg_in *msgs_in);