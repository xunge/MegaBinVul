#include <stdint.h>
#include <stddef.h>

struct mosquitto;
struct mosquitto_msg_store {
    uint16_t source_mid;
};
struct mosquitto_client_msg;

#define DL_FOREACH(head, el) \
    for((el) = (head); (el); (el) = (el)->next)

#define MOSQ_ERR_INVAL 1
#define MOSQ_ERR_SUCCESS 0

struct mosquitto_client_msg {
    struct mosquitto_msg_store *store;
    struct mosquitto_client_msg *next;
};

struct mosquitto_msgs_in {
    struct mosquitto_client_msg *inflight;
    struct mosquitto_client_msg *queued;
};

struct mosquitto {
    struct mosquitto_msgs_in msgs_in;
};