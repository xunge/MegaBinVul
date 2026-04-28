#include <sys/types.h>
#include <signal.h>
#include <errno.h>

extern long do_send_specific(pid_t tgid, pid_t pid, int sig, siginfo_t *info);