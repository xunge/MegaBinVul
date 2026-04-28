#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define EUID_ASSERT() 
#define EUID_ROOT() 
#define EUID_USER() 
#define errExit(msg) { perror(msg); exit(EXIT_FAILURE); }

extern char *pid_proc_comm(pid_t pid);
extern uid_t pid_get_uid(pid_t pid);
extern int find_child(pid_t pid, pid_t *child);
extern void delete_run_files(pid_t pid);