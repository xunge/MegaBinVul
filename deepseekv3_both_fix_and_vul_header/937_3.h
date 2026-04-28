#include <stdlib.h>
#include <string.h>

#define REDIS_NOTUSED(V) ((void) V)
#define AE_READABLE 1
#define REDIS_IO_WAIT (1<<0)

struct aeEventLoop;
struct redisCommand;

typedef struct listNode {
    struct listNode *next;
    struct listNode *prev;
    void *value;
} listNode;

typedef struct listIter {
    struct listNode *next;
    int direction;
} listIter;

typedef struct redisObject {
    void *ptr;
} redisObject;

typedef struct redisClient {
    int fd;
    int flags;
    redisObject **argv;
    char *querybuf;
} redisClient;

struct server {
    int ds_enabled;
    int vm_enabled;
    struct aeEventLoop *el;
    listNode *io_ready_clients;
    listNode *unblocked_clients;
    int cache_blocked_clients;
    int vm_blocked_clients;
};

extern struct server server;

void aeCreateFileEvent(struct aeEventLoop *eventLoop, int fd, int mask, void (*proc)(struct aeEventLoop *eventLoop, int fd, void *clientData, int mask), void *clientData);
void readQueryFromClient(struct aeEventLoop *eventLoop, int fd, void *clientData, int mask);
struct redisCommand *lookupCommand(char *name);
void call(redisClient *c, struct redisCommand *cmd);
void resetClient(redisClient *c);
void processInputBuffer(redisClient *c);
void flushAppendOnlyFile(void);
size_t sdslen(char *s);
void listRewind(listNode *list, listIter *iter);
listNode *listNext(listIter *iter);
void listDelNode(listNode *list, listNode *node);
listNode *listFirst(listNode *list);
int listLength(listNode *list);
void redisAssert(int condition);