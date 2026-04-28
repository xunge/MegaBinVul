#include <stdint.h>
#include <stddef.h>

typedef struct dict dict;
typedef struct dictEntry dictEntry;
typedef char *sds;
typedef struct intset intset;

#define OBJ_ENCODING_HT 1
#define OBJ_ENCODING_INTSET 2
#define C_OK 0
#define DICT_OK 0

typedef struct robj {
    int encoding;
    void *ptr;
} robj;

struct server {
    int set_max_intset_entries;
};

extern struct server server;

int isSdsRepresentableAsLongLong(sds value, long long *llval);
intset *intsetAdd(intset *is, long long value, uint8_t *success);
unsigned int intsetLen(const intset *is);
void setTypeConvert(robj *subject, int encoding);
void serverPanic(const char *msg);
void serverAssert(int condition);
dictEntry *dictAddRaw(dict *d, void *key, dictEntry **existing);
void dictSetKey(dict *d, dictEntry *de, void *key);
void dictSetVal(dict *d, dictEntry *de, void *val);
int dictAdd(dict *d, void *key, void *val);
sds sdsdup(const sds s);