#include <stdlib.h>

#define REDIS_ERR -1
#define REDIS_OK 0

typedef struct redisAeEvents redisAeEvents;

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

typedef struct aeEventLoop aeEventLoop;

struct redisAeEvents {
    redisAsyncContext *context;
    aeEventLoop *loop;
    int fd;
    int reading;
    int writing;
};

static void *hiredis_safe_malloc(size_t size) {
    return malloc(size);
}

static void redisAeAddRead(void *privdata) {}
static void redisAeDelRead(void *privdata) {}
static void redisAeAddWrite(void *privdata) {}
static void redisAeDelWrite(void *privdata) {}
static void redisAeCleanup(void *privdata) {}