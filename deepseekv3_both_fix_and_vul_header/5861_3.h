#include <stdlib.h>

typedef struct Buffer Buffer;
typedef struct Monitor Monitor;
typedef struct Authctxt Authctxt;

struct Buffer {
    /* buffer implementation */
};

struct Monitor {
    int m_recvfd;
};

struct Authctxt {
    char *user;
};

extern Monitor *pmonitor;
extern void buffer_init(Buffer *);
extern void buffer_put_cstring(Buffer *, const char *);
extern void mm_request_send(int, int, Buffer *);
extern void mm_request_receive_expect(int, int, Buffer *);
extern int buffer_get_int(Buffer *);
extern void buffer_free(Buffer *);
extern void debug3(const char *, ...);

#define MONITOR_REQ_PAM_INIT_CTX 0
#define MONITOR_ANS_PAM_INIT_CTX 0