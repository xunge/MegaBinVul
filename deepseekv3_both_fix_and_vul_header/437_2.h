#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>

#define HTTP_IS_SPHT(c) ((c) == ' ' || (c) == '\t')
#define COOKIE_DELIM '~'
#define COOKIE_DELIM_DATE '|'
#define PR_CK_PFX (1 << 0)
#define PR_CK_INS (1 << 1)
#define PR_CK_IND (1 << 2)
#define PR_O_PERSIST (1 << 3)
#define TX_CK_MASK 0xF
#define TX_CK_VALID (1 << 0)
#define TX_CK_DOWN (1 << 1)
#define TX_CK_EXPIRED (1 << 2)
#define TX_CK_OLD (1 << 3)
#define TX_CK_INVALID (1 << 4)
#define TX_CK_UNUSED (1 << 5)
#define SF_IGNORE_PRST (1 << 0)
#define SF_ASSIGNED (1 << 1)
#define SF_FORCE_PRST (1 << 2)
#define SF_DIRECT (1 << 3)
#define SRV_ST_STOPPED 0

struct stream {
    struct session *sess;
    struct http_txn *txn;
    struct {
        struct {
            char *cookie_name;
            int cookie_len;
            unsigned int ck_opts;
            unsigned int options;
            unsigned int cookie_maxlife;
            unsigned int cookie_maxidle;
            struct server *srv;
        } *be;
        unsigned int flags;
        void *target;
    };
};

struct channel {
    struct {
        void *buf;
    };
};

struct session {
    struct {
        char *capture_name;
        int capture_namelen;
        int capture_len;
    } *fe;
    struct http_txn *txn;
};

struct http_txn {
    char *cli_cookie;
    unsigned int flags;
    unsigned int cookie_first_date;
    unsigned int cookie_last_date;
};

struct htx {
    // minimal definition
};

struct http_hdr_ctx {
    void *blk;
    struct {
        char *ptr;
        size_t len;
    } value;
};

struct server {
    char *cookie;
    int cklen;
    int cur_state;
    struct server *next;
    void *obj_type;
};

struct ist {
    char *ptr;
    size_t len;
};

extern struct timeval date;
extern struct pool_head *pool_head_capture;

static inline struct ist ist(const char *str) {
    return (struct ist){.ptr = (char *)str, .len = strlen(str)};
}
static inline int unlikely(int x) { return x; }
static inline int http_find_header(struct htx *htx, struct ist name, struct http_hdr_ctx *ctx, int full) { return 0; }
static inline char *http_find_cookie_value_end(char *start, char *end) { return end; }
static inline int http_del_hdr_value(char *start, char *end, char **from, char *to) { return 0; }
static inline void htx_change_blk_value_len(struct htx *htx, void *blk, int len) {}
static inline void http_remove_header(struct htx *htx, struct http_hdr_ctx *ctx) {}
static inline struct htx *htxbuf(void *buf) { return NULL; }
static inline void *pool_alloc(void *pool) { return NULL; }
static inline void ha_alert(const char *msg) {}
static inline int b64tos30(const char *str) { return 0; }