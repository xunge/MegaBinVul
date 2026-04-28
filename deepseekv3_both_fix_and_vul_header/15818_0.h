#include <stdlib.h>

#define REDIS_ERR 0
#define REDIS_OK 1

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

typedef struct redisIvykisEvents {
    redisAsyncContext *context;
    struct {
        int fd;
        void (*handler_in)(void *);
        void (*handler_out)(void *);
        void (*handler_err)(void *);
        void *cookie;
    } fd;
} redisIvykisEvents;

void *hiredis_safe_malloc(size_t size);
void redisIvykisAddRead(void *);
void redisIvykisDelRead(void *);
void redisIvykisAddWrite(void *);
void redisIvykisDelWrite(void *);
void redisIvykisCleanup(void *);
void redisIvykisReadEvent(void *);
void redisIvykisWriteEvent(void *);
void IV_FD_INIT(void *);
void iv_fd_register(void *);