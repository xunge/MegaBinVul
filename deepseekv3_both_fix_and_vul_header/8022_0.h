#include <stdio.h>
#include <string.h>
#include <limits.h>

struct pid_info_t {
    char path[PATH_MAX];
    int parent_length;
    char cmdline[256];
    int pid;
    char user[32];
};