#include <stdlib.h>

#define REDIS_ERR 0
#define REDIS_OK 1

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

typedef struct iv_fd {
    int fd;
    void (*handler_in)(struct iv_fd *fd);
    void (*handler_out)(struct iv_fd *fd);
    void (*handler_err)(struct iv_fd *fd);
    void *cookie;
} iv_fd;

typedef struct redisIvykisEvents {
    redisAsyncContext *context;
    iv_fd fd;
} redisIvykisEvents;

void redisIvykisAddRead(void *privdata);
void redisIvykisDelRead(void *privdata);
void redisIvykisAddWrite(void *privdata);
void redisIvykisDelWrite(void *privdata);
void redisIvykisCleanup(void *privdata);
void redisIvykisReadEvent(struct iv_fd *fd);
void redisIvykisWriteEvent(struct iv_fd *fd);
void IV_FD_INIT(struct iv_fd *fd);
void iv_fd_register(struct iv_fd *fd);