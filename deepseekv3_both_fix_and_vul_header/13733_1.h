#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>

struct user_info {
    uid_t uid;
    uid_t euid;
    gid_t gid;
    gid_t egid;
};

extern struct user_info current_user;
extern void sys_error(const char *, ...);
extern const char * _(const char *);