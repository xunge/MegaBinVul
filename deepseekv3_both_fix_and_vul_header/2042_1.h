#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>

#define PATH_MAX 4096
#define LOCK_DIR "/tmp/"
#define LOCK_PREFIX ".X"
#define LOCK_TMP_PREFIX ".X"
#define LOCK_SUFFIX "-lock"
#define LOCK_FILE_SIZE 256
#define TRUE 1
#define FALSE 0

extern int nolock;
extern char LockFile[LOCK_FILE_SIZE];
extern char *display;
extern int StillLocking;

void FatalError(const char *format, ...);