#include <stdint.h>
#include <inttypes.h>
#include <pthread.h>

typedef struct janus_transport {
    char* (*get_package)();
} janus_transport;

typedef struct janus_transport_session {
    void* instance;
} janus_transport_session;

typedef struct session_source {
    janus_transport_session* instance;
} session_source;

typedef struct janus_session {
    uint64_t session_id;
    int destroyed;
    int timeout;
    int transport_gone;
    time_t last_activity;
    session_source* source;
} janus_session;

typedef struct {
    void* dummy;
} GHashTableIter;
typedef void* gpointer;

extern pthread_mutex_t sessions_mutex;
extern void* sessions;
extern int reclaim_session_timeout;

#define JANUS_LOG(level, format, ...)
#define LOG_VERB 0

#define janus_mutex_lock pthread_mutex_lock
#define janus_mutex_unlock pthread_mutex_unlock
#define g_atomic_int_get(ptr) (*(ptr))
#define g_atomic_int_set(ptr, val) (*(ptr) = (val))

void janus_session_destroy(janus_session* session);
size_t g_hash_table_size(void* table);
void g_hash_table_iter_init(GHashTableIter* iter, void* table);
int g_hash_table_iter_next(GHashTableIter* iter, void* key, gpointer* value);
void g_hash_table_iter_remove(GHashTableIter* iter);