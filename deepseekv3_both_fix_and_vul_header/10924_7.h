#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <syslog.h>

#define G_USEC_PER_SEC 1000000
#define FALSE 0
#define TRUE 1
#define LOG_ERR 3

typedef int64_t gint64;

typedef struct janus_plugin_session {
    void *plugin_handle;
    int stopped;
} janus_plugin_session;

typedef struct janus_plugin_rtp {
    char *buffer;
    uint16_t length;
} janus_plugin_rtp;

typedef struct janus_rtp_header {
    uint16_t seq_number;
} janus_rtp_header;

typedef struct janus_voicemail_session {
    int destroyed;
    int stopping;
    int started;
    int64_t start_time;
    void *ref;
    uint16_t seq;
    void *stream;
} janus_voicemail_session;

typedef struct janus_voicemail_message {
    void *handle;
    void *message;
    void *transaction;
    void *jsep;
} janus_voicemail_message;

typedef struct ogg_packet {
    unsigned char *packet;
    long bytes;
    long b_o_s;
    long e_o_s;
    int64_t granulepos;
    int64_t packetno;
} ogg_packet;

extern int stopping;
extern int initialized;
extern void* messages;

int g_atomic_int_get(const volatile int *atomic);
void* g_malloc(size_t size);
void g_free(void* ptr);
void g_async_queue_push(void* queue, void* data);

int64_t janus_get_monotonic_time(void);
void janus_refcount_increase(void *);
void *json_pack(const char *fmt, ...);
unsigned char *janus_rtp_payload(char *buf, uint16_t len, int *plen);
ogg_packet *op_from_pkt(const unsigned char *payload, int plen);
void ogg_stream_packetin(void *os, ogg_packet *op);
void ogg_write(janus_voicemail_session *session);

void janus_voicemail_incoming_rtp(janus_plugin_session *handle, janus_plugin_rtp *packet);