#include <signal.h>
#include <stddef.h>

typedef struct _zval_struct {
    int type;
    long value;
} zval;

struct php_pcntl_pending_signal {
    int signo;
    struct php_pcntl_pending_signal *next;
};

typedef struct {
    struct php_pcntl_pending_signal *head;
    struct php_pcntl_pending_signal *spares;
    int processing_signal_queue;
    void *php_signal_table;
} pcntl_globals_t;

extern pcntl_globals_t pcntl_globals;

#define TSRMLS_FETCH()
#define TSRMLS_CC
#define TSRMLS_DC
#define PCNTL_G(name) (pcntl_globals.name)
#define SUCCESS 0
#define MAKE_STD_ZVAL(z) ((z) = malloc(sizeof(zval)))
#define ZVAL_NULL(z) ((z)->type = 0)
#define ZVAL_LONG(z, l) do { (z)->type = 1; (z)->value = (l); } while (0)

struct _zend_executor_globals {
    void *function_table;
};
extern struct _zend_executor_globals executor_globals;
#define EG(function_table) (executor_globals.function_table)

int zend_hash_index_find(void *ht, long h, void **pData);
int call_user_function(void *function_table, zval *object, zval *function_name, zval *retval_ptr, int param_count, zval *params);
void zval_ptr_dtor(zval **zval_ptr);