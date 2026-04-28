#include <stdint.h>
#include <stddef.h>

struct worker;
struct http_conn {
    struct {
        char *b;
        char *e;
    } rxbuf;
};

struct http {
    struct {
        char *b;
        char *e;
    } hd[3];
};

#define HTTP_CONN_MAGIC
#define HTTP_MAGIC

#define CHECK_OBJ_NOTNULL(obj, magic)
#define Tcheck(buf)
#define Tlen(hd) ((hd).e - (hd).b)
#define WSLH(w, fd, hp, h)

static int vct_islws(char c) { return 0; }
static int vct_issp(char c) { return 0; }
static int vct_isctl(char c) { return 0; }
static int vct_iscrlf(char c) { return 0; }
static int vct_issep(char c) { return 0; }
static size_t vct_skipcrlf(char *p) { return 0; }

static uint16_t http_dissect_hdrs(struct worker *w, struct http *hp, int fd, char *p, const struct http_conn *htc) { return 0; }