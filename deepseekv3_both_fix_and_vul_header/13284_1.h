#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <float.h>

typedef struct client client;
typedef struct robj robj;
typedef char* sds;

#define C_OK 0
#define HASH_SET_TAKE_VALUE 1
#define MAX_LONG_DOUBLE_CHARS 128
#define LD_STR_HUMAN 1
#define NOTIFY_HASH 0

struct client {
    robj **argv;
    struct {
        int id;
    } *db;
};

struct robj {
    void *ptr;
};

struct sharedStruct {
    robj *hset;
};
extern struct sharedStruct shared;

extern struct {
    long dirty;
} server;

void addReplyError(client *c, const char *err);
void addReplyBulkCBuffer(client *c, const char *buf, int len);
void signalModifiedKey(client *c, void *db, robj *key);
void notifyKeyspaceEvent(int type, const char *event, robj *key, int dbid);
void rewriteClientCommandArgument(client *c, int i, robj *obj);
void decrRefCount(robj *obj);

int getLongDoubleFromObjectOrReply(client *c, robj *obj, long double *value, void *null);
robj *hashTypeLookupWriteOrCreate(client *c, robj *key);
int hashTypeGetValue(robj *o, void *key, unsigned char **vstr, unsigned int *vlen, long long *ll);
int string2ld(const char *s, size_t len, long double *dp);
int ld2string(char *buf, size_t len, long double value, int flags);
sds sdsnewlen(const void *init, size_t initlen);
void hashTypeSet(robj *o, void *key, sds value, int flags);
robj *createRawStringObject(const char *ptr, size_t len);