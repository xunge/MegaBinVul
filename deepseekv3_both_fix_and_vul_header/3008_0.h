#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef int pid_t;

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#ifndef _WIN32
extern int ga_open_pidfile(const char *pidfile);
extern void reopen_fd_to_null(int fd);
extern void g_critical(const char *msg);
#endif