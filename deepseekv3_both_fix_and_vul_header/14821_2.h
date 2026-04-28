#include <stdio.h>
#include <errno.h>

#define XENLOG_DEBUG 0
#define ENOSYS 38

typedef void *XEN_GUEST_HANDLE_PARAM;
#define XEN_GUEST_HANDLE_PARAM(type) XEN_GUEST_HANDLE_PARAM

int gdprintk(int level, const char *fmt, ...);