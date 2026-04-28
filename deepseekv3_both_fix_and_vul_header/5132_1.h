#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/prctl.h>
#include <sched.h>
#include <setjmp.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <grp.h>

#define CLONE_NEWNS   0x00020000
#define CLONE_NEWCGROUP 0x02000000
#define CLONE_NEWUTS   0x04000000
#define CLONE_NEWIPC   0x08000000
#define CLONE_NEWUSER  0x10000000
#define CLONE_NEWPID   0x20000000
#define CLONE_NEWNET   0x40000000

enum sync_t {
    SYNC_ERR,
    SYNC_USERMAP_PLS,
    SYNC_USERMAP_ACK,
    SYNC_RECVPID_PLS,
    SYNC_RECVPID_ACK,
    SYNC_CHILD_READY,
    SYNC_GRANDCHILD
};

enum {
    JUMP_PARENT = 0,
    JUMP_CHILD,
    JUMP_INIT
};

#define SETGROUPS_DENY -1
#define CREATECGROUPNS 1

struct nlconfig_t {
    char *uidmappath;
    char *gidmappath;
    int uidmap_len;
    int gidmap_len;
    int namespaces;
    int cloneflags;
    char *oom_score_adj;
    int oom_score_adj_len;
    bool is_rootless_euid;
    bool is_setgroup;
    uint32_t *uidmap;
    uint32_t *gidmap;
};

extern int initpipe(void);
extern void nl_parse(int pipenum, struct nlconfig_t *config);
extern void update_oom_score_adj(char *data, int len);
extern void update_setgroups(pid_t pid, int setgroups);
extern void update_uidmap(char *path, pid_t pid, uint32_t *map, int len);
extern void update_gidmap(char *path, pid_t pid, uint32_t *map, int len);
extern pid_t clone_parent(jmp_buf *env, int jmpval);
extern void join_namespaces(int namespaces);
extern void nl_free(struct nlconfig_t *config);
extern void bail(const char *fmt, ...);

static int syncfd;