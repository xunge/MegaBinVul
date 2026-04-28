#include <signal.h>
#include <stdio.h>
#include <string.h>

static struct sigaction fio_old_sig_int;
static struct sigaction fio_old_sig_term;
static struct sigaction fio_old_sig_usr1;
static struct sigaction fio_old_sig_pipe;
static int fio_signal_set_flag;

void sig_int_handler(int signum);