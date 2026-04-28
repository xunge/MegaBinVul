#include <stdint.h>
#include <stdatomic.h>
#include <pthread.h>

typedef struct json_t json_t;

typedef struct janus_session janus_session;
typedef struct janus_transport janus_transport;
typedef struct janus_transport_source janus_transport_source;

struct janus_transport {
    const char* (*get_package)(void);
    void (*send_message)(void*, void*, int, json_t*);
};

struct janus_transport_source {
    janus_transport *transport;
    void *instance;
};

struct janus_session {
    pthread_mutex_t mutex;
    atomic_int destroyed;
    janus_transport_source *source;
};

void json_decref(json_t *json);

#define JANUS_LOG(level, format, ...)
#define LOG_HUGE 0
#define FALSE 0