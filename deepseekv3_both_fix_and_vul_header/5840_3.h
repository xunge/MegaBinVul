#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <sched.h>

#define ERROR(fmt, ...) fprintf(stderr, "ERROR: " fmt "\n", ##__VA_ARGS__)
#define WARN(fmt, ...) fprintf(stderr, "WARNING: " fmt "\n", ##__VA_ARGS__)
#define SYSERROR(fmt, ...) perror(fmt)

#define LXC_ATTACH_MOVE_TO_CGROUP (1 << 0)
#define CLONE_PARENT 0x00008000

typedef int (*lxc_attach_exec_t)(void*);

struct lxc_proc_context_info {
    signed long personality;
};

typedef struct lxc_attach_options {
    int namespaces;
    int attach_flags;
    int stdin_fd;
    char* initial_cwd;
} lxc_attach_options_t;

struct attach_clone_payload {
    int ipc_socket;
    lxc_attach_options_t* options;
    struct lxc_proc_context_info* init_ctx;
    lxc_attach_exec_t exec_function;
    void* exec_payload;
    int procfd;
};

static lxc_attach_options_t attach_static_default_options;

static inline int lxc_write_nointr(int fd, const void* buf, size_t count) {
    return write(fd, buf, count);
}

static inline int lxc_read_nointr_expect(int fd, void* buf, size_t count, const void* expected) {
    return read(fd, buf, count);
}

static inline int wait_for_pid(pid_t pid) {
    int status;
    waitpid(pid, &status, 0);
    return WIFEXITED(status) ? WEXITSTATUS(status) : -1;
}

static inline void rexit(int status) {
    _exit(status);
}

static pid_t lxc_cmd_get_init_pid(const char* name, const char* lxcpath) { return -1; }
static struct lxc_proc_context_info* lxc_proc_get_context_info(pid_t pid) { return NULL; }
static signed long get_personality(const char* name, const char* lxcpath) { return -1; }
static void lxc_proc_put_context_info(struct lxc_proc_context_info* ctx) {}
static int fetch_seccomp(const char* name, const char* lxcpath, struct lxc_proc_context_info* ctx, lxc_attach_options_t* options) { return 0; }
static int lxc_cmd_get_clone_flags(const char* name, const char* lxcpath) { return -1; }
static int cgroup_attach(const char* name, const char* lxcpath, pid_t pid) { return 0; }
static int lxc_attach_to_ns(pid_t pid, int flags) { return -1; }
static pid_t lxc_clone(int (*fn)(void*), void* arg, int flags) { return -1; }
static int attach_child_main(void* arg) { return -1; }