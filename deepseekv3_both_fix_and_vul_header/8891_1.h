#include <stdlib.h>
#include <string.h>

typedef struct _php_http_url_t php_http_url_t;
#define TSRMLS_DC
#define TSRMLS_CC
#define TSRMLS_SET_CTX(ctx)

struct parse_state {
    const char *end;
    const char *ptr;
    unsigned flags;
    size_t maxlen;
    void *ts;
};

#define E_WARNING 2

void *ecalloc(size_t nmemb, size_t size);
void efree(void *ptr);
int parse_scheme(struct parse_state *state);
int parse_hier(struct parse_state *state);
int parse_query(struct parse_state *state);
int parse_fragment(struct parse_state *state);
void php_error_docref(const char *docref, int type, const char *format, ...);