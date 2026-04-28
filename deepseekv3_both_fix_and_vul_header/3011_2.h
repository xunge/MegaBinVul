#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int zend_bool;

typedef struct _zend_file_handle {
    char *filename;
} zend_file_handle;

typedef struct _zend_op_array {
    int dummy;
} zend_op_array;

typedef struct _zend_lex_state {
    int dummy;
} zend_lex_state;

typedef struct _zval_value {
    long lval;
} zval_value;

typedef struct _znode {
    int op_type;
    union {
        struct {
            int type;
            zval_value value;
        } constant;
    } u;
} znode;

typedef struct _zval_struct {
    int dummy;
} zval;

#define TSRMLS_DC
#define TSRMLS_CC
#define TSRMLS_C
#define CG(v) (compiler_globals.v)
#define FAILURE (-1)
#define ZEND_REQUIRE 1
#define ZEND_USER_FUNCTION 1
#define INITIAL_OP_ARRAY_SIZE 64
#define IS_CONST 1
#define IS_LONG 1
#define Z_UNSET_ISREF(z)
#define Z_SET_REFCOUNT(z, rc)
#define ZMSG_FAILED_REQUIRE_FOPEN 1
#define ZMSG_FAILED_INCLUDE_FOPEN 2

struct _zend_compiler_globals {
    zend_op_array *active_op_array;
    int in_compilation;
    void *context;
    void *context_stack;
};

extern struct _zend_compiler_globals compiler_globals;

void *emalloc(size_t size);
void efree(void *ptr);
int zendparse(void);
void zend_bailout(void);
void zend_message_dispatcher(int type, const char *filename);
int open_file_for_scanning(zend_file_handle *file_handle);
void init_op_array(zend_op_array *op_array, int type, int size);
void zend_do_return(znode *node, int unused);
void pass_two(zend_op_array *op_array);
void zend_release_labels(int unused);
void zend_save_lexical_state(zend_lex_state *state);
void zend_restore_lexical_state(zend_lex_state *state);
void zend_stack_push(void *stack, void *element, size_t size);
void zend_init_compiler_context(void);