#include <stdlib.h>

#define EV_P_ 
#define EV_MULTIPLICITY 0
#define REDIS_ERR -1
#define REDIS_OK 0
#define EV_READ 0x01
#define EV_WRITE 0x02

typedef struct ev_io {
    void *data;
} ev_io;

typedef struct redisLibevEvents {
    void *context;
    void *loop;
    int reading;
    int writing;
    ev_io rev;
    ev_io wev;
} redisLibevEvents;

typedef struct redisContext {
    int fd;
} redisContext;

typedef struct redisAsyncContext {
    redisContext c;
    struct {
        void *data;
        void (*addRead)(void *);
        void (*delRead)(void *);
        void (*addWrite)(void *);
        void (*delWrite)(void *);
        void (*cleanup)(void *);
    } ev;
} redisAsyncContext;

static void redisLibevAddRead(void *privdata) {}
static void redisLibevDelRead(void *privdata) {}
static void redisLibevAddWrite(void *privdata) {}
static void redisLibevDelWrite(void *privdata) {}
static void redisLibevCleanup(void *privdata) {}
static void redisLibevReadEvent(struct ev_io *watcher, int revents) {}
static void redisLibevWriteEvent(struct ev_io *watcher, int revents) {}
static void *hiredis_safe_malloc(size_t size) { return malloc(size); }
static void ev_io_init(struct ev_io *w, void (*cb)(struct ev_io *w, int revents), int fd, int events) {}