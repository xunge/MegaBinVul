#include <stdbool.h>
#include <stddef.h>
#include <time.h>

typedef int mosq_sock_t;

struct mosquitto {
    int ident;
    int pollfd_index;
    mosq_sock_t sock;
    time_t last_msg_in;
    time_t next_msg_out;
    int keepalive;
    bool clean_start;
    char *id;
    int last_mid;
    void *will;
    char *username;
    char *password;
    void *listener;
    void *acl_list;
    bool retain_available;
    bool is_bridge;
    struct {
        void *payload;
    } in_packet;
    void *out_packet;
    void *current_out_packet;
    int out_packet_count;
    char *address;
    int remote_port;
    void *bridge;
    struct {
        int inflight_maximum;
        int inflight_quota;
    } msgs_in, msgs_out;
    int max_qos;
#ifdef WITH_TLS
    void *ssl;
#endif
};

struct db_t {
    time_t now_s;
    struct {
        int max_inflight_messages;
    } *config;
    struct {
        void *contexts_by_sock;
    } db;
} db;

enum mosq_client_state {
    mosq_cs_new
};

void mosquitto__set_state(struct mosquitto *context, enum mosq_client_state state);
void *mosquitto__calloc(size_t nmemb, size_t size);
char *mosquitto__strdup(const char *s);
void mosquitto__free(void *ptr);
void packet__cleanup(void *packet);
int net__socket_get_address(mosq_sock_t sock, char *address, int len, int *port);

#define WITH_EPOLL
#define id_client 0
#define HASH_ADD(hh, head, fieldname, keylen_in, add)