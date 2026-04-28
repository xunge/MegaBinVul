#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

struct ly_ctx;

struct lys_type_bit {
    const char *name;
};

struct lyxp_expr {
    char *expr;
    unsigned int *expr_pos;
    unsigned int *tok_len;
    int *tokens;
    unsigned int used;
};

#define LY_EINVAL 1
#define LY_TYPE_BITS 1
#define LY_TYPE_IDENT 2
#define LY_TYPE_INST 3
#define LY_TYPE_DEC64 4
#define LY_TYPE_INT8 5
#define LY_TYPE_INT16 6
#define LY_TYPE_INT32 7
#define LY_TYPE_INT64 8
#define LY_TYPE_UINT8 9
#define LY_TYPE_UINT16 10
#define LY_TYPE_UINT32 11
#define LY_TYPE_UINT64 12

#define LYXP_TOKEN_NAMETEST 1

#define LOGERR(ctx, err, fmt, ...)
#define LOGINT(ctx)

#define LY_CHECK_ERR_RETURN(cond, action, ret) if (cond) { action; return ret; }

static inline char *strnchr(const char *s, int c, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (s[i] == c) {
            return (char *)s + i;
        }
    }
    return NULL;
}

static struct lyxp_expr *lyxp_parse_expr(struct ly_ctx *ctx, const char *value) {
    return NULL;
}

static void lyxp_expr_free(struct lyxp_expr *exp) {
}

static void lydict_remove(struct ly_ctx *ctx, const char *value) {
}

static const char *lydict_insert(struct ly_ctx *ctx, const char *value, int zero) {
    return value;
}