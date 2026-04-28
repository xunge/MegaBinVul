#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

#define OBJ_ENCODING_INTSET 1
#define OBJ_SET 2
#define DICT_OK 1
#define DICT_ERR 0
#define SRANDMEMBER_SUB_STRATEGY_MUL 3
#define C_OK 0
#define CLIENT_CLOSE_ASAP (1<<0)

typedef char *sds;

typedef struct client {
    void **argv;
    int flags;
} client;

typedef struct robj {
    int type;
    void *ptr;
} robj;

typedef struct dict {
    unsigned long size;
} dict;

typedef struct dictEntry {
    void *key;
    void *val;
} dictEntry;

typedef struct dictIterator {
    dict *d;
    int index;
    dictEntry *entry;
} dictIterator;

typedef struct setTypeIterator {
    robj *subject;
    int encoding;
    int ii;
} setTypeIterator;

typedef struct dictType {
    unsigned int (*hashFunction)(const void *key);
    void *(*keyDup)(void *privdata, const void *key);
    void *(*valDup)(void *privdata, const void *obj);
    int (*keyCompare)(void *privdata, const void *key1, const void *key2);
    void (*keyDestructor)(void *privdata, void *key);
    void (*valDestructor)(void *privdata, void *obj);
} dictType;

struct sharedObjectsStruct {
    robj *emptyarray;
};

extern struct sharedObjectsStruct shared;
extern dictType sdsReplyDictType;

size_t sdslen(sds s);
sds sdsfromlonglong(int64_t value);
sds sdsdup(const char *s);
void sdsfree(sds s);
int getRangeLongFromObjectOrReply(client *c, void *obj, long min, long max, long *value, const char *msg);
robj *lookupKeyReadOrReply(client *c, void *key, robj *reply);
int checkType(client *c, robj *o, int type);
unsigned long setTypeSize(robj *o);
void addReplyArrayLen(client *c, long length);
int setTypeRandomElement(robj *o, sds *ele, int64_t *llele);
void addReplyBulkLongLong(client *c, int64_t value);
void addReplyBulkCBuffer(client *c, void *p, size_t len);
void addReply(client *c, robj *o);
setTypeIterator *setTypeInitIterator(robj *o);
int setTypeNext(setTypeIterator *si, sds *ele, int64_t *llele);
void setTypeReleaseIterator(setTypeIterator *si);
void serverAssert(int condition);
dict *dictCreate(dictType *type);
int dictExpand(dict *d, unsigned long size);
int dictAdd(dict *d, void *key, void *val);
dictEntry *dictGetFairRandomKey(dict *d);
void dictUnlink(dict *d, void *key);
void dictFreeUnlinkedEntry(dict *d, dictEntry *de);
unsigned long dictSize(dict *d);
dictIterator *dictGetIterator(dict *d);
dictEntry *dictNext(dictIterator *di);
void dictReleaseIterator(dictIterator *di);
void dictRelease(dict *d);
void addReplyBulkSds(client *c, sds s);
void *dictGetKey(const dictEntry *de);