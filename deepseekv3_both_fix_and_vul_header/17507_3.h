#include <stdbool.h>
#include <pthread.h>
#include <stdio.h>

typedef bool gboolean;
#define TRUE true
#define FALSE false

typedef struct _GstRTSPAuth {
    void *priv;
} GstRTSPAuth;

typedef struct _GstRTSPContext {
    void *request;
    void *token;
} GstRTSPContext;

typedef struct _GstRTSPToken GstRTSPToken;

typedef struct _GstRTSPAuthPrivate {
    pthread_mutex_t lock;
    GstRTSPToken *default_token;
    void *basic;
} GstRTSPAuthPrivate;

typedef struct _GstRTSPAuthCredential {
    int scheme;
    char *authorization;
    void *params;
} GstRTSPAuthCredential;

enum {
    GST_RTSP_HDR_AUTHORIZATION,
    GST_RTSP_AUTH_BASIC,
    GST_RTSP_AUTH_DIGEST
};

#define GST_DEBUG_OBJECT(a, ...) printf(__VA_ARGS__)