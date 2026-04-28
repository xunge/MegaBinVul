#include <stdlib.h>

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
    void (*scheduleTimer)(void *privdata);
} redisEvents;

typedef struct redisAsyncContext {
    redisContext c;
    redisEvents ev;
} redisAsyncContext;

typedef struct redisLibeventEvents {
    redisAsyncContext *context;
    struct event *ev;
    struct event_base *base;
} redisLibeventEvents;

struct event_base;
struct event;

#define REDIS_ERR 0
#define REDIS_OK 1
#define EV_READ 0x02
#define EV_WRITE 0x04

struct event* event_new(struct event_base *base, int fd, short events,
                       void (*callback)(int, short, void *), void *arg);
void redisLibeventAddRead(void *privdata);
void redisLibeventDelRead(void *privdata);
void redisLibeventAddWrite(void *privdata);
void redisLibeventDelWrite(void *privdata);
void redisLibeventCleanup(void *privdata);
void redisLibeventSetTimeout(void *privdata);
void redisLibeventHandler(int fd, short event, void *arg);