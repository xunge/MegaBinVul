#include <string.h>

struct BodyCache;

struct Header {
    char *data;
};

struct Context {
    void *data;
    int msgcount;
    struct Header **hdrs;
};

struct PopData;

#ifdef USE_HCACHE
#define HC_FNAME
#define HC_FEXT
#endif

int mutt_bcache_del(struct BodyCache *bcache, const char *id);
int mutt_str_strcmp(const char *a, const char *b);