#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

struct ly_ctx;

struct lys_type_bit {
    char *name;
};

struct lyxp_expr {
    char *expr;
    unsigned int *expr_pos;
    unsigned int *tok_len;
    unsigned int used;
    int *tokens;
};

#define LY_TYPE_BITS 0
#define LY_TYPE_IDENT 1
#define LY_TYPE_INST 2
#define LY_TYPE_DEC64 3
#define LY_TYPE_INT8 4
#define LY_TYPE_INT16 5
#define LY_TYPE_INT32 6
#define LY_TYPE_INT64 7
#define LY_TYPE_UINT8 8
#define LY_TYPE_UINT16 9
#define LY_TYPE_UINT32 10
#define LY_TYPE_UINT64 11

#define LY_EINVAL 0
#define LOGERR(ctx, err, fmt, ...)
#define LOGINT(ctx)
#define LY_CHECK_ERR_RETURN(cond, action, ret) if (cond) { action; return ret; }

#define LYXP_TOKEN_NAMETEST 0

static struct lyxp_expr *lyxp_parse_expr(struct ly_ctx *ctx, const char *value);
static void lyxp_expr_free(struct lyxp_expr *exp);
static void lydict_remove(struct ly_ctx *ctx, const char *value);
static const char *lydict_insert(struct ly_ctx *ctx, const char *value, int len);

static const char *strnchr(const char *s, int c, size_t n);