#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define REDIS_BLOCK 1
#define REDIS_CONNECTED 2
#define REDIS_CONN_UNIX 1
#define REDIS_ERR -1
#define REDIS_OK 0

struct timeval;
struct sockaddr_un;

typedef struct redisContext {
    int fd;
    int flags;
    int connection_type;
    struct timeval *timeout;
    struct {
        char *path;
    } unix_sock;
} redisContext;

int redisCreateSocket(redisContext *c, int domain);
int redisSetBlocking(redisContext *c, int blocking);
int redisContextTimeoutMsec(redisContext *c, long *timeout_msec);
int redisContextWaitReady(redisContext *c, long timeout_msec);