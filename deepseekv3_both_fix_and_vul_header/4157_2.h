#include <errno.h>
#include <stdio.h>

#define CAP_SYS_ADMIN 0
#define EPERM EACCES

struct inode;
struct file;

static inline int capable(int cap) { return 0; }
static inline void pr_warn_once(const char *fmt) { printf(fmt); }