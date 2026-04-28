#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct Context {
    void *data;
    char *path;
    int msgcount;
    bool quiet;
    struct Header **hdrs;
};

struct PopData {
    time_t check_time;
    bool clear_cache;
    int cmd_uidl;
    char err_msg[256];
    void *bcache;
};

struct Progress {
    const char *msg;
    int type;
    int inc;
    int size;
};

struct Header {
    int refno;
    bool deleted;
    char *data;
    bool old;
    bool read;
    int index;
};

#define MUTT_PROGRESS_MSG 1

extern int ReadInc;
extern bool MarkOld;
extern bool MessageCacheClean;

int pop_fetch_data(struct PopData *pop_data, const char *cmd, void *data, void (*callback)(void), struct Context *ctx);
int pop_read_header(struct PopData *pop_data, struct Header *hdr);
void mutt_debug(int level, const char *fmt, ...);
void mutt_progress_init(struct Progress *progress, const char *msg, int type, int inc, int size);
void mutt_progress_update(struct Progress *progress, int pos, int percent);
void mutt_error(const char *fmt, ...);
void mutt_clear_error(void);
void mx_update_context(struct Context *ctx, int count);
void mutt_header_free(struct Header **hdr);
void mutt_bcache_list(void *bcache, void (*callback)(void), void *data);
int mutt_bcache_exists(void *bcache, const char *id);
char *mutt_str_strdup(const char *str);
const char *_(const char *str);
const char *ngettext(const char *singular, const char *plural, int n);
void fetch_uidl(void);
void msg_cache_check(void);
char *cache_id(const char *data);

#ifdef USE_HCACHE
typedef void header_cache_t;
header_cache_t *pop_hcache_open(struct PopData *pop_data, const char *path);
void *mutt_hcache_fetch(header_cache_t *hc, const char *key, size_t keylen);
struct Header *mutt_hcache_restore(unsigned char *data);
void mutt_hcache_free(header_cache_t *hc, void **data);
void mutt_hcache_store(header_cache_t *hc, const char *key, size_t keylen, struct Header *hdr, int flags);
void mutt_hcache_close(header_cache_t *hc);
#endif