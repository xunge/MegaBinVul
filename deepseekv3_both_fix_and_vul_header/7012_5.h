#include <stdlib.h>
#include <string.h>

typedef struct client client;
typedef struct robj robj;
typedef struct redisDb {
    int id;
} redisDb;
typedef struct redisServer {
    long dirty;
} redisServer;

#define OBJ_STRING 0
#define C_OK 0
#define NOTIFY_STRING 0

struct client {
    redisDb *db;
    robj **argv;
};

struct robj {
    void *ptr;
};

extern redisServer server;

size_t stringObjectLen(robj *o);
robj *lookupKeyWrite(redisDb *db, robj *key);
robj *tryObjectEncoding(robj *o);
void dbAdd(redisDb *db, robj *key, robj *val);
void incrRefCount(robj *o);
int checkType(client *c, robj *o, int type);
int checkStringLength(client *c, ...);
robj *dbUnshareStringValue(redisDb *db, robj *key, robj *o);
void *sdscatlen(void *s, const void *t, size_t len);
size_t sdslen(const void *s);
void signalModifiedKey(client *c, redisDb *db, robj *key);
void notifyKeyspaceEvent(int type, const char *event, robj *key, int dbid);
void addReplyLongLong(client *c, long long val);