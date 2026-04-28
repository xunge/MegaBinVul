#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#define REDIS_REPLY_ARRAY 1
#define REDIS_REPLY_MAP 2
#define REDIS_REPLY_SET 3
#define REDIS_REPLY_PUSH 4

typedef struct redisReply {
    int type;
    size_t elements;
    struct redisReply **element;
} redisReply;

typedef struct redisReadTask {
    int type;
    struct redisReadTask *parent;
    redisReply *obj;
    int idx;
} redisReadTask;

void *createReplyObject(int type);
void freeReplyObject(redisReply *r);
void *hi_calloc(size_t nmemb, size_t size);