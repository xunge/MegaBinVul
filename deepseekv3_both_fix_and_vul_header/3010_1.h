#include <stdlib.h>
#include <string.h>

typedef struct _zend_op_array {
    int dummy_op_array_fields;
} zend_op_array;

typedef struct _zval_struct {
    struct {
        struct {
            size_t len;
        } str;
    } value;
} zval;

typedef int zend_bool;

typedef struct _zend_lex_state {
    int dummy_lex_state_fields;
} zend_lex_state;

typedef struct _zend_stack {
    void *top;
} zend_stack;

struct _compiler_globals {
    zend_op_array *active_op_array;
    zend_bool in_compilation;
    zend_bool interactive;
    zend_bool unclean_shutdown;
    void *context;
    zend_stack context_stack;
};

struct _scanner_globals {
    char *script_filtered;
};

#define TSRMLS_DC
#define TSRMLS_CC
#define TSRMLS_C
#define FAILURE -1
#define SUCCESS 0
#define ZEND_EVAL_CODE 1
#define INITIAL_OP_ARRAY_SIZE 64
#define ST_IN_SCRIPTING 0

extern struct _compiler_globals compiler_globals;
extern struct _scanner_globals scanner_globals;

#define CG(v) (compiler_globals.v)
#define SCNG(v) (scanner_globals.v)

void *emalloc(size_t size);
void efree(void *ptr);
void zval_copy_ctor(zval *zvalue);
void convert_to_string(zval *zvalue);
void zend_save_lexical_state(zend_lex_state *lex_state TSRMLS_DC);
int zend_prepare_string_for_scanning(zval *source_string, char *filename TSRMLS_DC);
void init_op_array(zend_op_array *op_array, int type, int size TSRMLS_DC);
void zend_stack_push(zend_stack *stack, void *element, size_t size);
void zend_init_compiler_context(TSRMLS_D);
void BEGIN(int state);
int zendparse(TSRMLS_D);
void destroy_op_array(zend_op_array *op_array TSRMLS_DC);
void zend_do_return(zval *retval_ptr, int retval_used TSRMLS_DC);
void pass_two(zend_op_array *op_array TSRMLS_DC);
void zend_release_labels(int unused TSRMLS_DC);
void zend_restore_lexical_state(zend_lex_state *lex_state TSRMLS_DC);
void zval_dtor(zval *zvalue);