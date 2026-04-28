#include <stdint.h>
#include <assert.h>
#include <stddef.h>

struct worker;

typedef struct {
    char *b;
    char *e;
} hdr;

typedef struct {
    char *e;
} txt;

struct http {
    unsigned nhd;
    unsigned shd;
    unsigned conds;
    hdr *hd;
    int *hdf;
};

struct http_conn {
    txt rxbuf;
    size_t maxhdr;
};

struct VSC_C_main {
    unsigned losthdr;
};

extern struct VSC_C_main *VSC_C_main;

enum {
    HTTP_HDR_FIRST,
    SLT_LostHeader
};

static inline int vct_iscrlf(char c) { return (c == '\r' || c == '\n'); }
static inline int vct_skipcrlf(const char *p) { return (p[0] == '\r' && p[1] == '\n') ? 2 : 1; }
static inline int vct_issp(char c) { return (c == ' ' || c == '\t'); }
static inline int vct_islws(char c) { return (c == ' ' || c == '\t' || c == '\r' || c == '\n'); }

void WSL(struct worker *w, int slt, int fd, const char *fmt, ...);
void WSLH(struct worker *w, int fd, struct http *hp, int hdr);