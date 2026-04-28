#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

struct uv_process_options_s {
    unsigned int flags;
    const char* cwd;
    gid_t gid;
    uid_t uid;
    char** env;
    const char* file;
    char** args;
};

typedef struct uv_process_options_s uv_process_options_t;

extern char **environ;

#define UV_PROCESS_DETACHED (1 << 0)
#define UV_PROCESS_SETGID (1 << 1)
#define UV_PROCESS_SETUID (1 << 2)

static void uv__write_int(int fd, int val) {
    write(fd, &val, sizeof(val));
}

static void uv__cloexec(int fd, int set) {
    int flags = fcntl(fd, F_GETFD);
    if (flags == -1) return;
    fcntl(fd, F_SETFD, set ? (flags | FD_CLOEXEC) : (flags & ~FD_CLOEXEC));
}

static void uv__nonblock(int fd, int set) {
    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) return;
    fcntl(fd, F_SETFL, set ? (flags | O_NONBLOCK) : (flags & ~O_NONBLOCK));
}

static void uv__close(int fd) {
    close(fd);
}