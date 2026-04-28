#include <stdlib.h>

typedef struct redisContext {
    int fd;
} redisContext;

typedef struct redisAsyncContext {
    redisContext c;
    struct {
        void *data;
        void (*addRead)(void *privdata);
        void (*delRead)(void *privdata);
        void (*addWrite)(void *privdata);
        void (*delWrite)(void *privdata);
        void (*cleanup)(void *privdata);
    } ev;
} redisAsyncContext;

typedef struct aeEventLoop aeEventLoop;

typedef struct redisAeEvents {
    redisAsyncContext *context;
    aeEventLoop *loop;
    int fd;
    int reading;
    int writing;
} redisAeEvents;

#define REDIS_ERR 0
#define REDIS_OK 1

void redisAeAddRead(void *privdata);
void redisAeDelRead(void *privdata);
void redisAeAddWrite(void *privdata);
void redisAeDelWrite(void *privdata);
void redisAeCleanup(void *privdata);