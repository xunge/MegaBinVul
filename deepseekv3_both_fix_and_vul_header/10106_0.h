#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <net/if.h>
#include <pwd.h>
#include <grp.h>

#define RUN_FIREJAIL_NETWORK_DIR "/run/firejail/network"
#define LIBDIR "/usr/lib"

extern char **environ;

struct config {
    char *shell;
} cfg;

void errExit(const char *str);
void EUID_ASSERT(void);
void EUID_ROOT(void);
void EUID_USER(void);
char *pid_proc_comm(pid_t pid);
int find_child(pid_t pid, pid_t *child);
int join_namespace(pid_t pid, const char *ns);
void bandwidth_set(pid_t pid, const char *dev, int down, int up);
void bandwidth_remove(pid_t pid, const char *dev);
char *guess_shell(void);