#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

typedef int gboolean;
#define TRUE 1
#define FALSE 0

typedef struct GList {
    void *data;
    struct GList *next;
} GList;

typedef struct GHashTable GHashTable;

typedef struct janus_sip_session {
    void *stack;
    struct {
        int require_srtp;
        int local_audio_rtp_port;
        int local_video_rtp_port;
        int has_srtp_local_audio;
        int has_srtp_local_video;
        char *audio_srtp_local_profile;
        char *audio_srtp_local_crypto;
        char *video_srtp_local_profile;
        char *video_srtp_local_crypto;
        int audio_pt;
        int video_pt;
    } media;
} janus_sip_session;

typedef struct janus_sdp_attribute {
    char *name;
    char *value;
} janus_sdp_attribute;

typedef struct janus_sdp_mline {
    char *proto;
    int type;
    int port;
    char *c_addr;
    GList *ptypes;
    GList *attributes;
} janus_sdp_mline;

typedef struct janus_sdp {
    char *c_addr;
    GList *m_lines;
} janus_sdp;

enum {
    JANUS_SDP_AUDIO,
    JANUS_SDP_VIDEO
};

#define LOG_VERB 0
#define LOG_HUGE 0
#define JANUS_LOG(level, format, ...)

#define g_free free
#define g_strdup strdup
#define g_list_append(list, data) list
#define g_list_free(list) free(list)
#define g_hash_table_new_full(hash_func, key_equal_func, key_destroy_func, value_destroy_func) NULL
#define g_hash_table_lookup(hash_table, key) NULL
#define g_hash_table_insert(hash_table, key, value)
#define GPOINTER_TO_INT(p) ((int)(intptr_t)(p))
#define GINT_TO_POINTER(i) ((void*)(intptr_t)(i))

extern char *sdp_ip;
extern char *local_media_ip;
extern char *local_ip;

void janus_sip_srtp_set_local(janus_sip_session *session, gboolean video, char **profile, char **crypto);
janus_sdp_attribute *janus_sdp_attribute_create(const char *name, const char *value, ...);
void janus_sdp_remove_payload_type(janus_sdp *sdp, int pt);
char *janus_sdp_write(janus_sdp *sdp);