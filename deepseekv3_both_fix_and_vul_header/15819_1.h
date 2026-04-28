#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

typedef int redisFD;
#define REDIS_INVALID_FD (-1)

#define REDIS_BLOCK 0x1
#define REDIS_REUSEADDR 0x2
#define REDIS_CONNECTED 0x4

#define REDIS_CONN_TCP 1
#define REDIS_ERR_IO 1
#define REDIS_ERR_OTHER 2
#define REDIS_OK 0
#define REDIS_ERR (-1)
#define REDIS_CONNECT_RETRIES 10

typedef struct redisContext {
    int flags;
    int connection_type;
    struct {
        char *host;
        int port;
        char *source_addr;
    } tcp;
    struct timeval *timeout;
    redisFD fd;
    void *saddr;
    size_t addrlen;
} redisContext;