#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef int redisFD;
#define REDIS_INVALID_FD (-1)

#define REDIS_BLOCK 0x1
#define REDIS_REUSEADDR 0x2
#define REDIS_CONNECT_RETRIES 10

#define REDIS_OK 0
#define REDIS_ERR -1
#define REDIS_ERR_IO 1
#define REDIS_ERR_OTHER 2

#define REDIS_CONN_TCP 1
#define REDIS_CONNECTED 0x4

struct timeval;

typedef struct {
    int flags;
    int connection_type;
    struct timeval *timeout;
    redisFD fd;
    struct {
        char *host;
        int port;
        char *source_addr;
    } tcp;
    void *saddr;
    size_t addrlen;
} redisContext;

void __redisSetError(redisContext *c, int type, const char *str);
int redisContextTimeoutMsec(redisContext *c, long *timeout_msec);
int redisSetBlocking(redisContext *c, int blocking);
int redisSetTcpNoDelay(redisContext *c);
int redisContextWaitReady(redisContext *c, long timeout_msec);
void redisNetClose(redisContext *c);