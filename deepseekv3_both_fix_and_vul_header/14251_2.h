#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <setjmp.h>
#include <sys/socket.h>
#include <sys/prctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sched.h>
#include <sys/mount.h>
#include <grp.h>
#include <sys/syscall.h>

#ifndef CLONE_NEWUSER
#define CLONE_NEWUSER 0x10000000
#endif

#ifndef CLONE_NEWCGROUP
#define CLONE_NEWCGROUP 0x02000000
#endif

enum sync_t {
    SYNC_USERMAP_PLS = 0x40,
    SYNC_USERMAP_ACK = 0x41,
    SYNC_RECVPID_PLS = 0x42,
    SYNC_RECVPID_ACK = 0x43,
    SYNC_GRANDCHILD = 0x44,
    SYNC_CHILD_FINISH = 0x45,
    SYNC_MOUNTSOURCES_PLS = 0x46,
    SYNC_MOUNTSOURCES_ACK = 0x47,
};

enum {
    STAGE_PARENT = 0,
    STAGE_CHILD,
    STAGE_INIT
};

enum {
    DEBUG = 0,
    SETGROUPS_DENY = 1
};

struct nlconfig_t {
    char *data;
    size_t data_len;
    int *namespaces;
    int cloneflags;
    char *uidmappath;
    char *gidmappath;
    char *uidmap;
    size_t uidmap_len;
    char *gidmap;
    size_t gidmap_len;
    char *oom_score_adj;
    size_t oom_score_adj_len;
    bool is_rootless_euid;
    bool is_setgroup;
    char *mountsources;
    size_t mountsources_len;
};

int syncfd;
int current_stage;

void setup_logpipe(void);
int getenv_int(const char *name);
int ensure_cloned_binary(void);
void bail(const char *fmt, ...);
void write_log(int level, const char *fmt, ...);
void nl_parse(int pipenum, struct nlconfig_t *config);
void update_oom_score_adj(char *adj, size_t len);
void update_setgroups(pid_t pid, int deny);
void update_uidmap(const char *path, pid_t pid, char *map, size_t len);
void update_gidmap(const char *path, pid_t pid, char *map, size_t len);
pid_t clone_parent(jmp_buf *env, int stage);
void sane_kill(pid_t pid, int sig);
void send_mountsources(int syncfd, pid_t pid, char *sources, size_t len);
void receive_mountsources(int syncfd);
void nl_free(struct nlconfig_t *config);
void join_namespaces(int *namespaces);