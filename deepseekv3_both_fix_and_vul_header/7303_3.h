#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define HTTP_IS_SPHT(c) ((c) == ' ' || (c) == '\t')
#define TX_SCK_PRESENT  0x00000001
#define TX_SCK_MASK     0x0000000E
#define TX_SCK_FOUND    0x00000002
#define TX_SCK_DELETED  0x00000004
#define TX_SCK_REPLACED 0x00000008
#define SF_IGNORE_PRST  0x00000001
#define SF_DIRECT       0x00000002
#define PR_CK_PSV       0x00000001
#define PR_CK_INS       0x00000002
#define PR_CK_IND       0x00000004
#define PR_CK_RW        0x00000008
#define PR_CK_PFX       0x00000010
#define COOKIE_DELIM    ';'

struct ist {
    char *ptr;
    size_t len;
};

struct http_hdr_ctx {
    void *blk;
    struct ist value;
    int lws_before;
    int lws_after;
};

struct buffer {
    struct htx *htx;
};

struct htx {
    // minimal definition
};

struct channel {
    struct buffer buf;
};

struct proxy {
    char *cookie_name;
    char *capture_name;
    size_t capture_namelen;
    size_t capture_len;
    size_t cookie_len;
    uint32_t ck_opts;
};

struct session {
    struct proxy *fe;
};

struct http_txn {
    uint32_t flags;
    char *srv_cookie;
};

struct server {
    char *cookie;
    size_t cklen;
};

struct stream {
    struct session *sess;
    struct http_txn *txn;
    struct proxy *be;
    void *target;
    uint32_t flags;
};

static inline int unlikely(int x) { return x; }

static inline struct ist ist(const char *str) {
    return (struct ist){.ptr = (char*)str, .len = strlen(str)};
}

static inline struct ist ist2(char *ptr, size_t len) {
    return (struct ist){.ptr = ptr, .len = len};
}

extern int http_find_header(struct htx *htx, struct ist name, struct http_hdr_ctx *ctx, int full);
extern char *http_find_cookie_value_end(char *val_beg, char *val_end);
extern char *http_find_hdr_value_end(char *val_beg, char *val_end);
extern int http_remove_header(struct htx *htx, struct http_hdr_ctx *ctx);
extern int http_del_hdr_value(char *hdr_beg, char *hdr_end, char **prev, char *next);
extern void http_replace_header_value(struct htx *htx, struct http_hdr_ctx *ctx, struct ist value);
extern void htx_change_blk_value_len(struct htx *htx, void *blk, size_t len);
extern struct htx *htxbuf(struct channel *res);
extern struct server *objt_server(void *target);
extern void *pool_alloc(void *pool_head_capture);
extern void ha_alert(const char *fmt, ...);

extern void *pool_head_capture;