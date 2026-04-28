#include <stddef.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define UNAME26 0x0020000
#define LINUX_VERSION_CODE 0
#define UTS_RELEASE ""

struct task_struct {
    int personality;
};
extern struct task_struct *current;

#define __user
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max_t(type, a, b) ((type)(a) > (type)(b) ? (type)(a) : (type)(b))

static inline int scnprintf(char *buf, size_t size, const char *fmt, ...) { return 0; }
static inline int copy_to_user(void *dst, const void *src, size_t size) { return 0; }