#include <stdint.h>
#include <stddef.h>

typedef struct _zend_ast {
    struct _zend_ast *child[2];
    int kind;
} zend_ast;

typedef struct _zend_ast_list {
    uint32_t children;
    zend_ast *child[1];
} zend_ast_list;

typedef struct _zend_string {
    char *val;
} zend_string;

typedef struct _zval_struct {
    int type;
    long lval;
} zval;

typedef struct {
    int ticks;
} zend_declarables;

typedef struct _zend_op_array {
    unsigned int fn_flags;
} zend_op_array;

#define ZEND_AST_ZVAL 0
#define ZEND_ACC_STRICT_TYPES (1<<0)
#define IS_LONG 1

#define E_COMPILE_ERROR 1
#define E_COMPILE_WARNING 2
#define FAILURE -1

zend_declarables declarables;

#define FC(x) x

extern zend_op_array *CG_active_op_array;
#define CG(x) CG_##x

zend_ast_list *zend_ast_get_list(zend_ast *ast);
zend_string *zend_ast_get_str(zend_ast *ast);
int zend_string_equals_literal_ci(zend_string *s1, const char *s2);
void zend_const_expr_to_zval(zval *zv, zend_ast *ast);
long zval_get_long(zval *zv);
void zval_dtor(zval *zv);
int zend_declare_is_first_statement(zend_ast *ast);
void zend_compile_stmt(zend_ast *ast);
void zend_error_noreturn(int type, const char *format, ...);
void zend_error(int type, const char *format, ...);

#define ZSTR_VAL(s) ((s)->val)
#define Z_TYPE(z) ((z).type)
#define Z_LVAL(z) ((z).lval)