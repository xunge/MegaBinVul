#include <signal.h>
#include <string.h>

static volatile sig_atomic_t fio_signal_set_flag = 0;
static struct sigaction fio_old_sig_int;
static struct sigaction fio_old_sig_term;
static struct sigaction fio_old_sig_pipe;
static struct sigaction fio_old_sig_chld;
static struct sigaction fio_old_sig_usr1;