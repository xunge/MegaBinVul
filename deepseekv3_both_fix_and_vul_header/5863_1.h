#include <stddef.h>

typedef struct Buffer Buffer;
extern void buffer_clear(Buffer *);

extern struct sshpam_device {
    void (*free_ctx)(void *);
} sshpam_device;
extern void *sshpam_ctxt;
extern int sshpam_authok;
extern const char *auth_method;
extern const char *auth_submethod;

#define MONITOR_ANS_PAM_FREE_CTX 0
extern void mm_request_send(int, int, Buffer *);
extern void debug3(const char *, ...);