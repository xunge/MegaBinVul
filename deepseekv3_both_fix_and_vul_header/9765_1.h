#include <pthread.h>
#include <stdint.h>
#include <sys/time.h>

#define REQUEST_MAGIC 0
#define REQUEST_QUEUED 0
#define REQUEST_RUNNING 0
#define NO_SUCH_CHILD_PID 0
#define USEC 0
#define WITH_PROXY 0
#define L_INFO 0
#define RDEBUG2(...)
#define radlog(...)
#define rad_assert(expr)

typedef struct {
    unsigned int magic;
    int child_state;
    pthread_t child_pid;
    unsigned int delay;
    unsigned int number;
    const char *component;
    const char *module;
    struct {
        unsigned int max_request_time;
    } *root;
    int proxy;
    struct timeval when;
} REQUEST;

void remove_from_request_hash(REQUEST *request);
void tv_add(struct timeval *tv, unsigned int usec);
void INSERT_EVENT(void (*func)(void *), void *ctx);
void wait_for_proxy_id_to_expire(REQUEST *request);
void ev_request_free(REQUEST **request);