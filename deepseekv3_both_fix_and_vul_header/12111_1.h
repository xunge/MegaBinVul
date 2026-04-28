#include <sys/types.h>
#include <errno.h>
#include <pthread.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#ifdef WIN32
#include <winsock2.h>
#endif

#define MOSQ_ERR_INVAL 1
#define MOSQ_ERR_NO_CONN 2
#define MOSQ_ERR_SUCCESS 0
#define MOSQ_ERR_CONN_LOST 3
#define MOSQ_ERR_ERRNO 4
#define CMD_PUBLISH 0x30
#define CMD_DISCONNECT 0xE0
#define COMPAT_EWOULDBLOCK EAGAIN
#define COMPAT_ECONNRESET ECONNRESET
#define COMPAT_EINTR EINTR
#define INVALID_SOCKET (-1)

struct mosquitto;
struct mosquitto__packet {
    struct mosquitto__packet *next;
    uint8_t command;
    uint32_t mid;
    uint32_t to_process;
    uint32_t pos;
    uint8_t *payload;
};

enum mosquitto_client_state {
    mosq_cs_connect_pending
};

struct mosquitto {
    int sock;
    struct mosquitto__packet *out_packet;
    struct mosquitto__packet *out_packet_last;
    struct mosquitto__packet *current_out_packet;
    pthread_mutex_t current_out_packet_mutex;
    pthread_mutex_t out_packet_mutex;
    pthread_mutex_t callback_mutex;
    pthread_mutex_t msgtime_mutex;
    int keepalive;
    time_t next_msg_out;
    bool want_connect;
    bool in_callback;
    void *userdata;
    void (*on_publish)(struct mosquitto *, void *, int);
    void (*on_publish_v5)(struct mosquitto *, void *, int, int, void *);
};

struct db {
    time_t now_s;
};

extern struct db db;
extern ssize_t net__write(struct mosquitto *mosq, uint8_t *buf, uint32_t count);
extern void packet__cleanup(struct mosquitto__packet *packet);
extern void mosquitto__free(void *ptr);
extern enum mosquitto_client_state mosquitto__get_state(struct mosquitto *mosq);
extern void do_client_disconnect(struct mosquitto *mosq, int reason, void *arg);
extern time_t mosquitto_time(void);
extern void mux__add_out(struct mosquitto *mosq);
extern void mux__remove_out(struct mosquitto *mosq);

#define G_BYTES_SENT_INC(x)
#define G_MSGS_SENT_INC(x)
#define G_PUB_MSGS_SENT_INC(x)