#include <stdint.h>
#include <stdatomic.h>
#include <pthread.h>
#include <stdbool.h>

typedef struct janus_plugin_session janus_plugin_session;
typedef struct janus_plugin janus_plugin;

typedef struct janus_callbacks {
    int (*push_event)(janus_plugin_session *handle, janus_plugin *plugin, 
                     const char *transaction, void *event, void *context);
} janus_callbacks;

extern janus_plugin janus_voicemail_plugin;
extern janus_callbacks *gateway;
extern atomic_int stopping;
extern atomic_int initialized;
extern pthread_mutex_t sessions_mutex;

typedef struct janus_voicemail_session {
    atomic_int destroyed;
    atomic_int hangingup;
    int64_t start_time;
    bool started;
    atomic_int ref;
} janus_voicemail_session;

typedef void json_t;

#define JANUS_LOG(level, format, ...)
#define LOG_INFO 0
#define LOG_ERR 0
#define LOG_VERB 0
#define JANUS_VOICEMAIL_PACKAGE ""
#define TRUE true

/* Atomic operations */
#define g_atomic_int_get(ptr) atomic_load(ptr)
#define g_atomic_int_set(ptr, val) atomic_store(ptr, val)

/* Mutex operations */
#define janus_mutex_lock(mutex) pthread_mutex_lock(mutex)
#define janus_mutex_unlock(mutex) pthread_mutex_unlock(mutex)

/* Reference counting */
#define janus_refcount_increase(ptr) atomic_fetch_add(ptr, 1)
#define janus_refcount_decrease(ptr) atomic_fetch_sub(ptr, 1)

janus_voicemail_session *janus_voicemail_lookup_session(janus_plugin_session *handle);
int64_t janus_get_monotonic_time(void);
const char *janus_get_api_error(int ret);

/* Stub JSON functions */
json_t *json_object(void);
void json_object_set_new(json_t *object, const char *key, json_t *value);
json_t *json_string(const char *value);
void json_decref(json_t *json);