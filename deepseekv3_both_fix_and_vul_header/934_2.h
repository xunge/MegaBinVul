#include <string.h>
#include <strings.h>

#define REDIS_OK 0
#define REDIS_ERR 1
#define REDIS_CLOSE_AFTER_REPLY (1<<0)
#define REDIS_MULTI (1<<1)
#define REDIS_CMD_DENYOOM (1<<2)
#define REDIS_REPL_CONNECTED 0

typedef struct dict dict;
typedef struct list list;
typedef struct redisObject redisObject;
typedef struct redisClient redisClient;
typedef struct redisCommand redisCommand;

struct redisObject {
    void *ptr;
};

struct redisClient {
    redisObject **argv;
    int argc;
    int flags;
    int authenticated;
    dict *pubsub_channels;
    list *pubsub_patterns;
};

struct redisCommand {
    char *name;
    int arity;
    int flags;
    int (*proc)(redisClient *c);
};

struct redisServer {
    char *requirepass;
    int maxmemory;
    char *masterhost;
    int replstate;
    int repl_serve_stale_data;
    int loading;
    int vm_enabled;
    int vm_max_threads;
    int ds_enabled;
};

struct sharedObjectsStruct {
    redisObject *ok;
    redisObject *queued;
    redisObject *loadingerr;
};

extern struct sharedObjectsStruct shared;
extern struct redisServer server;

int strcasecmp(const char *s1, const char *s2);
void addReply(redisClient *c, redisObject *reply);
void addReplyError(redisClient *c, const char *err);
void addReplyErrorFormat(redisClient *c, const char *fmt, ...);
redisCommand *lookupCommand(const char *name);
void freeMemoryIfNeeded(void);
size_t zmalloc_used_memory(void);
int dictSize(dict *d);
int listLength(list *l);
void queueMultiCommand(redisClient *c, redisCommand *cmd);
int blockClientOnSwappedKeys(redisClient *c, redisCommand *cmd);
void call(redisClient *c, redisCommand *cmd);

int authCommand(redisClient *c);
int subscribeCommand(redisClient *c);
int unsubscribeCommand(redisClient *c);
int psubscribeCommand(redisClient *c);
int punsubscribeCommand(redisClient *c);
int infoCommand(redisClient *c);
int slaveofCommand(redisClient *c);
int execCommand(redisClient *c);
int discardCommand(redisClient *c);
int multiCommand(redisClient *c);
int watchCommand(redisClient *c);