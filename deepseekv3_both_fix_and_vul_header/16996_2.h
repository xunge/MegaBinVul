#include <stdbool.h>
#include <stdlib.h>

struct mosquitto__packet {
    struct mosquitto__packet *next;
};

struct mosquitto {
    bool clean_start;
    void *bridge;
    char *auth_method;
    char *username;
    char *password;
    char *address;
    char *id;
    struct mosquitto__packet *in_packet;
    struct mosquitto__packet *current_out_packet;
    struct mosquitto__packet *out_packet;
    int out_packet_count;
#ifdef WITH_BROKER
#ifdef __GLIBC__
#ifdef WITH_ADNS
    struct gaicb *adns;
#endif
#endif
#endif
};

struct gaicb {
    void *ar_request;
};

void bridge__cleanup(struct mosquitto *context);
void alias__free_all(struct mosquitto *context);
void net__socket_close(struct mosquitto *context);
void sub__clean_session(struct mosquitto *context);
void db__messages_delete(struct mosquitto *context, bool force_free);
void context__send_will(struct mosquitto *context);
void context__remove_from_by_id(struct mosquitto *context);
void packet__cleanup(struct mosquitto__packet **packet);
void mosquitto__free(void *ptr);
int gai_cancel(struct gaicb *);