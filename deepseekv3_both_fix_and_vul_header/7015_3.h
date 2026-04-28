#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <stddef.h>

typedef char *sds;

typedef struct robj {
    int type;
    void *ptr;
    int encoding;
} robj;

typedef struct client {
    void *user;
    void *cmd;
    robj **argv;
    int argc;
    struct redisDb *db;
    int flags;
} client;

typedef struct redisDb {
    int id;
} redisDb;

typedef struct list {
    // list implementation details
} list;

typedef struct redisSortObject {
    robj *obj;
    union {
        double score;
        robj *cmpobj;
    } u;
} redisSortObject;

typedef struct redisSortOperation {
    int type;
    robj *pattern;
} redisSortOperation;

typedef struct dict {
    // dict implementation details
} dict;

typedef struct dictIterator {
    // dict iterator implementation details
} dictIterator;

typedef struct dictEntry {
    // dict entry implementation details
} dictEntry;

typedef struct zskiplistNode {
    sds ele;
    struct zskiplistNode *backward;
    struct zskiplistLevel {
        struct zskiplistNode *forward;
    } level[];
} zskiplistNode;

typedef struct zskiplist {
    struct zskiplistNode *header;
    struct zskiplistNode *tail;
} zskiplist;

typedef struct zset {
    dict *dict;
    zskiplist *zsl;
} zset;

typedef struct listTypeIterator {
    // list iterator implementation details
} listTypeIterator;

typedef struct listTypeEntry {
    // list entry implementation details
} listTypeEntry;

typedef struct setTypeIterator {
    // set iterator implementation details
} setTypeIterator;

typedef struct listNode {
    void *value;
    struct listNode *next;
    struct listNode *prev;
} listNode;

typedef struct listIter {
    // list iterator implementation details
} listIter;

typedef struct quicklist {
    // quicklist implementation details
} quicklist;

#define C_OK 0
#define OBJ_SET 1
#define OBJ_LIST 2
#define OBJ_ZSET 3
#define OBJ_STRING 4
#define OBJ_ENCODING_SKIPLIST 5
#define OBJ_ENCODING_INT 6
#define LIST_HEAD 0
#define LIST_TAIL 1
#define LIST_CONV_AUTO 0
#define SORT_OP_GET 0
#define CMD_KEY_ACCESS 0
#define NOTIFY_LIST 0
#define NOTIFY_GENERIC 1
#define CLIENT_SCRIPT (1<<5)

struct sharedObjectsStruct {
    robj *syntaxerr;
    robj *wrongtypeerr;
} shared;

struct redisServer {
    int cluster_enabled;
    int sort_desc;
    int sort_alpha;
    int sort_bypattern;
    int sort_store;
    long dirty;
};

extern struct redisServer server;

void zfree(void *ptr);
void *zmalloc(size_t size);
robj *createQuicklistObject(void);
robj *createStringObject(const char *ptr, size_t len);
robj *createObject(int type, void *ptr);
void decrRefCount(robj *o);
void incrRefCount(robj *o);
int ACLUserCheckCmdWithUnrestrictedKeyAccess(void *user, void *cmd, robj **argv, int argc, int flags);
int getLongFromObjectOrReply(client *c, robj *o, long *target, const char *msg);
void addReplyError(client *c, const char *err);
void addReplyErrorObject(client *c, robj *err);
void addReplyArrayLen(client *c, long len);
void addReplyBulk(client *c, robj *obj);
void addReplyNull(client *c);
void addReplyLongLong(client *c, long long ll);
robj *lookupKeyRead(redisDb *db, robj *key);
robj *lookupKeyByPattern(redisDb *db, robj *pattern, robj *subj);
void setKey(client *c, redisDb *db, robj *key, robj *val, int flags);
int dbDelete(redisDb *db, robj *key);
void signalModifiedKey(client *c, redisDb *db, robj *key);
void notifyKeyspaceEvent(int type, const char *event, robj *key, int dbid);
void serverPanic(const char *msg);
void serverAssertWithInfo(client *c, robj *o, int expr);
list *listCreate(void);
void listSetFreeMethod(list *list, void (*free)(void *ptr));
void listRelease(list *list);
void listRewind(list *list, listIter *iter);
listNode *listNext(listIter *iter);
void listAddNodeTail(list *list, void *value);
dictIterator *dictGetIterator(dict *d);
dictEntry *dictNext(dictIterator *iter);
void dictReleaseIterator(dictIterator *iter);
size_t dictSize(dict *d);
void zsetConvert(robj *zobj, int encoding);
listTypeIterator *listTypeInitIterator(robj *subject, long index, int direction);
void listTypeReleaseIterator(listTypeIterator *li);
int listTypeNext(listTypeIterator *li, listTypeEntry *entry);
robj *listTypeGet(listTypeEntry *entry);
long listTypeLength(robj *subject);
void listTypePush(robj *subject, robj *value, int where);
void listTypeTryConversion(robj *subject, int enc, robj **argv, int argc);
setTypeIterator *setTypeInitIterator(robj *subject);
sds setTypeNextObject(setTypeIterator *si);
void setTypeReleaseIterator(setTypeIterator *si);
long setTypeSize(robj *subject);
zskiplistNode *zslGetElementByRank(zskiplist *zsl, unsigned long rank);
int sdsEncodedObject(robj *o);
robj *getDecodedObject(robj *o);
int sortCompare(const void *a, const void *b);
void pqsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *), long start, long end);
size_t sdslen(sds s);
robj *createSortOperation(int type, robj *pattern);
sds dictGetKey(dictEntry *de);