#include <stdlib.h>

#define REDIS_ERR 0
#define REDIS_OK 1
#define EV_READ 0x02
#define EV_WRITE 0x04

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
    void (*scheduleTimer)(void *privdata, long long timeout);
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

extern void *hiredis_safe_calloc(size_t nmemb, size_t size);
extern void redisLibeventAddRead(void *privdata);
extern void redisLibeventDelRead(void *privdata);
extern void redisLibeventAddWrite(void *privdata); 
extern void redisLibeventDelWrite(void *privdata);
extern void redisLibeventCleanup(void *privdata);
extern void redisLibeventSetTimeout(void *privdata, long long timeout);
extern void redisLibeventHandler(int fd, short event, void *arg);
extern struct event *event_new(struct event_base *base, int fd, short events, void (*cb)(int, short, void *), void *arg);