#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

typedef struct janus_refcount janus_refcount;
typedef struct janus_voicemail_session janus_voicemail_session;
typedef struct janus_voicemail_handle janus_voicemail_handle;

struct janus_refcount {
    int count;
};

struct janus_voicemail_handle {
    janus_refcount ref;
};

struct janus_voicemail_session {
    janus_refcount ref;
    janus_voicemail_handle *handle;
    char *filename;
    FILE *file;
};

#define janus_refcount_containerof(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

void janus_refcount_decrease(janus_refcount *ref);
void g_free(void *ptr);