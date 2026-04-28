#include <signal.h>
#include <stddef.h>

static struct sigaction fio_old_sig_usr1;
static struct sigaction fio_old_sig_int;
static struct sigaction fio_old_sig_term;
static struct sigaction fio_old_sig_pipe;
static int fio_signal_children_flag;

extern void fio_stop(void);