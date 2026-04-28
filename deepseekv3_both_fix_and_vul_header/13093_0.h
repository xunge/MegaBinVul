#include <stdlib.h>

typedef struct client client;
typedef struct redisObject redisObject;
typedef struct redisDb redisDb;
typedef struct sharedObjectsStruct sharedObjectsStruct;

#define SETKEY_DOESNT_EXIST (1<<0)
#define NOTIFY_STRING 0

extern sharedObjectsStruct shared;

struct client {
    int argc;
    redisObject **argv;
    redisDb *db;
};

struct redisDb {
    int id;
};

struct sharedObjectsStruct {
    redisObject *czero;
    redisObject *cone;
    redisObject *ok;
};

redisObject *lookupKeyWrite(redisDb *db, redisObject *key);
void addReplyErrorArity(client *c);
void addReply(client *c, redisObject *obj);
redisObject *tryObjectEncoding(redisObject *o);
void setKey(client *c, redisDb *db, redisObject *key, redisObject *val, int flags);
void notifyKeyspaceEvent(int type, char *event, redisObject *key, int dbid);

extern struct {
    int dirty;
} server;