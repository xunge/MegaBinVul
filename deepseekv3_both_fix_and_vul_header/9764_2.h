#include <sys/time.h>
#include <pthread.h>
#include <stdint.h>

#define REQUEST_MAGIC 0x12345678
#define USEC 1000000
#define WITH_COA
#define WITH_DETAIL
#define HAVE_PTHREAD_H

#define L_ERR 1

typedef void (*fr_event_callback_t)(void *);

typedef struct coa_request {
    void *proxy_reply;
    fr_event_callback_t next_callback;
    struct timeval next_when;
    struct timeval when;
    void *parent;
} COA_REQUEST;

typedef struct {
    int code;
} RADIUS_PACKET;

typedef struct {
    int code;
} RADIUS_PROXY;

typedef struct {
    uint32_t magic;
    COA_REQUEST *coa;
    int child_state;
    struct timeval received;
    struct {
        int max_request_time;
    } *root;
    unsigned int delay;
    struct {
        int type;
    } *listener;
    pthread_t child_pid;
    int master_state;
    unsigned int number;
    char *module;
    char *component;
    int in_request_hash;
    RADIUS_PROXY *proxy;
    RADIUS_PACKET *packet;
    struct timeval next_when;
    fr_event_callback_t next_callback;
    struct timeval when;
} REQUEST;

typedef struct {
    int type;
} rad_listener_t;

#define NO_SUCH_CHILD_PID (pthread_t)0

enum {
    REQUEST_QUEUED,
    REQUEST_RUNNING,
    REQUEST_DONE,
    REQUEST_REJECT_DELAY,
    REQUEST_CLEANUP_DELAY,
    REQUEST_PROXIED,
    REQUEST_STOP_PROCESSING
};

enum {
    RAD_LISTEN_DETAIL
};

enum {
    PW_COA_REQUEST,
    PW_DISCONNECT_REQUEST
};

extern void rad_assert(int);
extern void rad_panic(const char *);
extern void tv_add(struct timeval *, unsigned int);
extern void INSERT_EVENT(fr_event_callback_t, void *);
extern void ev_request_free(REQUEST **);
extern void request_stats_final(REQUEST *);
extern void cleanup_delay(REQUEST *);
extern void radlog(int, const char *, ...);
extern void fr_event_now(void *, struct timeval *);
extern void wait_for_child_to_die(void *);
extern void RDEBUG(const char *, ...);

extern int have_children;
extern void *el;
extern struct timeval now;