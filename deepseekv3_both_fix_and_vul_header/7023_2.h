#include <limits.h>
#include <strings.h>
#include <stddef.h>

typedef struct robj {
    void *ptr;
    int type;
} robj;

typedef struct client {
    int argc;
    robj **argv;
    int resp;
} client;

typedef struct listpackEntry {
    unsigned char *sval;
    size_t slen;
    long long lval;
} listpackEntry;

struct shared {
    robj *syntaxerr;
    robj *null[3];
} shared;

enum {
    OBJ_ZSET = 4
};

#define C_OK 0

void addReplyErrorObject(client *c, robj *err);
void addReplyError(client *c, const char *err);
int getLongFromObjectOrReply(client *c, robj *obj, long *target, const char *msg);
void zrandmemberWithCountCommand(client *c, long count, int withscores);
robj *lookupKeyReadOrReply(client *c, robj *key, robj *reply);
int checkType(client *c, robj *o, int type);
void zsetTypeRandomElement(robj *zset, unsigned long len, listpackEntry *ele, double *score);
unsigned long zsetLength(robj *zset);
void zsetReplyFromListpackEntry(client *c, listpackEntry *ele);