#include <stdlib.h>

struct redisCommand;
typedef struct robj robj;
typedef struct keyReference {
    int pos;
    int flags;
} keyReference;
typedef struct getKeysResult {
    keyReference *keys;
    int numkeys;
} getKeysResult;

#define UNUSED(x) (void)(x)
#define CMD_KEY_RO (1<<0)
#define CMD_KEY_ACCESS (1<<1)

keyReference *getKeysPrepareResult(getKeysResult *result, int count);