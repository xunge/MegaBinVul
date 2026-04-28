#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

struct Buffer;
typedef struct Buffer Buffer;

struct sshpam_device {
    void *(*init_ctx)(void *);
};

struct authctxt {
    char *user;
};

struct monitor;
typedef struct monitor Monitor;

#define MONITOR_REQ_PAM_FREE_CTX 0
#define MONITOR_ANS_PAM_INIT_CTX 0

extern struct authctxt *authctxt;
extern struct sshpam_device sshpam_device;
extern void *sshpam_ctxt;
extern void *sshpam_authok;
extern Monitor *mon_dispatch;

int debug3(const char *fmt, ...);
char *buffer_get_string(Buffer *m, size_t *len);
void buffer_clear(Buffer *m);
void buffer_put_int(Buffer *m, int value);
int mm_request_send(int sock, int type, Buffer *m);
void monitor_permit(Monitor *mon, int type, int permit);