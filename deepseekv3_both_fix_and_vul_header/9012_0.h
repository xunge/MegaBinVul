#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

struct ucred {
    pid_t pid;
    uid_t uid;
    gid_t gid;
};

static FILE *open_pids_file(const char *contrl, const char *cg);
static void pid_from_ns_wrapper(int sock, pid_t tpid);
static bool recv_creds(int sock, struct ucred *cred, char *v);
static void wait_for_pid(pid_t pid);