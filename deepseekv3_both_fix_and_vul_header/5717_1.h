#include <signal.h>
#include <stddef.h>

struct php_pcntl_pending_signal {
    int signo;
    struct php_pcntl_pending_signal *next;
};

#define TSRMLS_FETCH()
#define PCNTL_G(v) (pcntl_globals.v)

struct {
    struct php_pcntl_pending_signal *spares;
    struct php_pcntl_pending_signal *head;
    struct php_pcntl_pending_signal *tail;
} pcntl_globals;