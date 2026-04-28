#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <cstdio>
#include <memory>
#include <set>

#define ALOGE(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)

static bool ptrace_attach_thread(pid_t pid, pid_t tid) {
    return ptrace(PTRACE_ATTACH, tid, 0, 0) == 0;
}