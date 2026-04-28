#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdint.h>
#include <time.h>

struct base64_decode_ctx {
    int dummy;  // Placeholder for incomplete type
};

#define BASE64_DECODE_LENGTH(len) ((len) * 3 / 4)

extern time_t now;
extern int passwd_ttl;

void *xmalloc(size_t size);
void xfree(void *ptr);
char *xstrdup(const char *str);
void safe_free(void *ptr);
char *safe_str(const char *str);
void rfc1738_unescape(char *url);
void debug(const char *format, ...);
void base64_decode_init(struct base64_decode_ctx *ctx);
int base64_decode_update(struct base64_decode_ctx *ctx, size_t *dstlen, uint8_t *dst, size_t srclen, const char *src);
int base64_decode_final(struct base64_decode_ctx *ctx);

typedef struct {
    char *pub_auth;
    char *hostname;
    char *user_name;
    char *passwd;
} cachemgr_request;