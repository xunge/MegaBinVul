#include <stdint.h>
#include <stdatomic.h>
#include <pthread.h>
#include <stdio.h>

typedef struct janus_plugin_session {
    void* plugin_handle;
} janus_plugin_session;

typedef struct janus_voicemail_session janus_voicemail_session;

extern atomic_int stopping;
extern atomic_int initialized;
extern void* sessions;
extern pthread_mutex_t sessions_mutex;

#define janus_mutex_lock(mutex) pthread_mutex_lock(mutex)
#define janus_mutex_unlock(mutex) pthread_mutex_unlock(mutex)
#define g_atomic_int_get(ptr) atomic_load(ptr)
#define g_hash_table_remove(table, key) // Stub - replace with actual hash table implementation

janus_voicemail_session *janus_voicemail_lookup_session(janus_plugin_session *handle);
void janus_voicemail_hangup_media_internal(janus_plugin_session *handle);

#define JANUS_LOG(level, format, ...) printf(format, ##__VA_ARGS__)
#define LOG_ERR 1
#define LOG_VERB 2