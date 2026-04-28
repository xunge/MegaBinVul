#include <stdlib.h>

#define EV_P_ 
#define EV_MULTIPLICITY 0
#define REDIS_ERR 0
#define REDIS_OK 1
#define EV_READ 1
#define EV_WRITE 2

typedef struct redisContext {
    int fd;
} redisContext;

typedef struct {
    void *data;
    void (*addRead)(void *);
    void (*delRead)(void *);
    void (*addWrite)(void *);
    void (*delWrite)(void *);
    void (*cleanup)(void *);
} redisEventLoop;

typedef struct redisAsyncContext {
    redisContext c;
    redisEventLoop ev;
} redisAsyncContext;

typedef struct redisLibevEvents {
    redisAsyncContext *context;
    void *loop;
    int reading;
    int writing;
    struct {
        void *data;
    } rev, wev;
} redisLibevEvents;

static void redisLibevAddRead(void *privdata) {}
static void redisLibevDelRead(void *privdata) {}
static void redisLibevAddWrite(void *privdata) {}
static void redisLibevDelWrite(void *privdata) {}
static void redisLibevCleanup(void *privdata) {}
static void redisLibevReadEvent(void *watcher, int revents) {}
static void redisLibevWriteEvent(void *watcher, int revents) {}
static void ev_io_init(void *watcher, void *cb, int fd, int events) {}