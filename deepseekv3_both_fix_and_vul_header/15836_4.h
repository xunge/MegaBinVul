#include <stdlib.h>

struct ev_loop;
struct ev_io {
    void *data;
};

typedef struct {
    int fd;
} redisContext;

typedef struct {
    void (*addRead)(void *privdata);
    void (*delRead)(void *privdata);
    void (*addWrite)(void *privdata);
    void (*delWrite)(void *privdata);
    void (*cleanup)(void *privdata);
    void *data;
} redisAsyncEvents;

typedef struct redisAsyncContext {
    redisContext c;
    redisAsyncEvents ev;
} redisAsyncContext;

typedef struct redisLibevEvents {
    redisAsyncContext *context;
    struct ev_loop *loop;
    int reading, writing;
    struct ev_io rev;
    struct ev_io wev;
} redisLibevEvents;

#define EV_P_ 
#define EV_READ 0x01
#define EV_WRITE 0x02
#define REDIS_ERR 0
#define REDIS_OK 1

static void redisLibevAddRead(void *privdata) {}
static void redisLibevDelRead(void *privdata) {}
static void redisLibevAddWrite(void *privdata) {}
static void redisLibevDelWrite(void *privdata) {}
static void redisLibevCleanup(void *privdata) {}
static void redisLibevReadEvent(struct ev_io *watcher, int revents) {}
static void redisLibevWriteEvent(struct ev_io *watcher, int revents) {}
static void ev_io_init(struct ev_io *io, void (*cb)(struct ev_io *, int), int fd, int events) {}