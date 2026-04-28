#include <stdlib.h>
#include <stdint.h>

struct ly_ctx {
    // context structure placeholder
};

struct lys_module {
    struct ly_ctx *ctx;
};

struct lys_ext_instance_complex {
    // complex extension instance structure placeholder
};

struct lyext_substmt {
    int cardinality;
};

typedef enum {
    LY_STMT_PREFIX,
    LY_STMT_BELONGSTO,
    LY_STMT_ARGUMENT
} LY_STMT;

typedef enum {
    LY_STMT_CARD_SOME
} LY_STMT_CARD;

typedef enum {
    LYE_INCHILDSTMT,
    LYE_TOOMANY
} LYE;

typedef enum {
    LY_VLOG_NONE
} LY_VLOG;

const char *lydict_insert_zc(struct ly_ctx *ctx, char *value);
void lydict_remove(struct ly_ctx *ctx, const char *value);
void LOGVAL(struct ly_ctx *ctx, LYE code, LY_VLOG vlog, void *none, const char *arg_name, const char *parent_name);
void LOGMEM(struct ly_ctx *ctx);

#define LY_CHECK_ERR_GOTO(cond, action, label) if (cond) { action; goto label; }

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

const char **lys_ext_complex_get_substmt(LY_STMT stmt, struct lys_ext_instance_complex *ext, struct lyext_substmt **info);