#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define REDIS_BLOCK 1
#define REDIS_CONNECTED 2
#define REDIS_CONN_UNIX 3
#define REDIS_ERR -1
#define REDIS_OK 0

typedef struct redisContext {
    int fd;
    int flags;
    int connection_type;
    struct timeval *timeout;
    struct sockaddr *saddr;
    socklen_t addrlen;
    struct {
        char *path;
    } unix_sock;
} redisContext;

int redisCreateSocket(redisContext *c, int domain);
int redisSetBlocking(redisContext *c, int blocking);
int redisContextTimeoutMsec(redisContext *c, long *timeout_msec);
int redisContextWaitReady(redisContext *c, long timeout_msec);