#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define LONG_STRING 1024
#define USE_HCACHE
#define WriteInc 1
#define MUTT_PROGRESS_MSG 0
#define POP_DISCONNECTED 0

struct Context {
    void *data;
    int msgcount;
    int deleted;
    bool quiet;
    struct Header **hdrs;
    const char *path;
};

struct Header {
    bool deleted;
    bool changed;
    int refno;
    char *data;
};

struct PopData {
    int check_time;
    int status;
    bool clear_cache;
    char err_msg[LONG_STRING];
    void *bcache;
};

struct Progress {
    // minimal progress struct definition
    int dummy;
};

const char *_(const char *s);

void mutt_progress_init(struct Progress *progress, const char *msg, int type, int inc, int total);
void mutt_progress_update(struct Progress *progress, int pos, int percent);
void mutt_error(const char *fmt, ...);
void mutt_bcache_del(void *bcache, char *data);
void mutt_str_strfcpy(char *dest, const char *src, size_t dsize);

#ifdef USE_HCACHE
typedef void header_cache_t;
header_cache_t *pop_hcache_open(struct PopData *pop_data, const char *path);
void mutt_hcache_delete(header_cache_t *hc, const char *key, size_t keylen);
void mutt_hcache_store(header_cache_t *hc, const char *key, size_t keylen, void *data, unsigned int uidvalidity);
void mutt_hcache_close(header_cache_t *hc);
#endif

int pop_reconnect(struct Context *ctx);
int pop_query(struct PopData *pop_data, const char *buf, size_t buflen);
void pop_clear_cache(struct PopData *pop_data);