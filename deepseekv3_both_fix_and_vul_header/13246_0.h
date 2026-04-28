#include <stdint.h>
#include <stddef.h>

typedef int LY_ERR;
typedef int ly_bool;

enum yang_arg {
    Y_IDENTIF_ARG,
    Y_PREF_IDENTIF_ARG,
    Y_STR_ARG,
    Y_MAYBE_STR_ARG
};

struct lysp_ctx;

#define LY_CHECK_ERR_RET(expr, err, retval)
#define LY_CHECK_RET(expr)
#define LOGVAL_PARSER(ctx, code, ch)
#define LY_EVALID 0
#define LY_VCODE_INCHAR 0
#define LY_SUCCESS 0

int ly_getutf8(const char **str, uint32_t *c, size_t *len);
LY_ERR lysp_check_identifierchar(struct lysp_ctx *ctx, uint32_t c, ly_bool first, uint8_t *prefix);
LY_ERR lysp_check_stringchar(struct lysp_ctx *ctx, uint32_t c);