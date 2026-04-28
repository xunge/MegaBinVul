#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define HTTP_IS_SPHT(c) ((c) == ' ' || (c) == '\t')
#define TX_SCK_PRESENT  0x00000001
#define TX_SCK_FOUND    0x00000002
#define TX_SCK_DELETED  0x00000004
#define TX_SCK_REPLACED 0x00000008
#define TX_SCK_MASK     0x0000000F
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

struct buffer {
    char *buf;
};

struct channel {
    struct buffer buf;
};

struct stream {
    struct session *sess;
    struct http_txn *txn;
    uint32_t flags;
    void *target;
    struct {
        char *cookie_name;
        int cookie_len;
        uint32_t ck_opts;
    } *be;
};

struct session {
    struct {
        char *capture_name;
        int capture_namelen;
        int capture_len;
    } *fe;
};

struct http_txn {
    uint32_t flags;
    char *srv_cookie;
};

struct htx {
    // minimal definition
};

struct http_hdr_ctx {
    void *blk;
    struct ist value;
    int lws_before;
    int lws_after;
};

struct server {
    char *cookie;
    int cklen;
};

struct pool_head;
extern struct pool_head *pool_head_capture;

static inline void *pool_alloc(struct pool_head *pool) { return NULL; }
static inline void ha_alert(const char *fmt, ...) {}
static inline struct server *objt_server(void *target) { return NULL; }
static inline int http_find_header(struct htx *htx, struct ist name, struct http_hdr_ctx *ctx, int full) { return 0; }
static inline char *http_find_cookie_value_end(char *val_beg, char *hdr_end) { return NULL; }
static inline char *http_find_hdr_value_end(char *val_beg, char *hdr_end) { return NULL; }
static inline void htx_change_blk_value_len(struct htx *htx, void *blk, int len) {}
static inline void http_remove_header(struct htx *htx, struct http_hdr_ctx *ctx) {}
static inline int http_del_hdr_value(char *hdr_beg, char *hdr_end, char **prev, char *next) { return 0; }
static inline void http_replace_header_value(struct htx *htx, struct http_hdr_ctx *ctx, struct ist value) {}
static inline struct htx *htxbuf(struct buffer *buf) { return NULL; }
static inline struct ist ist(const char *str) { return (struct ist){.ptr = (char *)str, .len = strlen(str)}; }
static inline struct ist ist2(char *ptr, size_t len) { return (struct ist){.ptr = ptr, .len = len}; }
#define unlikely(x) (x)