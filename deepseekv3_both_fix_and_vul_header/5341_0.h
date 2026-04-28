#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mount.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_BUF 1024
#define sc_must_snprintf snprintf
#define sc_strdup strdup

static void die(const char *msg);
static void sc_do_mount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags, const void *data);