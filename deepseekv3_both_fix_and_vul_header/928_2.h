#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>

#define AE_READABLE 1
#define AE_WRITABLE 2

typedef struct redisClient redisClient;
typedef struct dict dict;
typedef struct aeEventLoop aeEventLoop;
typedef char *sds;

struct listNode {
    struct listNode *prev;
    struct listNode *next;
    void *value;
};

struct list {
    struct listNode *head;
    struct listNode *tail;
    unsigned long len;
};

typedef struct list list;
typedef struct listNode listNode;

struct redisClient {
    sds querybuf;
    int flags;
    struct list *watched_keys;
    dict *pubsub_channels;
    struct list *pubsub_patterns;
    int fd;
    struct list *reply;
    struct list *io_keys;
    int replstate;
    int repldbfd;
    int argc;
    void **argv;
};

struct server {
    aeEventLoop *el;
    struct list *clients;
    struct list *io_ready_clients;
    int ds_enabled;
    int cache_blocked_clients;
    int vm_enabled;
    int vm_blocked_clients;
    struct list *monitors;
    struct list *slaves;
    redisClient *master;
    int replstate;
};

extern struct server server;

#define REDIS_BLOCKED (1<<0)
#define REDIS_IO_WAIT (1<<1)
#define REDIS_SLAVE (1<<2)
#define REDIS_MONITOR (1<<3)
#define REDIS_MASTER (1<<4)
#define REDIS_REPL_SEND_BULK 1
#define REDIS_REPL_CONNECT 2

void sdsfree(sds s);
void unblockClientWaitingData(redisClient *c);
void unwatchAllKeys(redisClient *c);
void listRelease(struct list *list);
void pubsubUnsubscribeAllChannels(redisClient *c, int notify);
void pubsubUnsubscribeAllPatterns(redisClient *c, int notify);
void dictRelease(dict *dict);
void aeDeleteFileEvent(aeEventLoop *eventLoop, int fd, int mask);
void freeClientArgv(redisClient *c);
struct listNode *listSearchKey(struct list *list, void *key);
void listDelNode(struct list *list, struct listNode *node);
void dontWaitForSwappedKey(redisClient *c, void *key);
void freeClientMultiState(redisClient *c);
void zfree(void *ptr);
void redisAssert(int condition);
unsigned long listLength(const struct list *l);
struct listNode *listFirst(struct list *l);