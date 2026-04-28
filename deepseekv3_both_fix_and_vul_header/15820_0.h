#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define REDIS_BLOCK 1
#define REDIS_ERR -1
#define REDIS_OK 0
#define REDIS_CONN_UNIX 1
#define REDIS_CONNECTED 2

struct timeval;
struct sockaddr_un;

typedef struct redisContext {
    int flags;
    int connection_type;
    int fd;
    void *saddr;
    socklen_t addrlen;
    struct timeval *timeout;
    struct {
        char *path;
    } unix_sock;
} redisContext;

extern int redisCreateSocket(redisContext *c, int domain);
extern int redisSetBlocking(redisContext *c, int blocking);
extern int redisContextTimeoutMsec(redisContext *c, long *timeout_msec);
extern int redisContextWaitReady(redisContext *c, long timeout_msec);
extern char *hiredis_safe_strdup(const char *s);
extern void *hiredis_safe_malloc(size_t size);