#include <stdint.h>
#include <inttypes.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct janus_plugin_session janus_plugin_session;

typedef struct janus_voicemail_session {
    janus_plugin_session *handle;
    uint64_t recording_id;
    int64_t start_time;
    void *stream;
    char *filename;
    FILE *file;
    uint16_t seq;
    bool started;
    bool stopping;
    atomic_int hangingup;
    atomic_int destroyed;
    atomic_int ref;
} janus_voicemail_session;

struct janus_plugin_session {
    void *plugin_handle;
};

extern atomic_int stopping;
extern atomic_int initialized;
extern char* recordings_path;
extern void* sessions;
extern void* sessions_mutex;

#define FALSE false
#define TRUE true

static inline int g_atomic_int_get(const atomic_int* ptr) { return atomic_load(ptr); }
static inline void g_atomic_int_set(atomic_int* ptr, int val) { atomic_store(ptr, val); }
static inline void* g_malloc0(size_t size) { return calloc(1, size); }
static inline char* g_strdup(const char* str) { return strdup(str); }
static inline int g_snprintf(char* str, size_t size, const char* format, ...) {
    va_list args;
    va_start(args, format);
    int ret = vsnprintf(str, size, format, args);
    va_end(args);
    return ret;
}

uint64_t janus_random_uint64(void);
void janus_refcount_init(atomic_int *ref, void (*callback)(void));
void janus_mutex_lock(void *mutex);
void janus_mutex_unlock(void *mutex);
void janus_voicemail_session_free(void);
void g_hash_table_insert(void* hash_table, void* key, void* value);