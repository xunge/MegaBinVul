#include <signal.h>
#include <stddef.h>

struct php_pcntl_pending_signal {
    int signo;
    struct php_pcntl_pending_signal *next;
};

#define TSRMLS_FETCH()
#define PCNTL_G(name) (pcntl_globals.name)

struct {
    struct php_pcntl_pending_signal *spares;
    struct php_pcntl_pending_signal *head;
    struct php_pcntl_pending_signal *tail;
    int pending_signals;
} pcntl_globals;