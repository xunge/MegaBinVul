#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

typedef struct {
    char *clientaddr;
    int sd;
    char cwd[PATH_MAX];
} ctrl_t;

extern char *compose_abspath(ctrl_t *ctrl, char *path);
extern int chrooted;
extern char *home;
extern void INFO(const char *fmt, ...);
extern void DBG(const char *fmt, ...);
extern void send_msg(int sd, const char *msg);