#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define C_OK 0
#define C_ERR -1
#define PROTO_INLINE_MAX_SIZE (1024*64)
#define PROTO_MBULK_BIG_ARG (1024*32)
#define SDS_NOINIT NULL
#define CLIENT_MASTER (1<<0)
#define OBJ_STRING 0
#define PROTO_MAX_BULK_LEN (512*1024*1024)

typedef struct client {
    int multibulklen;
    int argc;
    char *querybuf;
    size_t qb_pos;
    size_t argv_len_sum;
    long bulklen;
    int flags;
    void **argv;
} client;

typedef struct robj {
    int type;
    void *ptr;
} robj;

typedef char *sds;

typedef struct Server {
    long proto_max_bulk_len;
} Server;

extern Server server;

void serverAssertWithInfo(client *c, robj *o, int condition);
void addReplyError(client *c, const char *err);
void addReplyErrorFormat(client *c, const char *fmt, ...);
void setProtocolError(const char *err, client *c);
int string2ll(const char *s, size_t slen, long long *value);
void *zmalloc(size_t size);
void zfree(void *ptr);
robj *createObject(int type, void *ptr);
robj *createStringObject(const char *ptr, size_t len);
sds sdsnewlen(const void *init, size_t initlen);
void sdsclear(sds s);
void sdsrange(sds s, int start, int end);
sds sdsMakeRoomFor(sds s, size_t addlen);
size_t sdslen(const sds s);
void sdsIncrLen(sds s, int incr);