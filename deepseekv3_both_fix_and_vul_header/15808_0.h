#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#define REDIS_BLOCK 1
#define REDIS_REUSEADDR 2
#define REDIS_CONNECTED 4
#define REDIS_CONN_TCP 1
#define REDIS_OK 0
#define REDIS_ERR -1
#define REDIS_ERR_IO 1
#define REDIS_ERR_OTHER 2
#define REDIS_CONNECT_RETRIES 3

typedef struct redisContext {
    int flags;
    int connection_type;
    int fd;
    struct timeval *timeout;
    struct {
        int port;
        char *host;
        char *source_addr;
    } tcp;
} redisContext;

void __redisSetError(redisContext *c, int type, const char *str);
int redisContextTimeoutMsec(redisContext *c, long *timeout_msec);
int redisSetBlocking(redisContext *c, int blocking);
int redisSetTcpNoDelay(redisContext *c);
void redisContextCloseFd(redisContext *c);
int redisContextWaitReady(redisContext *c, long timeout_msec);