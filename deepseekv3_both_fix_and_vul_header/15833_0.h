#include <stdlib.h>
#include <sys/time.h>

typedef struct redisAsyncContext {
    struct {
        struct timeval *timeout;
    } c;
} redisAsyncContext;