#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <inttypes.h>

typedef struct ogg_stream_state {
    int dummy;
} ogg_stream_state;

typedef struct ogg_packet {
    int dummy;
} ogg_packet;

typedef struct json_t {
    int dummy;
} json_t;

typedef struct janus_voicemail_message {
    void *handle;
    json_t *message;
    json_t *jsep;
    char *transaction;
} janus_voicemail_message;

typedef struct janus_voicemail_session {
    void *handle;
    char *filename;
    FILE *file;
    ogg_stream_state *stream;
    uint64_t recording_id;
    uint64_t sdp_sessid;
    int sdp_version;
    int seq;
    bool started;
    bool stopping;
    int destroyed;
    int hangingup;
} janus_voicemail_session;

typedef struct janus_gateway {
    int (*events_is_enabled)(void);
    void (*notify_event)(void *, void *, void *);
    int (*push_event)(void *, void *, char *, json_t *, json_t *);
    void (*end_session)(void *);
} janus_gateway;

struct janus_voicemail_plugin {
    int dummy;
};

extern int initialized;
extern int stopping;
extern void *messages;
extern janus_voicemail_message exit_message;
extern void *sessions_mutex;
extern bool notify_events;
extern char *recordings_base;
extern const char *sdp_template;
extern struct janus_voicemail_plugin janus_voicemail_plugin;
extern janus_gateway *gateway;

#define JANUS_LOG(level, ...)
#define LOG_VERB 0
#define LOG_ERR 1
#define JANUS_VOICEMAIL_ERROR_NO_MESSAGE 0
#define JANUS_VOICEMAIL_ERROR_INVALID_JSON 0
#define JANUS_VOICEMAIL_ERROR_MISSING_ELEMENT 0
#define JANUS_VOICEMAIL_ERROR_INVALID_ELEMENT 0
#define JANUS_VOICEMAIL_ERROR_ALREADY_RECORDING 0
#define JANUS_VOICEMAIL_ERROR_LIBOGG_ERROR 0
#define JANUS_VOICEMAIL_ERROR_IO_ERROR 0
#define JANUS_VOICEMAIL_ERROR_INVALID_STATE 0
#define JANUS_VOICEMAIL_ERROR_INVALID_REQUEST 0
#define JANUS_OK 0
#define TRUE 1
#define FALSE 0
typedef int gboolean;
typedef int64_t gint64;

static janus_voicemail_session *janus_voicemail_lookup_session(void *handle) { return NULL; }
static void janus_voicemail_message_free(janus_voicemail_message *msg) {}
static ogg_packet *op_opushead() { return NULL; }
static ogg_packet *op_opustags() { return NULL; }
static void op_free(ogg_packet *op) {}
static void ogg_flush(janus_voicemail_session *session) {}
static int g_atomic_int_get(int *atomic) { return *atomic; }
static void g_atomic_int_set(int *atomic, int value) { *atomic = value; }
static void janus_mutex_lock(void *mutex) {}
static void janus_mutex_unlock(void *mutex) {}
static janus_voicemail_message *g_async_queue_pop(void *queue) { return NULL; }
static int g_snprintf(char *str, size_t size, const char *format, ...) { return 0; }
static void *g_malloc0(size_t size) { return calloc(1, size); }
static bool json_is_object(json_t *json) { return false; }
static json_t *json_object_get(json_t *json, const char *key) { return NULL; }
static const char *json_string_value(json_t *json) { return NULL; }
static json_t *json_object() { return NULL; }
static void json_object_set_new(json_t *json, const char *key, json_t *value) {}
static json_t *json_string(const char *value) { return NULL; }
static json_t *json_integer(int value) { return NULL; }
static void json_decref(json_t *json) {}
static json_t *json_pack(const char *fmt, ...) { return NULL; }
static bool json_is_true(json_t *json) { return false; }
static int janus_get_real_time() { return (int)time(NULL); }
static int janus_get_codec_pt(const char *sdp, const char *codec) { return 0; }
static int64_t janus_get_monotonic_time() { return 0; }
static const char *janus_get_api_error(int error) { return ""; }
static size_t g_strlcat(char *dst, const char *src, size_t size) { return 0; }
static int ogg_stream_init(ogg_stream_state *os, int serialno) { return 0; }
static int ogg_stream_packetin(ogg_stream_state *os, ogg_packet *op) { return 0; }
static void ogg_stream_destroy(ogg_stream_state *os) {}
#define JANUS_VALIDATE_JSON_OBJECT(root, params, error_code, error_cause, mandatory, missing_element, invalid_element)