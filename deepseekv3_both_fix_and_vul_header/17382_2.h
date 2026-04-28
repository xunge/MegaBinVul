#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdint.h>

typedef struct client {
    int argc;
    struct robj **argv;
} client;

typedef struct robj {
    void *ptr;
    int type;
} robj;

typedef struct streamID {
    uint64_t ms;
    uint64_t seq;
} streamID;

typedef struct stream {
    streamID last_id;
    void *cgroups;
} stream;

typedef struct streamCG {
    streamID last_id;
} streamCG;

typedef char *sds;

#define OBJ_STREAM 0
#define C_OK 0

struct sharedObjectsStruct {
    robj *nokeyerr;
    robj *ok;
    robj *cone;
    robj *czero;
    robj *syntaxerr;
} shared;

struct redisServer {
    long long dirty;
} server;

size_t sdslen(sds s);
sds sdsnew(const char *init);
robj *lookupKeyWriteOrReply(client *c, robj *key, robj *reply);
int checkType(client *c, robj *o, int type);
streamCG *streamLookupCG(stream *s, sds groupname);
int streamParseIDOrReply(client *c, robj *o, streamID *id, int strict);
streamCG *streamCreateCG(stream *s, sds groupname, size_t len, streamID *id);
void addReply(client *c, robj *obj);
void addReplySds(client *c, sds s);
void addReplyErrorFormat(client *c, const char *fmt, ...);
void addReplyHelp(client *c, const char **help);
void addReplyLongLong(client *c, long long ll);
long long streamDelConsumer(streamCG *cg, sds name);
void streamFreeCG(streamCG *cg);
int raxRemove(void *rax, unsigned char *s, size_t len, void **old);