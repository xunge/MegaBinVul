#include <assert.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

struct mosquitto {
    pthread_mutex_t out_packet_mutex;
    struct mosquitto__packet *out_packet;
    struct mosquitto__packet *out_packet_last;
    unsigned int out_packet_count;
    bool is_dropping;
    char *id;
    int sockpairW;
    bool in_callback;
    int threaded;
#ifdef WITH_BROKER
    void *wsi;
#endif
};

struct mosquitto__packet {
    unsigned int pos;
    unsigned int to_process;
    unsigned int packet_length;
    struct mosquitto__packet *next;
};

extern struct {
    struct {
        int max_queued_messages;
    } *config;
} db;

#define WITH_BROKER
#define MOSQ_ERR_SUCCESS 0
#define INVALID_SOCKET (-1)
#define MOSQ_LOG_NOTICE 0

typedef enum {
    mosq_ts_none
} mosq_threaded_t;

void mosquitto__free(void *ptr);
int packet__write(struct mosquitto *mosq);
void log__printf(void *unused, int level, const char *fmt, ...);
void G_MSGS_DROPPED_INC(void);