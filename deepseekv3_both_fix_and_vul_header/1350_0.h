#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

#define RPMLOG_DEBUG 0
#define RPMERR_MKDIR_FAILED -1

extern int _fsm_debug;
void rpmlog(int level, const char *format, ...);