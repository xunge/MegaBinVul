#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct client {
    int argc;
    struct robj **argv;
    int resp;
} client;

typedef struct robj {
    void *ptr;
} robj;

typedef struct listpackEntry {
    unsigned char *sval;
    unsigned int slen;
    long long lval;
    int type;
} listpackEntry;

struct shared {
    robj *syntaxerr;
    robj *null[3];
};

extern struct shared shared;

#define C_OK 0
#define OBJ_HASH 0

void addReplyErrorObject(client *c, robj *err);
void addReplyError(client *c, const char *err);
int getLongFromObjectOrReply(client *c, robj *obj, long *target, const char *msg);
void hrandfieldWithCountCommand(client *c, long count, int withvalues);
robj *lookupKeyReadOrReply(client *c, robj *key, robj *reply);
int checkType(client *c, robj *o, int type);
void hashTypeRandomElement(robj *hash, unsigned long len, listpackEntry *ele, int *flags);
unsigned long hashTypeLength(robj *hash);
void hashReplyFromListpackEntry(client *c, listpackEntry *ele);