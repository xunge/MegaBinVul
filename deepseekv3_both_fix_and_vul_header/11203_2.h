#include <limits.h>
#include <stdlib.h>

struct Account {
    // Add necessary account fields here
};

struct Connection {
    struct Account account;
};

struct ImapData {
    struct {
        struct Connection *conn;
        struct {
            char *path;
        } *ctx;
    };
};

struct ImapMbox {
    char *mbox;
};

struct Url {
    char *path;
};

typedef struct header_cache_t header_cache_t;
typedef struct Account mutt_account_t;
typedef struct Connection mutt_connection_t;

#define U_PATH 0
#define FREE(x) free(*(x))

extern const char *HeaderCache;
extern int imap_parse_path(const char *path, struct ImapMbox *mx);
extern void imap_cachepath(struct ImapData *idata, const char *path, char *dest, size_t dlen);
extern void url_tostring(struct Url *url, char *dest, size_t dlen, int flags);
extern void mutt_account_tourl(const mutt_account_t *account, struct Url *url);
extern header_cache_t *mutt_hcache_open(const char *op, const char *path, void *namer);
extern void *imap_hcache_namer;