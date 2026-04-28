#include <stdlib.h>
#include <string.h>

typedef struct redisContext {
    int fd;
} redisContext;

typedef struct redisEvents {
    void *data;
    void (*addRead)(void *privdata);
    void (*delRead)(void *privdata);
    void (*addWrite)(void *privdata);
    void (*delWrite)(void *privdata);
    void (*cleanup)(void *privdata);
} redisEvents;

typedef struct redisAsyncContext {
    redisContext c;
    redisEvents ev;
} redisAsyncContext;

typedef struct redisLibeventEvents {
    redisAsyncContext *context;
    void *rev;
    void *wev;
} redisLibeventEvents;

typedef struct event_base event_base;
typedef struct event event;

#define REDIS_OK 0
#define REDIS_ERR -1
#define EV_READ 0x02
#define EV_WRITE 0x04

static void redisLibeventAddRead(void *privdata) {}
static void redisLibeventDelRead(void *privdata) {}
static void redisLibeventAddWrite(void *privdata) {}
static void redisLibeventDelWrite(void *privdata) {}
static void redisLibeventCleanup(void *privdata) {}
static void redisLibeventReadEvent(int fd, short event, void *arg) {}
static void redisLibeventWriteEvent(int fd, short event, void *arg) {}

static void *event_new(struct event_base *base, int fd, short events,
                      void (*callback)(int, short, void *), void *arg) {
    return NULL;
}
static int event_add(void *ev, const struct timeval *timeout) {
    return 0;
}

#define hi_calloc calloc