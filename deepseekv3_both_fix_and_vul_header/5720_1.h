#include <signal.h>
#include <stddef.h>

typedef struct _zval_struct zval;

struct php_pcntl_pending_signal {
    int signo;
    struct php_pcntl_pending_signal *next;
};

typedef struct {
    struct php_pcntl_pending_signal *head;
    struct php_pcntl_pending_signal *spares;
    int pending_signals;
    int processing_signal_queue;
    void *php_signal_table;
} pcntl_globals_struct;

extern pcntl_globals_struct pcntl_globals;

#define TSRMLS_FETCH()
#define TSRMLS_CC
#define PCNTL_G(v) (pcntl_globals.v)
#define SUCCESS 0
#define MAKE_STD_ZVAL(z)
#define ZVAL_NULL(z)
#define ZVAL_LONG(z, l)
#define EG(v) (executor_globals.v)
#define call_user_function(a,b,c,d,e,f)
#define zval_ptr_dtor(z)
#define zend_hash_index_find(a,b,c) (0)

typedef struct _zend_executor_globals {
    void *function_table;
} zend_executor_globals;

extern zend_executor_globals executor_globals;