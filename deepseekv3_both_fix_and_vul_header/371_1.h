#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

typedef struct cachemgr_request {
    char *pub_auth;
    const char *passwd;
    const char *hostname;
    const char *user_name;
} cachemgr_request;

struct base64_encode_ctx {
    int dummy;
};

extern time_t now;
extern void safe_free(void *);
extern char *safe_str(const char *);
extern char *rfc1738_escape(const char *);
extern void debug(const char *, ...);
extern void *xmalloc(size_t);
extern int base64_encode_len(int);
extern void base64_encode_init(struct base64_encode_ctx *);
extern size_t base64_encode_update(struct base64_encode_ctx *, char *, int, uint8_t *);
extern size_t base64_encode_final(struct base64_encode_ctx *, char *);