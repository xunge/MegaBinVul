#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>

#define LOCK_DIR "/tmp/"
#define LOCK_PREFIX ".X"
#define LOCK_TMP_PREFIX ".Xl"
#define LOCK_SUFFIX "-lock"
#define PATH_MAX 4096
#define TRUE 1
#define FALSE 0

extern int nolock;
extern char LockFile[PATH_MAX];
extern char *display;
extern int StillLocking;

void FatalError(const char *format, ...);