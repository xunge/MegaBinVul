#include <stdlib.h>
#include <string.h>

#define REDIS_OK 0
#define REDIS_ENCODING_RAW 0
#define REDIS_VM_MEMORY 0

typedef struct redisClient redisClient;
typedef struct redisObject {
    int encoding;
    void *ptr;
    int storage;
} robj;

struct redisServer {
    int ds_enabled;
    int vm_enabled;
} server;

int _installWriteEvent(redisClient *c);
void redisAssert(int condition);
int _addReplyToBuffer(redisClient *c, void *ptr, size_t len);
void _addReplyObjectToList(redisClient *c, robj *obj);
robj *getDecodedObject(robj *obj);
void decrRefCount(robj *obj);
size_t sdslen(void *s);