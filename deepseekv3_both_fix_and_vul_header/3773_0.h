#include <string.h>
#include <stdio.h>

typedef int ret_t;
typedef unsigned int cuint_t;

#define CHR_SP ' '
#define CHR_CR '\r'
#define CHR_LF '\n'
#define unlikely(x) (x)

#define ret_ok 0
#define ret_error -1

typedef struct {
    char *buf;
    cuint_t len;
} cherokee_buffer_t;

typedef struct {
    cherokee_buffer_t nc;
    cherokee_buffer_t uri;
    cherokee_buffer_t qop;
    cherokee_buffer_t realm;
    cherokee_buffer_t nonce;
    cherokee_buffer_t cnonce;
    cherokee_buffer_t user;
    cherokee_buffer_t response;
    cherokee_buffer_t algorithm;
} cherokee_validator_t;

#define CHEROKEE_BUF_INIT { NULL, 0 }

static inline int equal_str(const char *a, const char *b) {
    return strcmp(a, b) == 0;
}

void cherokee_buffer_add(cherokee_buffer_t *buf, const char *str, cuint_t len);
void cherokee_buffer_mrproper(cherokee_buffer_t *buf);