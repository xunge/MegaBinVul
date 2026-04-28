#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <stdio.h>

struct argv_array {
    const char **argv;
    int argc;
    int alloc;
};

struct child_process {
    const char **argv;
    struct argv_array args;
    const char **env;
    struct argv_array env_array;
    int in;
    int out;
    int err;
    pid_t pid;
    int no_stdin;
    int no_stdout;
    int no_stderr;
    int stdout_to_stderr;
    int silent_exec_failure;
    int clean_on_exit;
    int use_shell;
    int git_cmd;
    const char *dir;
};

struct child_err {
    int err;
    int syserr;
};

struct atfork_state {
    sigset_t old;
};

#define ARGV_ARRAY_INIT { NULL, 0, 0 }
#define CHILD_ERR_CHDIR 1
#define CHILD_ERR_SIGPROCMASK 2
#define CHILD_ERR_SILENT 3
#define CHILD_ERR_ENOENT 4
#define CHILD_ERR_ERRNO 5
#define GIT_WINDOWS_NATIVE 0

extern void child_process_clear(struct child_process *);
extern void close_pair(int[]);
extern void error(const char *, ...);
extern void error_errno(const char *, ...);
extern void set_die_routine(void (*)(const char *, va_list));
extern void set_error_routine(void (*)(const char *, va_list));
extern void set_warn_routine(void (*)(const char *, va_list));
extern void child_die(int);
extern void child_dup2(int, int);
extern void child_close(int);
extern void child_close_pair(int[]);
extern void prepare_cmd(struct argv_array *, struct child_process *);
extern char **prep_childenv(const char **);
extern void atfork_prepare(struct atfork_state *);
extern void atfork_parent(struct atfork_state *);
extern void mark_child_for_cleanup(pid_t, struct child_process *);
extern void wait_or_whine(pid_t, const char *, int);
extern void child_err_spew(struct child_process *, struct child_err *);
extern const char **prepare_git_cmd(struct argv_array *, const char **);
extern const char **prepare_shell_cmd(struct argv_array *, const char **);
extern pid_t mingw_spawnvpe(const char *, const char **, char **, const char *, int, int, int);
extern void trace_argv_printf(const char **, const char *, ...);
extern void set_cloexec(int);
extern int xread(int, void *, size_t);
extern void argv_array_clear(struct argv_array *);
extern int child_notifier;