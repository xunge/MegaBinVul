#include <stdatomic.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct janus_plugin_session janus_plugin_session;
typedef struct janus_voicemail_session janus_voicemail_session;

extern atomic_int stopping;
extern atomic_int initialized;

#define FALSE false

#define g_atomic_int_get(ptr) atomic_load(ptr)
#define g_atomic_int_set(ptr, val) atomic_store(ptr, val)
#define g_atomic_int_compare_and_exchange(ptr, oldval, newval) atomic_compare_exchange_weak(ptr, &(int){oldval}, newval)

struct janus_voicemail_session {
    bool started;
    atomic_int destroyed;
    atomic_int hangingup;
    FILE *file;
    void *stream;
};

janus_voicemail_session *janus_voicemail_lookup_session(janus_plugin_session *handle);

#define LOG_ERR 0
#define JANUS_LOG(level, format, ...) printf(format, ##__VA_ARGS__)

void ogg_stream_destroy(void *stream);